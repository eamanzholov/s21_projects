#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 2;
  cols_ = 2;
  matrix_ = NULL;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0.0;
    }
  }
}

S21Matrix::S21Matrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0.0;
    }
  }
}

S21Matrix::S21Matrix(const S21Matrix& o) {
  rows_ = o.rows_;
  cols_ = o.cols_;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = o.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& o) {
  rows_ = o.rows_;
  cols_ = o.cols_;
  matrix_ = o.matrix_;

  o.matrix_ = nullptr;
  o.rows_ = 0;
  o.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
      matrix_[i] = nullptr;
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
  rows_ = 0;
  cols_ = 0;
}

// some operators overloads
S21Matrix S21Matrix::operator+(const S21Matrix& o) {
  S21Matrix result(*this);
  result.SumMatrix(o);
  return result;
}
S21Matrix S21Matrix::operator-(const S21Matrix& o) {
  S21Matrix result(*this);
  result.SubMatrix(o);
  return result;
}
S21Matrix S21Matrix::operator*(const S21Matrix& o) {
  S21Matrix result(*this);
  result.MulMatrix(o);
  return result;
}
S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}
bool S21Matrix::operator==(const S21Matrix& o) { return EqMatrix(o); }
void S21Matrix::operator=(const S21Matrix& o) {
  setRows(o.rows_);
  setCols(o.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = o.matrix_[i][j];
    }
  }
}
void S21Matrix::operator+=(const S21Matrix& o) { SumMatrix(o); }
void S21Matrix::operator-=(const S21Matrix& o) { SubMatrix(o); }
void S21Matrix::operator*=(const S21Matrix& o) { MulMatrix(o); }
void S21Matrix::operator*=(const double num) { MulNumber(num); }
double& S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Indexes outside the matrix");
  }
  return matrix_[row][col];
}

// some public methods
bool S21Matrix::EqMatrix(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_ || rows_ <= 0 || cols_ <= 0) {
    return false;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs(matrix_[i][j] - o.matrix_[i][j]) > 1.e-7) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::out_of_range(
        "Incorrect input, matrices should have positive rows and cols size");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (matrix_[i][j] + o.matrix_[i][j] > DBL_MAX ||
          matrix_[i][j] + o.matrix_[i][j] < -DBL_MAX) {
        throw std::overflow_error("Overflow");
      }
      matrix_[i][j] += o.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::out_of_range(
        "Incorrect input, matrices should have positive rows and cols size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (matrix_[i][j] - o.matrix_[i][j] > DBL_MAX ||
          matrix_[i][j] - o.matrix_[i][j] < -DBL_MAX) {
        throw std::overflow_error("Overflow");
      }
      matrix_[i][j] -= o.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::out_of_range(
        "Incorrect input, matrices should have positive rows and cols size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (matrix_[i][j] * num > DBL_MAX || matrix_[i][j] * num < -DBL_MAX) {
        throw std::overflow_error("Overflow");
      }
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& o) {
  if (cols_ != o.rows_) {
    throw std::out_of_range(
        "Incorrect input, cols of matrix not equil rows of other matrix");
  }
  S21Matrix temp(rows_, o.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < o.cols_; j++) {
      temp.matrix_[i][j] = 0;
      for (int k = 0; k < cols_; k++) {
        if (temp.matrix_[i][j] + matrix_[i][k] * o.matrix_[k][j] < -DBL_MAX ||
            temp.matrix_[i][j] + matrix_[i][k] * o.matrix_[k][j] > DBL_MAX) {
          throw std::overflow_error("Overflow");
        } else {
          temp.matrix_[i][j] += matrix_[i][k] * o.matrix_[k][j];
        }
      }
    }
  }

  setCols(o.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < o.cols_; j++) {
      matrix_[i][j] = temp.matrix_[i][j];
    }
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}
S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::invalid_argument(
        "Matrix must be square to calculate complements");
  }

  S21Matrix complements(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor = getMinor(i, j);
      double determinant = minor.Determinant();
      complements(i, j) = std::pow(-1, i + j) * determinant;
    }
  }

  return complements;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::invalid_argument(
        "Matrix must be square to calculate determinant");
  }

  // Base case for 1x1 matrix
  if (rows_ == 1) {
    return matrix_[0][0];
  }

  // Base case for 2x2 matrix
  if (rows_ == 2) {
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  }

  double determinant = 0.0;
  for (int j = 0; j < cols_; j++) {
    S21Matrix minor = getMinor(0, j);
    determinant += (j % 2 == 0 ? 1 : -1) * matrix_[0][j] * minor.Determinant();
  }

  return determinant;
}
S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (det == 0) {
    throw std::invalid_argument(
        "Matrix is not invertible because its determinant is zero");
  }

  S21Matrix complements = CalcComplements();
  S21Matrix adjugate(complements.getCols(), complements.getRows());

  for (int i = 0; i < complements.getRows(); i++) {
    for (int j = 0; j < complements.getCols(); j++) {
      adjugate(j, i) =
          complements(i, j);  // Transpose the matrix of complements
    }
  }

  S21Matrix inverse(adjugate.getRows(), adjugate.getCols());
  for (int i = 0; i < adjugate.getRows(); i++) {
    for (int j = 0; j < adjugate.getCols(); j++) {
      inverse(i, j) = adjugate(i, j) / det;
    }
  }

  return inverse;
}

// accessors and mutators
int S21Matrix::getRows() const { return S21Matrix::rows_; }
int S21Matrix::getCols() const { return S21Matrix::cols_; }

void S21Matrix::setRows(int newRows) { resize(newRows, cols_); }
void S21Matrix::setCols(int newCols) { resize(rows_, newCols); }

void S21Matrix::resize(int newRows, int newCols) {
  double** newMatrix = new double*[newRows];
  for (int i = 0; i < newRows; i++) {
    newMatrix[i] = new double[newCols];
  }
  for (int i = 0; i < newRows; i++) {
    for (int j = 0; j < newCols; j++) {
      if (i < rows_ && j < cols_) {
        newMatrix[i][j] = matrix_[i][j];
      } else {
        newMatrix[i][j] = 0.0;
      }
    }
  }
  S21Matrix::~S21Matrix();
  matrix_ = newMatrix;
  rows_ = newRows;
  cols_ = newCols;
}

S21Matrix S21Matrix::getMinor(int row, int col) {
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0, minor_i = 0; i < rows_; i++) {
    if (i == row) continue;
    for (int j = 0, minor_j = 0; j < cols_; j++) {
      if (j == col) continue;
      minor(minor_i, minor_j) = matrix_[i][j];
      minor_j++;
    }
    minor_i++;
  }
  return minor;
}