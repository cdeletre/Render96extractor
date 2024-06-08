# Render96extractor
Extract and generate ressources package for Render96ex (sm64ex fork)

# Usage

First put your baserom.us.z64 in the root directory and check that the sha1 of this file is correct:

```
# sha1sum baserom.us.z64
9bef1128717f958171a4afac3ed78ee2bb4e86ce  baserom.us.z64
```

Then run `gen-res-dynos.sh` with the appropriate option. For example:

```
./gen-res-dynos.sh -m hdtextures -m 3dmodels -m audio -l
```

This will generate a package (`render96-package.zip`) that contains all the required assets (base, demos, texts) and also the optionnal hd texture pack, audio pack and model pack.

You will just have to unzip it in your render96 installation folder. This will populate `res` and `dynos` folders.

Run `gen-res-dynos.sh -h` for some help:

```
./gen-res-dynos.sh -h
Generates the ressources needed to run render96 (sm64ex fork)
and add optionnal packs (textures, 3d models, audio).

usage: ./gen-res-dynos.sh [-h] [-m MODE] [-p PACK] [-l]
-m: running mode
    MODE:
      docker-amd64 : use docker with amd64 image (default, more safe but needs docker)
      docker-arm64 : use docker with arm64 image (needs docker)
      nodocker : run without docker (you need to manually install bsdmainutils build-essential and python3)
-p: install a pack
  PACK:
    hdtextures : RENDER96-HD-TEXTURE-PACK
    models : Render96 DynOs 3D model pack
    audio : Render96 DynOs audio pack (music, jingle, sfx)
-l: use low-mem pack (recommended for 1GB memory system)
    textures are resized to 25%
    audio is resampled to 22050Hz

example: ./gen-res-dynos.sh -m hdtextures -m 3dmodels -m audio -l
         This will generate ressources with 3 packs for low memory.

res
|-- base.zip (required)
|-- demos (required)
|   `-- *.bin
|-- gfx (optionnal)
|   |-- actors
|   |-- levels
|   `-- textures
`-- texts (required)
    `-- *.json

dynos
|-- audio (optionnal)
`-- packs
    `-- Render96AlphaModelPack (optionnal)
```