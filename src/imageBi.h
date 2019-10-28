#ifndef INC_00_IMAGEBIN_H
#define INC_00_IMAGEBIN_H

/**
 * Structure to store a sequence of bits
 */ 
typedef struct{
    /**Bit sequence*/
    unsigned char b;
}ImageBi;

typedef struct {
    /**Matrix of bits*/
    ImageBi *data;
    /**Matrix width*/
    int width;
    /**Matrix height*/
    int height;
    /**Matrix size*/
    int size;
} MatrixBi;

/**
 * Creates a matrix and allocates memory to store the bits of a pbm image
 * 
 * @param rows The number of rows of the image
 * @param columns The number of columns of the image
*/
MatrixBi * createMatrixBi(int rows, int columns);

/**
 * Loads a pbm format image
 * 
 * @param name Name of the image file
 */
MatrixBi * loadFileBi(char *name);

/**
 * Saves a file in the pbm format
 * 
 * @param bi Matrix of bits to be saved in pbm format
 * @param name Name of the file in which the matrix will be stored
 */
void saveFileBi(MatrixBi *bi, char *name);

#endif //INC_00_IMAGEBIN_H