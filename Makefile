all: ppmtesting

ppmtesting: imageRGB.c ppmtesting.c
	gcc -o imageRGB imageRGB.c ppmtesting.c -I.


ppmtesting.o: ppmtesting.c
	gcc -o ppmtesting.o -c ppmtesting.c -W -Wall


imageRGB.o: imageRGB.c
	gcc -o imageRGB.o -c imageRGB.c -W -Wall

clean:
	rm -rf *.o
