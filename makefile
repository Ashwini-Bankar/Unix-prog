
all:myprogram
myprogram:main1.o libmysharedlib.so
	gcc -L /home/ashwini/Unix-prog myprogram main1.o -lmysharedlib
libmysharedlib.so:main1.o copyfile.o readfile.o
	gcc -shared main1.c copyfile.c readfile.c -o libmysharedlib.so
main1.o:main1.c header.h
	gcc -c -fPIC main1.c 
copyfile.o:copyfile.c header.h
	gcc -c -fPIC copyfile.c
readfile.o:readfile.c header.h
	gcc -c -fPIC readfile.c
libs:libmysharedlib.so
clean:
	rm -f myprogram *.o *.so *.gch
