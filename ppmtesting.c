#include <stdio.h>
#include "imageRGB.h"

int main(void)
{	
	
	/*struct RGBPixel pixel1 = createRGBpixel(32,64,129);
	
	printf("pixel1 is %d, %d, %d \n", pixel1.r, pixel1.g, pixel1.b);*/
	
	//printf("%s", argv[1]);
	printf("%s", "argv[1]");
	Matrix *dm = LoadFromFile("lena.ppm");
    PrintMat(dm);
    return 0; 
	
	
	/*char *filename = argv[1];
	printf("%s \n", filename);
	
	FILE *fp;
	fp = fopen(filename, "rb");
	
	char buffer[100];

	fgets(buffer, 100, fp);
	printf("%s", buffer);
	fgets(buffer, 100, fp);
	printf("%s", buffer);
	fgets(buffer, 100, fp);
	printf("%s", buffer);
	
	unsigned char bytes[3];
	struct RGBPixel pixel;
	
	fread( bytes, 1,3,fp);
	pixel.r=bytes[0];
	pixel.g=bytes[1];
	pixel.b=bytes[2];
	printf("%u %u %u\n", pixel.r, pixel.g, pixel.b);
	
	
	return 0;*/
}


