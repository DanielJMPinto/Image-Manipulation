
struct RGBPixel{
		unsigned char r,g,b;
}ImageRGB;

struct RGBPixel createRGBpixe(int r, int g, int b){
	struct RGBPixel pixel;
	pixel.r = r;
	pixel.g = g;
	pixel.b = b;
	
	return pixel; 
}
