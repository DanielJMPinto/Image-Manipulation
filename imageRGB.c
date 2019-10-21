#include "imageRGB.h"
#include <stdlib.h>
#include <stdio.h>

Matrix * CreateMat(int rows, int columns)
{
    Matrix *tmp;

    tmp = (Matrix*)malloc(sizeof(Matrix));
    tmp->n = 0;
    tmp->width=rows;
    tmp->height=columns;

    tmp->size = rows*columns;
    
    tmp->data = (ImageRGB *)calloc(tmp->size, sizeof(int));

    return tmp;
}

Matrix * LoadFromFile(char *name)
{

    printf("%s \n", "wow. it got to this point");
    FILE *fp = fopen(name, "rb");

    
    int width, height, max_color;
    char buffer[10];

	fgets(buffer, 10, fp);
	printf("%s \n", buffer);
	fscanf(fp, "%d %d", &width, &height);
	printf("%d %d \n", width, height);
	
    fscanf(fp, "%d", &max_color);
	printf("%d \n", max_color);
    

    Matrix *tmp = CreateMat(width, height);
    fread(tmp->data, 3 * tmp->width, tmp->height, fp);

    return tmp;
}

void SaveOnFile(Matrix *dm, char *name)
{
    FILE *fp = fopen(name, "wb");

    fwrite(&(dm->n), sizeof(int), 1, fp);

    fwrite(dm->data, sizeof(int), dm->n, fp);
}

void PrintMat(Matrix *dm)
{

    ImageRGB * array_ptr = dm->data;

    for(int i = 0; i <= dm->size; i++){
        PrintRGB(array_ptr);
        array_ptr++;
    }

    printf("\n");
}

void PrintRGB(ImageRGB *px){

    printf("[ %d, %d, %d ]", px->r, px->g, px->b);

}