
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

void saveFileGS(MatrixGS *gs, char *name);
