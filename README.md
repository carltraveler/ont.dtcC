# ont.dtcC
ontology wasm toolchain for c/c++



# install

git clone https://github.com/carltraveler/ont.dtcC

cd install/

cp -r * install_dir

export PATH=$PATH:install_dir/bin



# tools

ont_c

ont_cpp

wasm-ld

wasm-objdump

wasm2wat



# usage

ont_c test.c

ont_c test.c -o test.wasm

ont_cpp helloc.cpp 

ont_cpp helloc.cpp -o helloc.wasm

ont_cpp helloc.cpp -o helloc.wasm -Llibdir -lmalloc

ont_c -nostdinc -I/${install_dir}/include/libc -L/${install_dir}/lib -lc -lmalloc -static test_memset.c
