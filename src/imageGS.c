#include "imageGS.h"
#include "imageBi.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * @brief Function to create and allocate memory to a matrix in wich it will be stored bytes of a grayscale image
 * 
 */
MatrixGS * createMatrixGS(int rows, int columns)
{
    MatrixGS *gs;

    gs = (MatrixGS*)malloc(sizeof(MatrixGS));
    gs->n = 0;
    gs->width=rows;
    gs->height=columns;

    gs->size = rows*columns;
    
    gs->data = (ImageGS *)calloc(gs->size, sizeof(char));

    return gs;
}

MatrixGS * loadFileGS(char *name)
{
    FILE *fp = fopen(name, "rb");
    
    int width, height, max_color;
    char buffer[10];

	fgets(buffer, sizeof(buffer), fp);
	fscanf(fp, "%d %d", &width, &height);
	
    fscanf(fp, "%d", &max_color);
    fgets(buffer, sizeof(buffer), fp);

    MatrixGS *gs = createMatrixGS(width, height);
    fread(gs->data, gs->width, gs->height, fp);

    return gs;
}

void saveFileGS(MatrixGS *gs, char *name)
{
    FILE *fp = fopen(name, "wb");

    fprintf(fp, "P5\n");
    fprintf(fp, "%d %d\n", gs->width,gs->height);
    fprintf(fp, "%d\n",255);

    fwrite(gs->data, gs->width,gs->height, fp);
}

void gray2bin(MatrixGS * gs, char * tsh, char * name)
{
    ImageGS * px = gs->data;

    MatrixBi * bi = createMatrixGS(gs->width, gs->height);
    ImageBi * px2 = bi->data;
    int p=0 ,j = 0;
    for(int i = 0; i < bi->size; i++){
        
        if(px->g < tsh){
            p++;
            //px2->b = ((0 << (7-count)) & 0x01);
            px2->b=255;
            
        }else
        {
            j++;
            px2->b=0;
            
            
        }
       
        px++;
        px2++;
        
        
        
    }
    int hist[2];
    hist[0]=p;
    hist[1]=j;
    printf("p - %i\nj - %i\nsize - %d\n", p,j, bi->size);
    printf("0 - %i\n1 - %i", hist[0], hist[1]);
    printf("\n");
    saveFileGS(bi, name);
}

void intensityGS(MatrixGS *gs, char inten, char *name)
{
    ImageGS * px = gs->data;

    MatrixGS * gsint = createMatrixGS(gs->width, gs->height);
    ImageGS * px2 = gsint->data;

    for(int i = 0; i < gsint->size; i++){
        if(px->g + inten >255){
            px2->g = 255;
        }else if (px->g + inten < 0)
        {
            px2->g=0;
        }else{
            px2->g= px->g + inten;
        }

        px++;
        px2++;
    }
    
    saveFileGS(gsint, name);
}

void filterGS(MatrixGS *gs, char *name)
{
    ImageGS * px = gs->data;

    MatrixGS * gsfil = createMatrixGS(gs->width, gs->height);
    ImageGS * px2 = gsfil->data;

    char count = 1;


    for(int i = 0; i < gsfil->size; i++){

        //cantos da imagem. vai buscar 4 a volta do pixel atual
        if(count == 1)
        {
            px2->g = px->g / 4 + (px+1)->g / 4 + (px+gs->width)->g / 4 + (px+gs->width+1)->g / 4;
        }
        else if (count == gs->width )
        {
            px2->g = px->g / 4 + (px-1)->g / 4 + (px+gs->width)->g / 4 + (px+gs->width-1)->g / 4;
        }
        else if (count == gs->size - gs->width)
        {
            px2->g = px->g / 4 + (px+1)->g / 4 + (px-gs->width)->g / 4 + (px-gs->width+1)->g / 4;
        }
        else if (count == gs->size)
        {
            px2->g = px->g / 4 + (px-1)->g / 4 + (px-gs->width)->g / 4 + (px-gs->width-1)->g / 4;
        }
        //linhas e colunas. vai buscar os 6 pixeis a volta
        else if (count < gs->width)
        {
            px2->g = (px-1)->g / 6 + px->g / 6 + (px+1)->g / 6 + (px+gs->width-1)->g / 6 + (px+gs->width)->g / 6 + (px+gs->width+1)->g / 6;
        }
        else if (count > gs->size - gs->width && count < gs->size)
        {
            px2->g = (px-1)->g / 6 + px->g / 6 + (px+1)->g / 6 + (px-gs->width-1)->g / 6 + (px-gs->width)->g / 6 + (px-gs->width+1)->g / 6;
        }
        else if ((count-1) % gs->width == 0 )
        {
            px2->g = (px-gs->width)->g / 6 + (px-gs->width+1)->g / 6 + px->g / 6 + (px+1)->g / 6 + (px+gs->width)->g / 6 + (px+gs->width+1)->g / 6;
        }
        else if (count % gs->width == 0 )
        {
            px2->g = (px-gs->width-1)->g / 6 + (px-gs->width)->g / 6 + (px-1)->g / 6 + px->g / 6 + (px+gs->width-1)->g / 6 + (px+gs->width)->g / 6;
        }
        //pixeis no centro da imagem
        else
        {
            px2->g = (px-gs->width-1)->g / 9 + (px-gs->width)->g / 9 + (px-gs->width+1)->g / 9 + (px-1)->g / 9 + px->g / 9 + (px+1)->g / 9 + (px+gs->width-1)->g / 9 + (px+gs->width)->g / 9 + (px+gs->width+1)->g / 9;
        }
        
        count++;
        px++;
        px2++;
        
    }
    
    saveFileGS(gsfil, name);
}
