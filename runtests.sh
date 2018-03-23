#! /bin/bash

export LD_LIBRARY_PATH=".:/opt/intel/mkl/lib/intel64_lin"

./main_basic lib.so

./main_libs lib.so

LD_PRELOAD="/opt/intel/mkl/lib/intel64_lin/libmkl_avx2.so /opt/intel/mkl/lib/intel64_lin/libmkl_def.so /opt/intel/mkl/lib/intel64_lin/libmkl_core.so /opt/intel/mkl/lib/intel64_lin/libmkl_sequential.so" ./main_basic lib.so
