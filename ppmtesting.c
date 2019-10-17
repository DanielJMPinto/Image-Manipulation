#include <stdio.h>

struct RGBPixel{
		unsigned int r,g,b;
	};

struct RGBPixel createRGBpixel(int r, int g, int b){
	struct RGBPixel pixel;
	pixel.r = r;
	pixel.g = g;
	pixel.b = b;
	
	return pixel; 
}

int main(int argc, char **argv)
{	
	
	struct RGBPixel pixel1 = createRGBpixel(32,64,129);
	
	printf("pixel1 is %d, %d, %d \n", pixel1.r, pixel1.g, pixel1.b);
	
	char *filename = argv[1];
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
	
	
	fread(bytes, 1,3,fp);
	printf("%u %u %u\n", bytes[0], bytes[1], bytes[2]);
	
	
	return 0;
}


