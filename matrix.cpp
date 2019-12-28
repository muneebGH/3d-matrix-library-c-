#include"matrix.h"
void createMatrix(int *** m, int row, int col) {
	*m = new int *[row];
	for (int i = 0; i < row; i++) {
		*m[i] = new int[col];
	}

}

void printMatrix(int *** p, int col, int row) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << *p[i][j];
		}
		cout << "\n";
	}
}
int isIdentity(int *** p, int col, int row) {
	//returns one if set is identity , returns zero if set isnt identity 
	int zeros = 0;
	int ones = 0;
	int num;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			num = *p[i][j];
			if (i == j && num == 1) {
				ones++;
			}
			if (i != j && num == 0) {
				zeros++;
			}
		}
	}
	int z = (row*col) - row;
	if (ones == row && zeros == z) {
		return 1;
	}
	else {
		return 0;
	}

}


bool isLowerTriangle(int ***p, int col, int row) {
	int counter = 0;
	int zeros = 0;
	int ones = 0;
	int num;
	int check = 1;
	int check_2;

	for (int i = 0; i < row; i++) {


		for (int j = 0; j < col; j++) {
			num = *p[i][j];
			if (num == 0) {
				zeros++;
			}
			if (num != 0) {
				ones++;
			}
		}
		check_2 = col - check;
		if (ones == check && zeros == check_2) {
			counter++;
		}
		check++;

	}

	if (counter == row) {
		return true;
	}
	else {
		return false;
	}
}



bool isUpperTriangle(int ***p, int col, int row) {
	int counter = 0;
	int zeros = 0;
	int ones = 0;
	int num;
	int check = col;
	int check_2;

	for (int i = 0; i < row; i++) {


		for (int j = 0; j < col; j++) {
			num = *p[i][j];
			if (num == 0) {
				zeros++;
			}
			if (num != 0) {
				ones++;
			}
		}
		check_2 = col - check;
		if (ones == check && zeros == check_2) {
			counter++;
		}
		check--;

	}

	if (counter == row) {
		return true;
	}
	else {
		return false;
	}
}





int ** getMatrixCopy(int *** p, int col, int row) {

	int ** copy;
	createMatrix(&copy, row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			copy[i][j] = *p[i][j];
		}

	}


	return copy;
}





bool isEqual(int ***a, int row1, int col1, int *** b, int row2, int col2) {

	if (row1 != row2 || col1 != col2) {
		return false;
	}

	int total = 0;


	for (int i = 0; i < row1; i++) {

		for (int j = 0; j < col1; j++) {

			if (*a[i][j] == *b[i][j]) {
				total++;
			}
		}
	}

	int totalSize = 0;
	totalSize = row1 * col1;
	if (total == totalSize) {
		return true;
	}
	else {
		return false;
	}
}




void freeMatrix(int *** p, int col, int row) {

	for (int i = 0; i < row; i++) {

		delete[] * p[i];

	}
	p=0;
}




int ** transpose(int *** p, int col, int row) {

	int **transpose;
	createMatrix(&transpose, row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			transpose[i][j] = *p[j][i];
		}
	}
	return transpose;
}



void reSize(int ***p, int col, int row, int newCol, int newRow)
{
	int ** newMat;
	createMatrix(&newMat, row, col);
	
	
	for (int i = 0; i < newRow; i = i + 1)
	{
		for (int j = 0; j < newCol; j = j + 1)
		{
			newMat[i][j] = *p[i][j];
		}
	}

	delete[] * p;

	*p = getMatrixCopy(&newMat, newCol, newRow);

	delete[]newMat;
}


bool isSymmetric(int ** p, int row, int col)
{

	int ** newMat;
	createMatrix(&newMat, row, col);
	newMat = transpose(&p, col, row);
	bool check = isEqual(&p, row, col, &newMat, row, col);
	if (check==true)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool isSkewSymmetric(int **p, int row, int col)
{


	int ** newMat;
	createMatrix(&newMat, row, col);
	newMat = transpose(&p, col, row);
	bool check = isEqualForSkew(&p, row, col, &newMat, row, col);
	if (check == true)
	{
		return true;
	}
	else
	{
		return false;
	}


}



bool isEqualForSkew(int ***a, int row1, int col1, int *** b, int row2, int col2) {

	if (row1 != row2 || col1 != col2) {
		return false;
	}

	int total = 0;


	for (int i = 0; i < row1; i++) {

		for (int j = 0; j < col1; j++) {

			if (*a[i][j] == -(*b[i][j])) {
				total++;
			}
		}
	}

	int totalSize = 0;
	totalSize = row1 * col1;
	if (total == totalSize) {
		return true;
	}
	else {
		return false;
	}
}



int ** addMatrix(int **a, int col1, int row1, int **b, int col2, int row2)
{
	int counter = 0;
	if (col1 == col2)
	{
		counter = counter + 1;
	}
	if (row1 == row2)
	{
		counter = counter + 1;
	}

	if (counter != 2)
	{
		cout << "cannot be added " << endl;
		exit(0);
	}

	int ** add;
	createMatrix(&add, row1, col1);
	for (int i = 0; i < row1; i = i + 1)
	{
		for (int j = 0; j < col1; j = j + 1)
		{
			add[i][j] = a[i][j] + b[i][j];
		}
	}

	return add;


}




















