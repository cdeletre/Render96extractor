# Render96extractor

Tool to extract and generate ressources package for [Render96/Render96ex](https://github.com/Render96/Render96ex) (sm64ex fork). This tools also pack the demo bin data so that [cdeletre/Render96ex](https://github.com/cdeletre/Render96ex/tree/tester_rt64alpha) can be used (it's a fork that builds the executable without hardcoding assets).

# Usage

First put your `baserom.us.z64` (I won't provided this file) in the root directory and check that the sha1 of this file is correct:

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

# Projects that are sourced here

## Render96ex

Everything in this repository comes from [Render96ex](https://github.com/Render96/Render96ex) except:

- `packs/gfx`
- `packs/lowmem/gfx`
- `packs/Render96-Alpha-3.1-modelpack`
- `packs/lowmem/Render96-Alpha-3.1-modelpack`
- `gen-res-dynos.sh`
- `README.md`

Some file that come from [Render96ex](https://github.com/Render96/Render96ex) have been modified:
- `Makefile` (demo bin data are now loaded from a file)
- `Dockerfile` (downgrade ubuntu version)
- `tools/demo_data_converter.py` (demo bin data are now loaded from a file)

This project hasn't specified a licence.

## RENDER96-HD-TEXTURE-PACK

[RENDER96-HD-TEXTURE-PACK](https://github.com/pokeheadroom/RENDER96-HD-TEXTURE-PACK) is used as HD texture pack in:

- `packs/gfx`
- `packs/lowmem/gfx`

This project has specified a [GPL 3.0 licence](https://github.com/pokeheadroom/RENDER96-HD-TEXTURE-PACK/blob/master/LICENSE)

## Render96-Alpha-3.1-modelpack

[ModelPack](https://github.com/Render96/ModelPack) Alpha 3.1.7 is used as 3D model pack in:

- `packs/Render96-Alpha-3.1-modelpack`
- `packs/lowmem/Render96-Alpha-3.1-modelpack`

This project hasn't specified a licence.