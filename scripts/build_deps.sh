#!/bin/bash

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
PUDDLE_ROOT="$SCRIPT_DIR"/..

echo "BUILD     ZXCONFIG"

cd "$PUDDLE_ROOT/third-party/zxconfig"

# use cmake to build it

mkdir build
cd build 

cmake .. -UBUILD_TESTING -DBUILD_TESTING=0
make

echo "INSTALL       ZXCONFIG"

sudo make install
