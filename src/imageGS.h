#ifndef INC_00_IMAGEGS_H
#define INC_00_IMAGEGS_H

typedef struct{
    unsigned char g;
}ImageGS;

typedef struct {
    ImageGS *data;
    int n;
    int width, height;
    int size;
} MatrixGS;

MatrixGS * createMatrixGS(int rows, int columns);

MatrixGS * loadFileGS(char *name);

void saveFileGS(MatrixGS *gs, char *name);

void gray2bin(MatrixGS * gs, char * tsh, char * name);

void intensityGS(MatrixGS *gs, char inten, char *name);

#endif //INC_00_IMAGEGS_H