#include "imageGS.h"
#include <stdlib.h>
#include <stdio.h>

MatrixGS * createMatrixGS(int rows, int columns)
{
    MatrixGS *gs;

    gs = (MatrixGS*)malloc(sizeof(MatrixGS));
    gs->n = 0;
    gs->width=rows;
    gs->height=columns;

    gs->size = rows*columns;
    
    gs->data = (ImageGS *)calloc(gs->size, sizeof(int));

    return gs;
}

void saveFileGS(MatrixGS *gs, char *name)
{
    FILE *fp = fopen(name, "wb");

    fprintf(fp, "P5\n");
    fprintf(fp, "%d %d\n", gs->width,gs->height);
    fprintf(fp, "%d\n",255);
    //fwrite(&(gs->n), sizeof(int), 1, fp);

    fwrite(gs->data, 3*gs->width,gs->height, fp);
}