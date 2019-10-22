
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