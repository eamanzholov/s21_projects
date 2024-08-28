#include <gtest/gtest.h>

#include <stdexcept>

#include "s21_matrix_oop.h"

TEST(Constructor, def_const) {
  S21Matrix test_mat;
  EXPECT_EQ(2, test_mat.getRows());
  EXPECT_EQ(2, test_mat.getCols());
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_DOUBLE_EQ(0, test_mat(i, j));
    }
  }
}

TEST(Constructor, second_copy_const) {
  S21Matrix test_mat(3, 3);
  S21Matrix test_mat_2(test_mat);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(0, test_mat(i, j));
    }
  }
}

TEST(Constructor, move_const) {
  S21Matrix test_mat(3, 3);
  S21Matrix test_mat_2(std::move(test_mat));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(0, test_mat_2(i, j));
    }
  }
}

TEST(Operator, plus_oper) {
  S21Matrix test_mat(3, 3);
  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  S21Matrix test_mat_2(test_mat);

  test_mat_2 = test_mat + test_mat_2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(test_mat(i, j) * 2, test_mat_2(i, j));
    }
  }
}

TEST(Operator, minus_oper) {
  S21Matrix test_mat(3, 3);
  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  S21Matrix test_mat_2(test_mat);

  test_mat_2 = test_mat - test_mat_2;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(0, test_mat_2(i, j));
    }
  }
}

TEST(Operator, mult_matrix_oper) {
  S21Matrix test_mat(3, 3);
  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  S21Matrix test_mat_2(test_mat);

  test_mat_2 = test_mat * test_mat_2;

  EXPECT_DOUBLE_EQ(1244, test_mat_2(0, 0));
  EXPECT_DOUBLE_EQ(612, test_mat_2(0, 1));
  EXPECT_DOUBLE_EQ(1248, test_mat_2(0, 2));

  EXPECT_DOUBLE_EQ(27, test_mat_2(1, 0));
  EXPECT_DOUBLE_EQ(3749, test_mat_2(1, 1));
  EXPECT_DOUBLE_EQ(144, test_mat_2(1, 2));

  EXPECT_DOUBLE_EQ(-56, test_mat_2(2, 0));
  EXPECT_DOUBLE_EQ(-3360, test_mat_2(2, 1));
  EXPECT_DOUBLE_EQ(-159, test_mat_2(2, 2));
}

TEST(Operator, mult_number_oper) {
  S21Matrix test_mat(3, 3);
  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  S21Matrix test_mat_2(test_mat);

  test_mat_2 = test_mat * 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(test_mat(i, j) * 3, test_mat_2(i, j));
    }
  }
}

TEST(Operator, eq_oper) {
  S21Matrix test_mat(3, 3);
  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  S21Matrix test_mat_2(test_mat);

  EXPECT_TRUE(test_mat_2 == test_mat);
}

TEST(Operator, plus_eq_oper) {
  S21Matrix test_mat(3, 3);
  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  S21Matrix test_mat_2(test_mat);

  test_mat_2 += test_mat;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(test_mat(i, j) * 2, test_mat_2(i, j));
    }
  }
}

TEST(Operator, minus_eq_oper) {
  S21Matrix test_mat(3, 3);
  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  S21Matrix test_mat_2(test_mat);

  test_mat_2 -= test_mat;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(0, test_mat_2(i, j));
    }
  }
}

TEST(Operator, mult_matrix_eq_oper) {
  S21Matrix test_mat(3, 3);
  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  S21Matrix test_mat_2(test_mat);

  test_mat_2 *= test_mat;

  EXPECT_DOUBLE_EQ(1244, test_mat_2(0, 0));
  EXPECT_DOUBLE_EQ(612, test_mat_2(0, 1));
  EXPECT_DOUBLE_EQ(1248, test_mat_2(0, 2));

  EXPECT_DOUBLE_EQ(27, test_mat_2(1, 0));
  EXPECT_DOUBLE_EQ(3749, test_mat_2(1, 1));
  EXPECT_DOUBLE_EQ(144, test_mat_2(1, 2));

  EXPECT_DOUBLE_EQ(-56, test_mat_2(2, 0));
  EXPECT_DOUBLE_EQ(-3360, test_mat_2(2, 1));
  EXPECT_DOUBLE_EQ(-159, test_mat_2(2, 2));
}

TEST(Operator, mult_number_eq_oper) {
  S21Matrix test_mat(3, 3);
  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  S21Matrix test_mat_2(test_mat);

  test_mat_2 *= 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(test_mat(i, j) * 3, test_mat_2(i, j));
    }
  }
}

TEST(Operator, brackets_oper) {
  S21Matrix test_mat;
  EXPECT_THROW(test_mat(5, 2), std::out_of_range);
}

TEST(Function, eq_function) {
  S21Matrix test_mat;
  S21Matrix test_mat2(3, 3);
  EXPECT_FALSE(test_mat.EqMatrix(test_mat2));

  S21Matrix test_mat3;
  test_mat3(1, 1) = 2;
  EXPECT_FALSE(test_mat.EqMatrix(test_mat3));
}

