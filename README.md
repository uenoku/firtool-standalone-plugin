# An example of MLIR pass plugin for CIRCT dialect


## Building - Component Build

```sh
DIR=<install path of CIRCT>
cd build
cmake .. -GNinja -DCMAKE_CXX_COMPILER=clang++ \
        -DCMAKE_C_COMPILER=clang \
        -DCIRCT_DIR=$DIR/lib/cmake/circt \
        -DMLIR_DIR=$DIR/lib/cmake/mlir \ 
        -DLLVM_DIR=$DIR/lib/cmake/llvm \ 
        -DLLVM_ENABLE_ZSTD=Off
ninja check-standalone
ls build/StandalonePlugin.so
```
