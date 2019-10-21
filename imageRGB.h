#ifndef INC_00_IMAGERGB_H
#define INC_00_IMAGERGB_H

typedef struct{
	unsigned char r,g,b;
}ImageRGB;

typedef struct {
    ImageRGB *data;
    int n;
    int width, height;
    int size;
} Matrix;

Matrix * CreateMat(int rows, int columns);

Matrix * LoadFromFile(char *);

void SaveOnFile(Matrix *v, char *name);

void PrintMat(Matrix * dm);

void PrintRGB(ImageRGB * px);

#endif //INC_00_IMAGERGB_H
