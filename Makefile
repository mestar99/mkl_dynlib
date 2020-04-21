.PHONY: all main_all main_basic clean

all: main_all lib.so

main_all: main_basic main_libs

main_basic: main_basic_local main_basic_global

# not working
main_basic_local: main.c
	gcc -o main_basic_local -g -O0 main.c -ldl

main_basic_global: main.c
	gcc -o main_basic_global -g -O0 main.c -ldl -DLOAD_GLOBAL

# working
main_libs: main.c
	gcc -o main_libs -g -O0 main.c -ldl -Wl,--no-as-needed -L/opt/intel/mkl/lib/intel64_lin -lmkl_core -lmkl_sequential -lmkl_intel_lp64 -lpthread -lm

lib.so: lib.so.1
	ln -sfT lib.so.1 lib.so

lib.so.1: lib.c
	gcc -shared -fPIC -Wl,-soname,lib.so.1,--no-as-needed -o lib.so.1 -m64 -I/opt/intel/mkl/include lib.c -L/opt/intel/mkl/lib/intel64_lin -lmkl_core -lmkl_sequential -lmkl_intel_lp64 -lpthread -lm

clean:
	rm main_basic_local main_basic_global main_libs lib.so lib.so.1
