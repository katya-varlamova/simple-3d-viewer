# BUILD

It is possible to build app with docker image katyavarlamova/qtjsoncppimg. If there are problems with this image, you may create new one with Dockerfile.

In docker container:

```bash
git clone https://github.com/katya-varlamova/simple-3d-viewer ./src
cd src
mkdir build && cd build
cmake ../
make
cd ../../
```

# TEST

```bash
./src/build/UnitTests/units
```
# RUN

```bash
    cd src/data
    chmod +x ./make_config
    ./make_config
    cd ../build
    ./src $(realpath ../data/config.json) -no-gui
```