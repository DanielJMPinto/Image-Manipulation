#include "imageRGB.h"
#include "imageGS.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Function to create and allocate memory to a matrix in wich it will be stored bytes of a color image
 * 
 */
MatrixRGB * createMatrixRGB(int rows, int columns)
{
    MatrixRGB *rgb;

    rgb = (MatrixRGB*)malloc(sizeof(MatrixRGB));
    rgb->n = 0;
    rgb->width=rows;
    rgb->height=columns;

    rgb->size = rows*columns;
    
    rgb->data = (ImageRGB *)calloc(rgb->size, sizeof(int));

    return rgb;
}

/**
 * @brief Loads color image into matrix
 */
MatrixRGB * loadFileRGB(char *name)
{
    FILE *fp = fopen(name, "rb");

    int width, height, max_color;
    char buffer[10];

	fgets(buffer, sizeof(buffer), fp);
	fscanf(fp, "%d %d", &width, &height);
	
    fscanf(fp, "%d", &max_color);
    fgets(buffer, sizeof(buffer), fp);

    MatrixRGB *rgb = createMatrixRGB(width, height);
    fread(rgb->data, 3 * rgb->width, rgb->height, fp);

    return rgb;
}

/**
 * @brief Saves a matrix in ppm format (color image)
 */
void saveFileRGB(MatrixRGB *rgb, char *name)
{
    FILE *fp = fopen(name, "wb");

    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", rgb->width,rgb->height);
    fprintf(fp, "%d\n",255);

    fwrite(rgb->data, 3*rgb->width,rgb->height, fp);
}


/**
 * @brief Makes a color to grayscale conversion
 */
void color2gray(MatrixRGB *rgb, char *name)
{
    ImageRGB * px = rgb->data;

    MatrixGS * gs = createMatrixGS(rgb->width, rgb->height);
    ImageGS * px2 = gs->data;

    MatrixGS * gs_r = createMatrixGS(rgb->width, rgb->height);
    ImageGS * px2_r = gs_r->data;

    MatrixGS * gs_g = createMatrixGS(rgb->width, rgb->height);
    ImageGS * px2_g = gs_g->data;

    MatrixGS * gs_b = createMatrixGS(rgb->width, rgb->height);
    ImageGS * px2_b = gs_b->data;

    for(int i = 0; i < gs->size; i++){
        px2->g = px->r * 0.3 + px->g * 0.58 + px->b * 0.11;
        px2_r->g = px->r;
        px2_g->g = px->g;
        px2_b->g = px->b;
        
        px++;
        px2++;
        px2_r++;
        px2_g++;
        px2_b++;
    }
    
    saveFileGS(gs, name);
    saveFileGS(gs_r, "../res/pgm/salvar_gray_red.pgm");
    saveFileGS(gs_g, "../res/pgm/salvar_gray_green.pgm");
    saveFileGS(gs_b, "../res/pgm/salvar_gray_blue.pgm");
}

void intensityRGB(MatrixRGB *rgb, char inten, char *name)
{
    ImageRGB * px = rgb->data;

    MatrixRGB * rgbint = createMatrixRGB(rgb->width, rgb->height);
    ImageRGB * px2 = rgbint->data;

    for(int i = 0; i < rgbint->size; i++){
        if(px->r + inten >255){
            px2->r = 255;
        }else if (px->r + inten < 0)
        {
            px2->r=0;
        }else{
            px2->r= px->r + inten;
        }
        
        if(px->g + inten >255){
            px2->g = 255;
        }else if (px->g + inten < 0)
        {
            px2->g=0;
        }else{
            px2->g= px->g + inten;
        }

        if(px->b + inten >255){
            px2->b = 255;
        }else if (px->b + inten < 0)
        {
            px2->b=0;
        }else{
            px2->b= px->b + inten;
        }

        px++;
        px2++;
    }
    
    saveFileRGB(rgbint, name);
}

