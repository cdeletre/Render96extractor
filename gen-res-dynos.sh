#/usr/bin/env sh

OPTSTRING=":hm:lp:"

MODE=0
ARCH="amd64"
HDTEXTURES=0
MODELS=0
AUDIO=0
LOWMEM=0

EXTRACTED=0

ROOT_DIR="${PWD}"
PACKS_DIR="packs"
BUILD_DIR="/build/us_pc"
MKZIP="./tools/mkzip.py"
PACKAGE_LST="render96-package.lst"
PACKAGE_ZIP="render96-package.zip"
PACKAGE_LOG="render96-package.log"

function print_help {
  echo 'Generates the ressources needed to run render96 (sm64ex fork)'
  echo 'and add optionnal packs (textures, 3d models, audio).'
  echo ''
  echo "usage: $0 [-h] [-m MODE] [-p PACK] [-l]"
  echo '-m: running mode'
  echo '    MODE:'
  echo '      docker-amd64 : use docker with amd64 image (default, more safe but needs docker)'
  echo '      docker-arm64 : use docker with arm64 image (needs docker)'
  echo '      nodocker : run without docker (you need to manually install bsdmainutils build-essential and python3)'
  echo '-p: install a pack'
  echo '  PACK:'
  echo '    hdtextures : RENDER96-HD-TEXTURE-PACK'
  echo '    models : Render96 DynOs 3D model pack'
  echo '    audio : Render96 DynOs audio pack (music, jingle, sfx)'
  echo '-l: use low-mem pack (recommended for 1GB memory system)'
  echo '    textures are resized to 25%'
  echo '    audio is resampled to 22050Hz'
  echo ''
  echo "example: $0 -m hdtextures -m 3dmodels -m audio -l"
  echo '         This will generate ressources with 3 packs for low memory.'
  echo ''
  echo 'res'
  echo '|-- base.zip (required)'
  echo '|-- demos (required)'
  echo '|   `-- *.bin'
  echo '|-- gfx (optionnal)'
  echo '|   |-- actors'
  echo '|   |-- levels'
  echo '|   `-- textures'
  echo '`-- texts (required)'
  echo '    `-- *.json'
  echo ''
  echo 'dynos'
  echo '|-- audio (optionnal)'
  echo '`-- packs'
  echo '    `-- Render96AlphaModelPack (optionnal)'
}

while getopts ${OPTSTRING} opt; do
  case ${opt} in
    h)
      print_help
      exit 0
      ;;
    m)
      if [[ "${OPTARG}" == "docker-amd64" ]]
      then
        MODE=0
        ARCH="amd64"
      fi

      if [[ "${OPTARG}" == "docker-arm64" ]]
      then
        MODE=0
        ARCH="arm64"
      fi

      if [[ "${OPTARG}" == "nodocker" ]]
      then
        MODE=1
      fi

      ;;
    p)
      if [[ "${OPTARG}" == "hdtextures" ]]
      then
        HDTEXTURES=1
      fi

      if [[ "${OPTARG}" == "3dmodels" ]]
      then
        MODELS=1
      fi

      if [[ "${OPTARG}" == "audio" ]]
      then
        AUDIO=1
      fi
      ;;
    l)
      LOWMEM=1
      ;;
    :)
      echo "Option -${OPTARG} requires an argument."
      exit 1
      ;;
    ?)
      print_help
      exit 1
      ;;
  esac
done

if [ ${LOWMEM} -eq 1 ]
then
  PACKS_DIR="${PACKS_DIR}/lowmem"
fi

