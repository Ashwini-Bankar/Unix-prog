all:test
test:source_test.o libholecount.a
	gcc -lm -o test source_test.o -L. -lholecount
holecount.a:source.o source_test.o
	ar -cvr libholecount.a source.o source_test.o

source.o:source.c fileheader.h
	gcc -c source.c

source_test.o:source_test.c fileheader.h
	gcc -c source_test.c

libs:libholecount.a

clean:
	rm -f test *.o *.a
