#include "imageGS.h"
#include "imageBi.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * Creates a matrix and allocates memory to store the pixels of a pgm image
 * 
 * @param rows The number of rows of pixels of the image
 * @param columns The number of columns of pixels of the image
*/
MatrixGS * createMatrixGS(int rows, int columns)
{
    MatrixGS *gs;

    gs = (MatrixGS*)malloc(sizeof(MatrixGS));
    gs->width=rows;
    gs->height=columns;

    gs->size = rows*columns;
    
    gs->data = (ImageGS *)calloc(gs->size, sizeof(char));

    return gs;
}

/**
 * Loads a pgm format image
 * 
 * @param name Name of the image file
 */
MatrixGS * loadFileGS(char *name)
{
    FILE *fp = fopen(name, "rb");
    if (!fp) {
        fprintf(stderr, "Unable to open file '%s'\n", name);
        exit(1);
    }
    
    int width, height, max_color;
    char buffer[10];

	fgets(buffer, sizeof(buffer), fp);
    if (buffer[0] != 'P' || buffer[1] != '5') {
         fprintf(stderr, "Invalid image format (must be 'P5')\n");
         exit(1);
    }
	fscanf(fp, "%d %d", &width, &height);
	
    fscanf(fp, "%d", &max_color);
    fgets(buffer, sizeof(buffer), fp);

    MatrixGS *gs = createMatrixGS(width, height);
    fread(gs->data, gs->width, gs->height, fp);

    return gs;
}

/**
 * Saves a file in the pgm format
 * 
 * @param gs Matrix of pixels to be saved in pgm format
 * @param name Name of the file in which the matrix will be stored
 */
void saveFileGS(MatrixGS *gs, char *name)
{
    FILE *fp = fopen(name, "wb");

    fprintf(fp, "P5\n");
    fprintf(fp, "%d %d\n", gs->width,gs->height);
    fprintf(fp, "%d\n",255);

    fwrite(gs->data, gs->width,gs->height, fp);
}

/**
 * Converts a pgm format image into a pbm image
 * 
 * @param gs Matrix of pixels that will be converted into pbm format
 * @param nome Name of the file in which the new image will be stored
 */
void gray2bin(MatrixGS * gs, int tsh, char * name)
{
    ImageGS * px = gs->data;

    MatrixGS * bi = createMatrixGS(gs->width, gs->height);
    ImageGS * px2 = bi->data;

    for(int i = 0; i < bi->size; i++){
        
        if(px->g < tsh){
            px2->g=0;
            
        }else
        {
            px2->g=255; 
        }
       
        px++;
        px2++;
    }

    saveFileGS(bi, name);
}

/**
 * Changes the intensity of a pgm image
 * 
 * @param gs Matrix of pixels
 * @param inten Value to be added to each pixel in order to change the intensity of the image
 * @param name Name of the file in which the new image will be stored
 */
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

/**
 * Applies a filter to a pgm image
 * 
 * @param gs Matrix of pixels
 * @param name Name of the file in which the new image will be stored
 */
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

/**
 * Applies a watermark to a grayscale image
 * 
 * @param gs Matrix of pixels
 * @param name Name of the file in which the new image with the watermark will be stored
 */
void watermarkGS(MatrixGS* gs, char* name){
    ImageGS * px = gs->data;

    MatrixGS * wt = loadFileGS("../res/watermark/watermark.pgm");
    ImageGS * px2 = wt->data;
    int altura=0;
    int largura=0;

    for(int i = 0; i < gs->size; i++){
        
        if (gs->height - altura <= wt->height && gs->width - largura <= wt->width ){
            if(px2->g == 0){
                px->g = px->g * 0.55 + px2->g * 0.45;
            }
            px2++;
        }

        largura++;
        if(largura == gs->width){
            largura = 0;
            altura++;
        }
        px++;
    }
    
    saveFileGS(gs, name);
}