TEST(Function, sum_function) {
  S21Matrix test_mat;
  S21Matrix test_mat2(3, 3);
  EXPECT_THROW(test_mat.SumMatrix(test_mat2), std::out_of_range);
  S21Matrix test_mat3(0, 0);
  S21Matrix test_mat4(0, 0);
  EXPECT_THROW(test_mat3.SumMatrix(test_mat4), std::out_of_range);
  test_mat.setCols(4);
  test_mat.setRows(4);
  test_mat2.setCols(4);
  test_mat2.setRows(4);
  test_mat(0, 0) = DBL_MAX - 1;
  test_mat2(0, 0) = DBL_MAX;
  EXPECT_THROW(test_mat.SumMatrix(test_mat2), std::overflow_error);
}

TEST(Function, sub_function) {
  S21Matrix test_mat;
  S21Matrix test_mat2(3, 3);
  EXPECT_THROW(test_mat.SubMatrix(test_mat2), std::out_of_range);
  S21Matrix test_mat3(0, 0);
  S21Matrix test_mat4(0, 0);
  EXPECT_THROW(test_mat3.SubMatrix(test_mat4), std::out_of_range);
  test_mat2.setCols(2);
  test_mat2.setRows(2);
  test_mat(0, 0) = -DBL_MAX - 1;
  test_mat2(0, 0) = DBL_MAX;
  EXPECT_THROW(test_mat.SubMatrix(test_mat2), std::overflow_error);
}

TEST(Function, mul_number_function) {
  S21Matrix test_mat;
  S21Matrix test_mat3(0, 0);
  EXPECT_THROW(test_mat3.MulNumber(4), std::out_of_range);
  test_mat(0, 0) = -DBL_MAX - 1;
  EXPECT_THROW(test_mat.MulNumber(3), std::overflow_error);
}

TEST(Function, mul_matrix_function) {
  S21Matrix test_mat;
  S21Matrix test_mat2(2, 4);
  S21Matrix test_mat3(4, 2);
  EXPECT_THROW(test_mat.MulMatrix(test_mat3), std::out_of_range);
  test_mat(0, 0) = -DBL_MAX - 1;
  test_mat2(0, 0) = -DBL_MAX - 1;
  EXPECT_THROW(test_mat.MulMatrix(test_mat2), std::overflow_error);
}

TEST(Function, transpose_function) {
  S21Matrix test_mat(3, 3);
  S21Matrix test_mat2(3, 3);

  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  test_mat2(0, 0) = 36;
  test_mat2(0, 1) = -1;
  test_mat2(0, 2) = 0;

  test_mat2(1, 0) = 52;
  test_mat2(1, 1) = -63;
  test_mat2(1, 2) = 56;

  test_mat2(2, 0) = 36;
  test_mat2(2, 1) = -3;
  test_mat2(2, 2) = 3;

  EXPECT_TRUE(test_mat.Transpose() == test_mat2);
}

TEST(Function, calc_complements_function) {
  S21Matrix test_mat(3, 3);
  S21Matrix test_mat2(3, 3);

  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  test_mat2(0, 0) = -21;
  test_mat2(0, 1) = 3;
  test_mat2(0, 2) = -56;

  test_mat2(1, 0) = 1860;
  test_mat2(1, 1) = 108;
  test_mat2(1, 2) = -2016;

  test_mat2(2, 0) = 2112;
  test_mat2(2, 1) = 72;
  test_mat2(2, 2) = -2216;

  EXPECT_TRUE(test_mat.CalcComplements() == test_mat2);

  test_mat.setCols(4);
  EXPECT_THROW(test_mat.CalcComplements(), std::invalid_argument);
}

TEST(Function, determinant_function) {
  S21Matrix test_mat(3, 3);
  S21Matrix test_mat2(3, 3);

  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  test_mat.setCols(4);
  EXPECT_THROW(test_mat.Determinant(), std::invalid_argument);
  test_mat.setCols(1);
  test_mat.setRows(1);
  test_mat(0, 0) = 0;
  EXPECT_DOUBLE_EQ(0, test_mat.Determinant());
}

TEST(Function, inverse_function) {
  S21Matrix test_mat(3, 3);
  S21Matrix test_mat2(3, 3);

  test_mat(0, 0) = 36;
  test_mat(0, 1) = 52;
  test_mat(0, 2) = 36;

  test_mat(1, 0) = -1;
  test_mat(1, 1) = -63;
  test_mat(1, 2) = -3;

  test_mat(2, 0) = 0;
  test_mat(2, 1) = 56;
  test_mat(2, 2) = 3;

  test_mat2(0, 0) = 0.008027522;
  test_mat2(0, 1) = -0.71100917;
  test_mat2(0, 2) = -0.80733944;

  test_mat2(1, 0) = -0.001146788;
  test_mat2(1, 1) = -0.04128440;
  test_mat2(1, 2) = -0.027522935;

  test_mat2(2, 0) = 0.02140672;
  test_mat2(2, 1) = 0.770642201;
  test_mat2(2, 2) = 0.8470948;

  EXPECT_TRUE(test_mat2.EqMatrix(test_mat.InverseMatrix()));

  test_mat.setCols(1);
  test_mat.setRows(1);
  test_mat(0, 0) = 0;
  EXPECT_THROW(test_mat.InverseMatrix(), std::invalid_argument);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}