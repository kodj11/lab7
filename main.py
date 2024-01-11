import numpy as np

class Matrix:
    def __init__(self, rows=0, cols=0):
        self._matrix = np.zeros((rows, cols))
        self._rows = rows
        self._cols = cols
    
    def __add__(self, other):
        if self._rows != other._rows or self._cols != other._cols:
            raise ValueError("Матрицы не равны. Их сумма не возможна!")
        result = Matrix(self._rows, self._cols)
        result._matrix = self._matrix + other._matrix
        return result
    
    def __sub__(self, other):
        if self._rows != other._rows or self._cols != other._cols:
            raise ValueError("Разница невозможна! Не выыполняется условие равенства соответствующих параметров матриц.")  
        result = Matrix(self._rows, self._cols)
        result._matrix = self._matrix - other._matrix
        return result
    
    def __mul__(self, other):
        if isinstance(other, Matrix):
            if self._cols != other._rows:
                raise ValueError("Умножение невозможно! Не выыполняется условие равенства соответствующих параметров матриц.")
            result = Matrix(self._rows, other._cols)
            result._matrix = self._matrix @ other._matrix
        else:
            result = Matrix(self._rows, self._cols)
            result._matrix = self._matrix * other
        return result
    
    def transpose(self):
        result = Matrix(self._cols, self._rows)
        result._matrix = self._matrix.transpose() 
        return result

    def __copy__(self):
        cls = self.__class__
        result = cls.__new__(cls)
        result.__dict__.update(self.__dict__)
        return result

    def __deepcopy__(self, memo):
        cls = self.__class__
        result = cls.__new__(cls)
        memo[id(self)] = result
        for k, v in self.__dict__.items():
            setattr(result, k, deepcopy(v, memo))
        return result

    def input(self):
        print(f"Введите матрицу ({self._rows}, {self._cols}):")
        matrix = []
        for i in range(self._rows):
            row = list(map(float, input().split())) 
            if len(row) != self._cols:
                raise ValueError("Invalid row length")
            matrix.append(row)
        self._matrix = np.array(matrix)

    def display(self):
        for row in self._matrix:
            print([round(x, 2) for x in row])
        
class QMatrix(Matrix):
    def determinant(self):
        return np.linalg.det(self._matrix)
    
    def inverse(self):
        if self.determinant() == 0:
            raise ValueError("Определитель равен 0. Обратную матрицу не получить!")
        result = QMatrix(self._rows, self._cols)
        result._matrix = np.linalg.inv(self._matrix)
        return result

matrix = Matrix(3,3)
matrix.input()
transpose = matrix.transpose()
print("Транспонированная матрицап:")
transpose.display()
add_matrix = matrix + transpose
print("Суммая matrix + transpose:")
add_matrix.display()
umn = matrix * 5
print("matrix * 5:")
umn.display()
qmatrix = QMatrix(3,3)
print("QMatrix")
qmatrix.input()
try:
    inverse = qmatrix.inverse()
    print("Обратная матрица:")
    inverse.display()
except Exception as e:
    print(e)




