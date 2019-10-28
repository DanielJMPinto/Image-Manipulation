#include "imageBi.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * @brief Function to create and allocate memory to a matrix in wich it will be stored bits of a binary image
 * 
 */
MatrixBi * createMatrixBi(int rows, int columns)
{
    MatrixBi *bi;

    bi = (MatrixBi*)malloc(sizeof(MatrixBi));
    bi->n = 0;
    bi->width=rows;
    bi->height=columns;

    bi->size = rows*columns;
    
    bi->data = (ImageBi *)calloc(bi->size, sizeof(char));

    return bi;
}

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

void saveFileBi(MatrixBi *bi, char *name)
{
    FILE *fp = fopen(name, "wb");

    fprintf(fp, "P4\n");
    fprintf(fp, "%d %d\n", bi->width,bi->height);

    fwrite(bi->data, bi->width,bi->height, fp);
}