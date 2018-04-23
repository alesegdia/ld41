#!/usr/bin/env bash

set +e
rm drake-win32.zip

set -e
rm -rf winbuild/
mkdir winbuild 
cd winbuild
cmake .. -DCMAKE_TOOLCHAIN_FILE=../module/aether/cmake/mingw-i686-toolchain.cmake
make -j8
cp -r ../media ../bin/win32
cd ../bin/win32
zip ../../drake-win32.zip **/* *
cd ../../

set +e
rm drake-linux.zip

set -e
rm -rf linbuild
mkdir linbuild
cd linbuild
cmake ..
make -j8
cp -r ../media/ ../bin/linux
cd ../bin/linux/
zip ../../drake-linux.zip **/* *

