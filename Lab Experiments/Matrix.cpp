//Prepared by : Ansh Kushwaha
#include <iostream>
using namespace std;

void add(int* mat1, int* mat2, int *mat3, int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			*(mat3+(i*n+j)) = *(mat1+(i*n+j)) + *(mat2+(i*n+j));
		}
	}
}

int trace(int *mat, int n) {
	int res = 0;
	for(int i = 0; i < n; i++) {
		res += *(mat+(i*n+i));
	}
	return res;
}

void multiply(int* mat1, int* mat2, int* mat3, int m1, int n1) {
	for(int i = 0; i < m1; i++) {
		for(int j = 0; j < m1; j++) {
			int res = 0;
			for(int k = 0; k < n1; k++) {
				res += *(mat1+i*n1+k) * *(mat2+k*m1+j);
			}
			*(mat3+i*m1+j) = res;
		}
	}
}

int main() {
	int n;
	cout << "Enter order of matrix : ";
	cin >> n;
	int matrix1[n][n];
	int matrix2[n][n];
	int matrix3[n][n];
	for(int i = 0; i < n; i++) {
		cout << "Enter row " << i+1 << " of first matrix : ";
		for(int j = 0; j < n; j++) {
			cin >> matrix1[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		cout << "Enter row " << i+1 << " of second matrix : ";
		for(int j = 0; j < n; j++) {
			cin >> matrix2[i][j];
		}
	}

	add(&matrix1[0][0], &matrix2[0][0], &matrix3[0][0], n, n);
	cout << "The addition of the two matrices : \n";
	for(int i = 0; i < n; i++) {
		cout << "\t";
		for(int j = 0; j < n; j++) {
			cout << matrix3[i][j] << " ";
		}
		cout << endl;
	}

	multiply(&matrix1[0][0], &matrix2[0][0], &matrix3[0][0], n, n);
	cout << "The multiplication of the two matrices : \n";
	for(int i = 0; i < n; i++) {
		cout << "\t";
		for(int j = 0; j < n; j++) {
			cout << matrix3[i][j] << " ";
		}
		cout << endl;
	}
	cout << trace(&matrix1[0][0], n) << endl;
	return 0;
}