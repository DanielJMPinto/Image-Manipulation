#include "imageBi.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * Creates a matrix and allocates memory to store the bits of a pbm image
 * 
 * @param rows The number of rows of the image
 * @param columns The number of columns of the image
*/
MatrixBi * createMatrixBi(int rows, int columns)
{
    MatrixBi *bi;

    bi = (MatrixBi*)malloc(sizeof(MatrixBi));
    bi->width=rows;
    bi->height=columns;

    bi->size = rows*columns;
    
    bi->data = (ImageBi *)calloc(bi->size, sizeof(char));

    return bi;
}

/**
 * Loads a pbm format image
 * 
 * @param name Name of the image file
 */
MatrixBi * loadFileBi(char *name)
{
    FILE *fp = fopen(name, "rb");
    
    int width, height;
    char buffer[10];

	fgets(buffer, sizeof(buffer), fp);
	fscanf(fp, "%d %d", &width, &height);
	
    fgets(buffer, sizeof(buffer), fp);

    MatrixBi *bi = createMatrixBi(width, height);
    fread(bi->data, bi->width, bi->height, fp);

    return bi;
}

/**
 * Saves a file in the pbm format
 * 
 * @param bi Matrix of bits to be saved in pbm format
 * @param name Name of the file in which the matrix will be stored
 */
void saveFileBi(MatrixBi *bi, char *name)
{
    FILE *fp = fopen(name, "wb");

    fprintf(fp, "P4\n");
    fprintf(fp, "%d %d\n", bi->width,bi->height);

    fwrite(bi->data, bi->width,bi->height, fp);
}