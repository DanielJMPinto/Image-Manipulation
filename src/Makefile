all: ppmtesting

ppmtesting: imageRGB.o imageGS.o imageBi.o ppmtesting.o
	gcc -o ppmtesting ppmtesting.o imageRGB.o imageGS.o imageBi.o

ppmtesting.o: ppmtesting.c imageRGB.h imageGS.h imageBi.h
	gcc -o ppmtesting.o -c ppmtesting.c -W -Wall

imageRGB.o: imageRGB.c imageRGB.h
	gcc -o imageRGB.o -c imageRGB.c -W -Wall

imageGS.o: imageGS.c imageGS.h
	gcc -o imageGS.o -c imageGS.c -W -Wall

imageBi.o: imageBi.c imageBi.h
	gcc -o imageBi.o -c imageBi.c -W -Wall

clean:
	rm -rf *.o
