#include "imageBi.h"
#include <stdlib.h>
#include <stdio.h>

MatrixBi * createMatrixBi(int rows, int columns)
{
    MatrixBi *bi;

    bi = (MatrixBi*)malloc(sizeof(MatrixBi));
    bi->n = 0;
    bi->width=rows;
    bi->height=columns;

    bi->size = rows*columns;
    
    bi->data = (ImageBi *)calloc(bi->size, sizeof(int));

    return bi;
}

MatrixBi * loadFileBi(char *name)
{

    //printf("%s \n", "wow. it got to this point");
    FILE *fp = fopen(name, "rb");

    
    int width, height;
    char buffer[10];

	fgets(buffer, 10, fp);
	//printf("%s \n", buffer);
	fscanf(fp, "%d %d", &width, &height);
	//printf("%d %d \n", width, height);
	
    fgets(buffer, 10, fp);
	//printf("%s \n", buffer);

    MatrixBi *bi = createMatrixBi(width, height);
    fread(bi->data, 3 * bi->width, bi->height, fp);

    return bi;
}

void saveFileBi(MatrixBi *bi, char *name)
{
    FILE *fp = fopen(name, "wb");

    fprintf(fp, "P4\n");
    fprintf(fp, "%d %d\n", bi->width,bi->height);
    //fwrite(&(bi->n), sizeof(int), 1, fp);

    fwrite(bi->data, 3*bi->width,bi->height, fp);
}