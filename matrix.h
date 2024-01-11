#include <iostream>

class Matrix {
protected:
	int rows;
	int cols;
	double** elements;

public:
	Matrix(int rows = 5, int cols = 5);
	Matrix(const Matrix& other);
	~Matrix();

	Matrix& operator=(const Matrix& other);

	void set(int rows, int cols, double element);
	int getRows() const;
	int getCols() const;
	double getElement(int rows, int cols) const;

	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator*(double num) const;
	Matrix operator*(const Matrix& other) const;

	Matrix transpose() const;

	friend std::istream& operator>>(std::istream& in, Matrix& matrix);
	friend std::ostream& operator<<(std::ostream& out, Matrix& matrix);
};

// Частный случай 
class QMatrix : public Matrix {
public:
	QMatrix(int size);
	QMatrix(const Matrix& other);
	QMatrix inverse() const;
	double determinant() const;
	QMatrix submatrix(int row, int col) const;
	QMatrix adjoint() const;
};