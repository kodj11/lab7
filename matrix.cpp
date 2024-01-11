#include "matrix.h"
#include <cmath>
#include <iostream>

// ����������� �� ��������� � Matrix
Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    elements = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        elements[i] = new double[cols];
    }
}

// ����������� ����������� Matrix 
Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;

    elements = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        elements[i] = new double[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            elements[i][j] = other.elements[i][j];
        }
    }
}

// ��������� Matrix
Matrix::~Matrix() {
    // ����������� ���������� ������
    for (int i = 0; i < rows; ++i) {
        delete[] elements[i];
    }
    delete[] elements;
}

// ������� ����� protected
int Matrix::getCols() const {
    return this->cols;
}
int Matrix::getRows() const {
    return this->rows;
}
double Matrix::getElement(int rows, int cols) const {
    return elements[rows][cols];
}
void Matrix::set(int rows, int cols, double element) {
    this->elements[rows][cols] = element;
}

// �������� ������������ ��� Matrix
Matrix& Matrix::operator=(const Matrix& other) {
    this->~Matrix();
    rows = other.rows;
    cols = other.cols;

    elements = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        elements[i] = new double[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            elements[i][j] = other.elements[i][j];
        }
    }

    return *this;
}
// �������� ������
// �������� ����� �������
Matrix Matrix::operator+(const Matrix& other) const {
    // ��������� ���������� ��������
    if (rows != other.rows || cols != other.cols) {
        throw "������� ������ �� ���������";
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.elements[i][j] = elements[i][j] + other.elements[i][j];
        }
    }

    return result;
}
// ��������� ������
// �������� ����� �������
Matrix Matrix::operator-(const Matrix& other) const {
    // ��������� ���������� ��������
    if (rows != other.rows || cols != other.cols) {
        throw "������� ������ �� ���������";
    }

    Matrix result(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.elements[i][j] = elements[i][j] - other.elements[i][j];
        }
    }

    return result;
}
// ��������� �� �����
// �������� ����� �������
Matrix Matrix::operator*(double num) const {
    Matrix result(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.set(i, j, elements[i][j] * num);
        }
    }

    return result;
}
Matrix Matrix::operator*(const Matrix& other) const {

    if (cols != other.rows) {
        throw "������� ������ ������������";
    }

    Matrix result(rows, other.cols);

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            double sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += elements[i][k] * other.elements[k][j];
            }
            result.elements[i][j] = sum;
        }
    }

    return result;
}

// ����� ���������������� �������
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.elements[j][i] = elements[i][j];
        }
    }

    return result;
}

std::istream& operator>>(std::istream& in, Matrix& matrix) {
    // ��������� �������� �������
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            in >> matrix.elements[i][j];
        }
    }

    return in;
}
std::ostream& operator<<(std::ostream& out, Matrix& matrix) {
    // ��������� �������� �������
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            out << matrix.elements[i][j] << " ";
        }
        out << std::endl;
    }

    return out;
}


// QMatrix

// ����������� �� ��������� � QXatrix
QMatrix::QMatrix(int size) : Matrix(size, size) { }
// ����������� ��� ������ ������
QMatrix::QMatrix(const Matrix& other) { 
    // ���� ����������
    if (other.getCols() > other.getRows()) {
        rows = other.getRows();
        cols = other.getRows();
    }
    else {
        rows = other.getCols();
        cols = other.getCols();
    }
    this->elements = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        this->elements[i] = new double[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            this->elements[i][j] = other.getElement(i, j);
        }
    }
}

double QMatrix::determinant() const {

    // ������� ������ ���� ����������
    if (rows != cols) {
        throw "������� ������ ���� ����������";
    }

    double det = 0;

    if (rows == 1) {
        // ������������ 1x1 ������� - �� ������������ �������
        det = elements[0][0];
    }
    else if (rows == 2) {
        // ������������ 2x2 �������
        det = elements[0][0] * elements[1][1] -
            elements[0][1] * elements[1][0];
    }
    else {
        // ������������ mxm �������
        for (int i = 0; i < rows; i++) {
            // ���������� �������� determinant �� ����������
            det += pow(-1, i) * elements[0][i] * submatrix(0, i).determinant();
        }
    }

    return det;
}

QMatrix QMatrix::submatrix(int row, int col) const {

    // ������� ����������
    int subRow = rows - 1;
    int subCol = cols - 1;

    // ������� ����������
    Matrix subMat(subRow, subCol);

    // �������� �������� �������� �������, 
    // ��������� ��������� ������ � �������
    for (int i = 0; i < subRow; i++) {
        for (int j = 0; j < subCol; j++) {
            // ��������� ������� ��������� ����������
            int indexI = i < row ? i : i + 1;
            int indexJ = j < col ? j : j + 1;

            subMat.set(i, j, elements[indexI][indexJ]);
        }
    }

    return subMat;
}

QMatrix QMatrix::inverse() const {
    double det = this->determinant();

    QMatrix adj = adjoint();

    QMatrix inverse(rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            inverse.elements[i][j] = adj.elements[i][j] / det;
        }
    }

    return inverse;
}

QMatrix QMatrix::adjoint() const {
    QMatrix adj(rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            QMatrix sub = submatrix(i, j);

            double det = sub.determinant();

            adj.elements[j][i] = pow(-1, i + j) * det;
        }
    }

    return adj;
}