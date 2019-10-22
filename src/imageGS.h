
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

void color2bin(MatrixGS * gs, char * tsh, char * name);
