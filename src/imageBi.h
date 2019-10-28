#ifndef INC_00_IMAGEBIN_H
#define INC_00_IMAGEBIN_H

typedef struct{
    unsigned char b;
}ImageBi;

typedef struct {
    ImageBi *data;
    int n;
    int width, height;
    int size;
} MatrixBi;

MatrixBi * createMatrixBi(int rows, int columns);

MatrixBi * loadFileBi(char *name);

void saveFileBi(MatrixBi *bi, char *name);

#endif //INC_00_IMAGEBIN_H