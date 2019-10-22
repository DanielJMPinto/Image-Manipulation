#include <stdio.h>
#include "imageRGB.h"
#include "imageGS.h"

/**
 * @brief Main program 
 */

int main(int argc, char** argv[])
{	
	
	/*struct RGBPixel pixel1 = createRGBpixel(32,64,129);
	
	printf("pixel1 is %d, %d, %d \n", pixel1.r, pixel1.g, pixel1.b);*/

	char *filename = argv[1];
	//printf("%s \n", filename);
	//printf("%s \n", "every time a seg fault happens, my life is shorten by a day");
	MatrixRGB *dm = loadFileRGB(filename);
    color2gray(dm, "salvar_gs.pgm");
	saveFileRGB(dm, "salvar_rgb.ppm");
    return 0;

	
	/*;
	
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