case ${MODE} in
  0)
    rm ${DOCKER_LOG}
    echo "(EXEC) docker ps"
    docker ps
    if [ ! $? -eq 0 ]
    then
      echo "Docker is not running or not installed."
      echo "and check your Docker installation"
      exit 1
    fi
    echo "Docker seems to be installed and running"
    echo "(EXEC) docker image ls | grep render96extractor | grep ${ARCH}"
    docker image ls | grep render96extractor | grep ${ARCH}
    if [ ! $? -eq 0 ]
    then
      echo "Docker image render96extractor:${ARCH} not found. Will build it."
      echo "It may take a while."
      echo "(EXEC) docker built . -t render96extractor:${ARCH}"
      docker build . -t render96extractor:${ARCH}

      if [ ! $? -eq 0 ]
      then
        echo "Image build failed."
        echo "check your docker installation"
        echo "or try to manually build the image using ./Dockefile"
        exit 1
      fi
    fi

    echo "(EXEC) docker run --rm -v ${PWD}:/render96 render96extractor:${ARCH} make res"
    docker run --rm -v ${PWD}:/render96 render96extractor:${ARCH} make res

    if [ ! $? -eq 0 ]
    then
      echo "Extraction of the assets from the rom has failed."
      echo "baserom.us.z64 must be present in ${PWD}"
      echo -n "sha1 of baserom.us.z64  is"
      cat sm64.us.sha1 | cut -d' ' -f1
      exit 1
    fi

    EXTRACTED=1

    ;;

  1)
    echo "(EXEC) make res"
    make res

    if [ ! $? -eq 0 ]
    then
      echo "Extraction of the assets from the rom has failed."
      echo "baserom.us.z64 must be present in ${PWD}"
      echo -n "sha1 of baserom.us.z64  is"
      cat sm64.us.sha1 | cut -d' ' -f1
      exit 1
    fi
    ;;
esac

if [ $EXTRACTED -eq 1 ]
then
  echo "Assets have been extracted, let pack them for easier installation."

  rm -f "${ROOT_DIR}/${PACKAGE_LST}"
  rm -f "${ROOT_DIR}/${PACKAGE_ZIP}"

  cd ${ROOT_DIR}/${BUILD_DIR}/res
  echo "${ROOT_DIR}/${BUILD_DIR}/res/base.zip res/base.zip" >> "${ROOT_DIR}/${PACKAGE_LST}"
  find demos -name \*.bin -exec echo "${ROOT_DIR}/${BUILD_DIR}/res/{} res/{}" >> "${ROOT_DIR}/${PACKAGE_LST}" \;
  find texts -name \*.json -exec echo "${ROOT_DIR}/${BUILD_DIR}/res/{} res/{}" >> "${ROOT_DIR}/${PACKAGE_LST}" \;
  cd ${ROOT_DIR}/${PACKS_DIR}
  find gfx -name \*.png -exec echo "${ROOT_DIR}/${PACKS_DIR}/{} res/{}" >> "${ROOT_DIR}/${PACKAGE_LST}" \;
  find audio -name \*.wav -exec echo "${ROOT_DIR}/${PACKS_DIR}/{} dynos/{}" >> "${ROOT_DIR}/${PACKAGE_LST}" \;
  find audio -name \*.txt -exec echo "${ROOT_DIR}/${PACKS_DIR}/{} dynos/{}" >> "${ROOT_DIR}/${PACKAGE_LST}" \;
  find Render96-Alpha-3.1-modelpack -name \*.bin -exec echo "${ROOT_DIR}/${PACKS_DIR}/{} dynos/packs/{}" >> "${ROOT_DIR}/${PACKAGE_LST}" \;

  cd ${ROOT_DIR}
  python3 ${MKZIP} "${ROOT_DIR}/${PACKAGE_LST}" "${ROOT_DIR}/${PACKAGE_ZIP}" > "${ROOT_DIR}/${PACKAGE_LOG}"

  if [ ! $? -eq 0 ]
      then
        echo "Packing failed. See ${PACKAGE_LOG}"
        exit 1
  fi

  echo "Everything has been packed. Unzip ${PACKAGE_ZIP}"
  echo "in your Render96 installation (you may overwrite existing files if asked)"
  
fi