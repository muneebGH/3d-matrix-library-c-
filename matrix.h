#include<iostream>
using namespace std;
void createMatrix(int *** m, int row, int col);
void printMatrix(int *** p, int col, int row);
int isIdentity(int *** p, int col, int row);
bool isLowerTriangle(int ***p, int col, int row);
void freeMatrix(int *** p, int col, int row);
bool isEqual(int ***a, int row1, int col1, int *** b, int row2, int col2);
void reSize(int ***p, int col, int row, int newcol, int newrow);

int ** getMatrixCopy(int *** p, int col, int row);

int ** transpose(int *** p, int col, int row);
bool isEqualForSkew(int ***a, int row1, int col1, int *** b, int row2, int col2);
bool isSkewSymmetric(int **p, int row, int col);
int ** addMatrix(int **a, int col1, int row1, int **b, int col2, int row2);
