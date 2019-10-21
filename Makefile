all: ppmtesting

ppmtesting: imageRGB.o ppmtesting.o
	gcc -o ppmtesting ppmtesting.o imageRGB.o

ppmtesting.o: ppmtesting.c imageRGB.h
	gcc -o ppmtesting.o -c ppmtesting.c -W -Wall


imageRGB.o: imageRGB.c imageRGB.h
	gcc -o imageRGB.o -c imageRGB.c -W -Wall

clean:
	rm -rf *.o
