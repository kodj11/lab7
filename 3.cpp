#include "matrix.h"
#include <iostream>

int main(void) {

	Matrix matrix(3, 3);
	
	std::cout << "Matrix(" << matrix.getCols() << "," << matrix.getRows() << ")" << std::endl;
	std::cout << "Enter elements: " << std::endl;
	std::cin >> matrix;
	std::cout << "Yout matrix: " << std::endl << matrix;

	QMatrix	qmatrix(matrix);
	QMatrix	qmatrix2(matrix);
	QMatrix	qmatrix3(matrix);
	std::cout << "QMatrix from Matrix: " << std::endl << qmatrix;
	QMatrix inverse = qmatrix3.inverse();
	std::cout << "Inverse QMatrix: " << std::endl << inverse << std::endl;
	//qmatrix = qmatrix * inverse;
	//std::cout << "QMatrix * Inverse_QMatrix: " << std::endl << qmatrix << std::endl;
	std::cout << "Determinant QMatrix = " << qmatrix.determinant() << std::endl;
	qmatrix2 = qmatrix.transpose();
	std::cout << "Transpose QMatrix = " << std::endl << qmatrix2 << std::endl;
	qmatrix = qmatrix * 5.1;
	std::cout << "QMatrix * 5.1: " << std::endl << qmatrix << std::endl;
	qmatrix = qmatrix * matrix;
	std::cout << "QMatrix * 5.1 * matrix: " << std::endl << qmatrix << std::endl;
	
	return 000;
}