void filterRGB(MatrixRGB *rgb, char *name)
{
    ImageRGB * px = rgb->data;

    MatrixRGB * rgbfil = createMatrixRGB(rgb->width, rgb->height);
    ImageRGB * px2 = rgbfil->data;

    char count = 1;


    for(int i = 0; i < rgbfil->size; i++){

        //cantos da imagem. vai buscar 4 a volta do pixel atual
        if(count == 1)
        {
            px2->r = px->r / 4 + (px+1)->r / 4 + (px+rgb->width)->r / 4 + (px+rgb->width+1)->r / 4;
            px2->g = px->g / 4 + (px+1)->g / 4 + (px+rgb->width)->g / 4 + (px+rgb->width+1)->g / 4;
            px2->b = px->b / 4 + (px+1)->b / 4 + (px+rgb->width)->b / 4 + (px+rgb->width+1)->b / 4;
        }
        else if (count == rgb->width )
        {
            px2->r = px->r / 4 + (px-1)->r / 4 + (px+rgb->width)->r / 4 + (px+rgb->width-1)->r / 4;
            px2->g = px->g / 4 + (px-1)->g / 4 + (px+rgb->width)->g / 4 + (px+rgb->width-1)->g / 4;
            px2->b = px->b / 4 + (px-1)->b / 4 + (px+rgb->width)->b / 4 + (px+rgb->width-1)->b / 4;
        }
        else if (count == rgb->size - rgb->width)
        {
            px2->r = px->r / 4 + (px+1)->r / 4 + (px-rgb->width)->r / 4 + (px-rgb->width+1)->r / 4;
            px2->g = px->g / 4 + (px+1)->g / 4 + (px-rgb->width)->g / 4 + (px-rgb->width+1)->g / 4;
            px2->b = px->b / 4 + (px+1)->b / 4 + (px-rgb->width)->b / 4 + (px-rgb->width+1)->b / 4;
        }
        else if (count == rgb->size)
        {
            px2->r = px->r / 4 + (px-1)->r / 4 + (px-rgb->width)->r / 4 + (px-rgb->width-1)->r / 4;
            px2->g = px->g / 4 + (px-1)->g / 4 + (px-rgb->width)->g / 4 + (px-rgb->width-1)->g / 4;
            px2->b = px->b / 4 + (px-1)->b / 4 + (px-rgb->width)->b / 4 + (px-rgb->width-1)->b / 4;
        }
        //linhas e colunas. vai buscar os 6 pixeis a volta
        else if (count < rgb->width)
        {
            px2->r = (px-1)->r / 6 + px->r / 6 + (px+1)->r / 6 + (px+rgb->width-1)->r / 6 + (px+rgb->width)->r / 6 + (px+rgb->width+1)->r / 6;
            px2->g = (px-1)->g / 6 + px->g / 6 + (px+1)->g / 6 + (px+rgb->width-1)->g / 6 + (px+rgb->width)->g / 6 + (px+rgb->width+1)->g / 6;
            px2->b = (px-1)->b / 6 + px->b / 6 + (px+1)->b / 6 + (px+rgb->width-1)->b / 6 + (px+rgb->width)->b / 6 + (px+rgb->width+1)->b / 6;
        }
        else if (count > rgb->size - rgb->width && count < rgb->size)
        {
            px2->r = (px-1)->r / 6 + px->r / 6 + (px+1)->r / 6 + (px-rgb->width-1)->r / 6 + (px-rgb->width)->r / 6 + (px-rgb->width+1)->r / 6;
            px2->g = (px-1)->g / 6 + px->g / 6 + (px+1)->g / 6 + (px-rgb->width-1)->g / 6 + (px-rgb->width)->g / 6 + (px-rgb->width+1)->g / 6;
            px2->b = (px-1)->b / 6 + px->b / 6 + (px+1)->b / 6 + (px-rgb->width-1)->b / 6 + (px-rgb->width)->b / 6 + (px-rgb->width+1)->b / 6;
        }
        else if ((count-1) % rgb->width == 0 )
        {
            px2->r = (px-rgb->width)->r / 6 + (px-rgb->width+1)->r / 6 + px->r / 6 + (px+1)->r / 6 + (px+rgb->width)->r / 6 + (px+rgb->width+1)->r / 6;
            px2->g = (px-rgb->width)->g / 6 + (px-rgb->width+1)->g / 6 + px->g / 6 + (px+1)->g / 6 + (px+rgb->width)->g / 6 + (px+rgb->width+1)->g / 6;
            px2->b = (px-rgb->width)->b / 6 + (px-rgb->width+1)->b / 6 + px->b / 6 + (px+1)->b / 6 + (px+rgb->width)->b / 6 + (px+rgb->width+1)->b / 6;
        }
        else if (count % rgb->width == 0 )
        {
            px2->r = (px-rgb->width-1)->r / 6 + (px-rgb->width)->r / 6 + (px-1)->r / 6 + px->r / 6 + (px+rgb->width-1)->r / 6 + (px+rgb->width)->r / 6;
            px2->g = (px-rgb->width-1)->g / 6 + (px-rgb->width)->g / 6 + (px-1)->g / 6 + px->g / 6 + (px+rgb->width-1)->g / 6 + (px+rgb->width)->g / 6;
            px2->b = (px-rgb->width-1)->b / 6 + (px-rgb->width)->b / 6 + (px-1)->b / 6 + px->b / 6 + (px+rgb->width-1)->b / 6 + (px+rgb->width)->b / 6;
        }
        //pixeis no centro da imagem
        else
        {
            px2->r = (px-rgb->width-1)->r / 9 + (px-rgb->width)->r / 9 + (px-rgb->width+1)->r / 9 + (px-1)->r / 9 + px->r / 9 + (px+1)->r / 9 + (px+rgb->width-1)->r / 9 + (px+rgb->width)->r / 9 + (px+rgb->width+1)->r / 9;
            px2->g = (px-rgb->width-1)->g / 9 + (px-rgb->width)->g / 9 + (px-rgb->width+1)->g / 9 + (px-1)->g / 9 + px->g / 9 + (px+1)->g / 9 + (px+rgb->width-1)->g / 9 + (px+rgb->width)->g / 9 + (px+rgb->width+1)->g / 9;
            px2->b = (px-rgb->width-1)->b / 9 + (px-rgb->width)->b / 9 + (px-rgb->width+1)->b / 9 + (px-1)->b / 9 + px->b / 9 + (px+1)->b / 9 + (px+rgb->width-1)->b / 9 + (px+rgb->width)->b / 9 + (px+rgb->width+1)->b / 9;
        }
        
        count++;
        px++;
        px2++;
        
    }
    
    saveFileRGB(rgbfil, name);
}
