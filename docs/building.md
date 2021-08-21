## Build
### CLI

To build, run `build.py`:
```
python3 build.py
```

`build.py` takes the following flags:
* `-i` / `--install-dependencies`
    Install the library dependencies before build. Defaults to `false`.
* `-nb` / `--no-build`
    Skip the build step. Defaults to `false`.
* `-ni` / `--no-install`
    Skip the install step. Defaults to `false`.
* `-c` / `--cleanup`
    Deletes the build and install data/temp files after build. Defaults to `false`.
* `-d` / `--debug`
    Build in debug

After the build, the client, server and data will be copied to the `./src/install` directory. This directory has the following structure:

```
install
    + - _platform name_ // Windows/Darwin/Linux
        + - bin
            // texturegenerator.exe on Windows and any other dependencies
```

Note: If `-c` is passed to `build.py`, the `./src/install` directory will be deleted after the build.

A zipped version of `./src/install` will be created in `./src/archives`. The resulting filename has the format:
```
texturegenerator-version-platform.zip
```

For instance:
```
texturegenerator-1.2.3-darwin.zip
```
