#ifndef INC_00_IMAGEGS_H
#define INC_00_IMAGEGS_H

/**
 * Structure to store a grayscale pixel
 */ 
typedef struct{
    /**Gray*/
    unsigned char g;
}ImageGS;

/**
 * Structure to store an image with grayscale pixels
 */
typedef struct {
    /**Matrix of pixels*/
    ImageGS *data;
    /**Matrix width*/
    int width;
    /**Matrix height*/
    int height;
    /**Matrix size*/
    int size;
} MatrixGS;

/**
 * Creates a matrix and allocates memory to store the pixels of a pgm image
 * 
 * @param rows The number of rows of pixels of the image
 * @param columns The number of columns of pixels of the image
*/
MatrixGS * createMatrixGS(int rows, int columns);

/**
 * Loads a pgm format image
 * 
 * @param name Name of the image file
 */
MatrixGS * loadFileGS(char *name);

/**
 * Saves a file in the pgm format
 * 
 * @param gs Matrix of pixels to be saved in pgm format
 * @param name Name of the file in which the matrix will be stored
 */
void saveFileGS(MatrixGS *gs, char *name);

/**
 * Converts a pgm format image into a pbm image
 * 
 * @param gs Matrix of pixels that will be converted into pbm format
 * @param nome Name of the file in which the new image will be stored
 */
void gray2bin(MatrixGS * gs, int tsh, char * name);

/**
 * Changes the intensity of a pgm image
 * 
 * @param gs Matrix of pixels
 * @param inten Value to be added to each pixel in order to change the intensity of the image
 * @param name Name of the file in which the new image will be stored
 */
void intensityGS(MatrixGS *gs, char inten, char *name);

/**
 * Applies a filter to a pgm image
 * 
 * @param gs Matrix of pixels
 * @param name Name of the file in which the new image will be stored
 */
void filterGS(MatrixGS *gs, char *name);

/**
 * Applies a watermark to a grayscale image
 * 
 * @param gs Matrix of pixels
 * @param name Name of the file in which the new image with the watermark will be stored
 */
void watermarkGS(MatrixGS* gs, char* name);

#endif //INC_00_IMAGEGS_H