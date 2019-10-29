#ifndef INC_00_IMAGERGB_H
#define INC_00_IMAGERGB_H

/**
 * Structure to store an RGB pixel
 */ 
typedef struct{
    /**Red*/
	unsigned char r;
    /**Green*/
    unsigned char g;
    /**Blue*/
    unsigned char b;
}ImageRGB;

/**
 * Structure to store an image with RGB pixels
 */ 
typedef struct {
    /**Matrix of pixels*/
    ImageRGB *data;
    /**Matrix width*/
    int width;
    /**Matrix height*/
    int height;
    /**Matrix size*/
    int size;
} MatrixRGB;

/**
 * Creates a matrix and allocates memory to store the pixels of a ppm image
 * 
 * @param rows The number of rows of pixels of the image
 * @param columns The number of columns of pixels of the image
*/
MatrixRGB * createMatrixRGB(int rows, int columns);

/**
 * Loads a ppm format image
 * 
 * @param name Name of the image file
 */
MatrixRGB * loadFileRGB(char *name);

/**
 * Saves a file in the ppm format
 * 
 * @param rgb Matrix of pixels to be saved in ppm format
 * @param name Name of the file in which the matrix will be stored
 */
void saveFileRGB(MatrixRGB *rgb, char *name);

/**
 * Converts a ppm format image into a pgm image
 * 
 * @param rgb Matrix of pixels that will be converted into grayscale
 * @param nome Name of the file in which the new image will be stored
 */
void color2gray(MatrixRGB *rgb, char *nome);

/**
 * Changes the intensity of a ppm image
 * 
 * @param rgb Matrix of pixels
 * @param inten Value to be added to each pixel in order to change the intensity of the image
 * @param name Name of the file in which the new image will be stored
 */
void intensityRGB(MatrixRGB *rgb, char inten, char *name);

/**
 * Applies a filter to a ppm image
 * 
 * @param rgb Matrix of pixels
 * @param name Name of the file in which the new image will be stored
 */
void filterRGB(MatrixRGB *rgb, char *name);

/**
 * Applies a watermark to a ppm image
 * 
 * @param rgb Matrix of pixels
 * @param name Name of the file in which the new image with the watermark will be stored
 */
void watermarkRGB(MatrixRGB* rgb, char* name);

#endif //INC_00_IMAGERGB_H
