#!/bin/bash

# 临时复制，注意调试结束后注释
# cp -r /mnt/d/lvgl/simple_beken/beken_generated src/

mkdir -p build

cd build

cmake -G "Unix Makefiles" ..

make -j16

cd ../bin

./main
