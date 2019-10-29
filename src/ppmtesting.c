#include <stdio.h>
#include "imageRGB.h"
#include "imageGS.h"
#include "imageBi.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/** \mainpage <h1>Image Processing</h1>
 * 
 * This is a simple image manipulation project.
 * 
 * The main purpose of this project is to manipulate images in the pnm format.
 * 
 * Users can:<ul>
 * <li>Convert one format of image into another</li>
 * <li>Apply filters</li>
 * <li>Increse/Decrease intensity of an image</li>
 * </ul>
 * 
 * \authors Rodrigo Oliveira, Daniel Pinto
 */

/**
 * Main program 
 */

int main(int argc, char* argv[])
{	 
	int threshold = 120;
	int inten = 70;

	
	if (argc > 1){
		for (int i=1; i < argc; i+=2){
			
			if (strcmp(argv[i], "-i")==0 && isdigit(*argv[i+1])){

				inten = atoi(argv[i+1]);
			}
			if (strcmp(argv[i], "-t")==0 && isdigit(*argv[i+1])){

				threshold = atoi(argv[i+1]);
			}
			if (strcmp(argv[i], "-d")==0 && isdigit(*argv[i+1])){

				inten = -atoi(argv[i+1]);
			}
		}
	}

	// lena.ppm
	MatrixRGB *rgb = loadFileRGB("../res/ppm/lena.ppm");

    color2gray(rgb, "../res/pgm/lena_gs.pgm", "../res/pgm/lena_gs_r.pgm", "../res/pgm/lena_gs_g.pgm", "../res/pgm/lena_gs_b.pgm");

	MatrixGS *gs = loadFileGS("../res/pgm/lena_gs.pgm");

	gray2bin(gs, threshold, "../res/pbm/lena_bin.pgm");

	intensityRGB(rgb, inten, "../res/ppm/lena_intensity_change_rgb.ppm");

	intensityGS(gs, inten, "../res/pgm/lena_intensity_change_gs.pgm");

	filterRGB(rgb, "../res/ppm/lena_filter_media_rgb.ppm");

	filterGS(gs, "../res/pgm/lena_filter_media_gs.pgm");

	watermarkRGB(rgb, "../res/ppm/lena_watermarked_rgb.ppm");

	watermarkGS(gs, "../res/pgm/lena_watermarked_gs.pgm");

	//------------------------------------------------------------

	//baboon.ppm

	MatrixRGB *rgb2 = loadFileRGB("../res/ppm/baboon.ppm");

    color2gray(rgb2, "../res/pgm/baboon_gs.pgm", "../res/pgm/baboon_gs_r.pgm", "../res/pgm/baboon_gs_g.pgm", "../res/pgm/baboon_gs_b.pgm");

	MatrixGS *gs2 = loadFileGS("../res/pgm/baboon_gs.pgm");

	gray2bin(gs2, threshold, "../res/pbm/baboon_bin.pgm");

	intensityRGB(rgb2, inten, "../res/ppm/baboon_intensity_change_rgb.ppm");

	intensityGS(gs2, inten, "../res/pgm/baboon_intensity_change_gs.pgm");

	filterRGB(rgb2, "../res/ppm/baboon_filter_media_rgb.ppm");

	filterGS(gs2, "../res/pgm/baboon_filter_media_gs.pgm");

	watermarkRGB(rgb2, "../res/ppm/baboon_watermarked_rgb.ppm");

	watermarkGS(gs2, "../res/pgm/baboon_watermarked_gs.pgm");
	
    return 0;
}


