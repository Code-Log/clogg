LD_LIBRARIES = clogg
LD_PATH = ../build
INCLUDE_PATH = ../include

all:
	make test
    
main.o: libclogg.a
	clang++ -c main.cpp -I ${INCLUDE_PATH}

test: main.o
	clang++ main.o -L ${LD_PATH} -l${LD_LIBRARIES} -o test

libclogg.a:
	cd ../build && make

clean:
	rm *.o test
	cd ../build && make clean
