#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <cfloat>
#include <cmath>
#include <iostream>

class S21Matrix {
 private:
  // attributes
  int rows_, cols_;  // rows and columns attributes
  double** matrix_;  // pointer to the memory where the matrix will be allocated

  // resize is for setCols and setRows method
  void resize(int newRows, int newCols);

 public:
  S21Matrix();                    // default constructor
  S21Matrix(int rows, int cols);  // parameterized constructor
  S21Matrix(const S21Matrix& o);  // copy constructor
  S21Matrix(S21Matrix&& o);       // move constructor
  ~S21Matrix();                   // destructor

  // some operators overloads
  S21Matrix operator+(const S21Matrix& o);
  S21Matrix operator-(const S21Matrix& o);
  S21Matrix operator*(const S21Matrix& o);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& o);
  void operator=(const S21Matrix& o);  // assignment operator overload
  void operator+=(const S21Matrix& o);
  void operator-=(const S21Matrix& o);
  void operator*=(const S21Matrix& o);
  void operator*=(const double num);
  double& operator()(int row, int col);  // index operator overload

  // some public methods
  bool EqMatrix(const S21Matrix& o);
  void SumMatrix(const S21Matrix& o);
  void SubMatrix(const S21Matrix& o);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& o);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // accessors and mutators
  int getRows() const;
  int getCols() const;

  void setRows(int newRows);
  void setCols(int newCols);

  // support functions
  // void print();
  S21Matrix getMinor(int row, int col);
};

#endif