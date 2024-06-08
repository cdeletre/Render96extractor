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