#include "s21_matrix.h"

// void s21_print_matrix(matrix_t *result) {
//   for (int i = 0; i < result->rows; i++) {
//     for (int j = 0; j < result->columns; j++) {
//       printf("%f ", result->matrix[i][j]);
//     }
//     printf("\n");
//   }
// }

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int ret = OK;
  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      *(result->matrix + i) = (double *)calloc(columns, sizeof(double));
    }
  } else {
    result->rows = 0;
    result->columns = 0;
    ret = INCORRECT;
  }
  return ret;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->rows && A->columns) {
    for (int i = 0; i < A->rows; i++) {
      free(*(A->matrix + i));
    }
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ret = SUCCESS;
  if (!A->rows || !A->columns || !B->rows || !B->columns) {
    ret = FAILURE;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    ret = FAILURE;
  } else {
    double eps = pow(10, -7);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= eps) {
          ret = FAILURE;
          break;
        }
        if (!ret) {
          break;
        }
      }
    }
  }
  return ret;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = OK;
  if (!A->rows || !A->columns || !A->columns || !B->columns) {
    ret = INCORRECT;
  } else if (A->rows != B->rows && A->columns != B->columns) {
    ret = CALC_ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return ret;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = OK;
  if (!A->rows || !A->columns || !B->rows || !B->columns) {
    ret = INCORRECT;
  } else if (A->rows != B->rows && A->columns != B->columns) {
    ret = CALC_ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return ret;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int ret = OK;
  if (!A->rows || !A->columns) {
    ret = INCORRECT;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return ret;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = OK;
  if (!A->rows || !A->columns || !B->rows || !B->columns) {
    ret = INCORRECT;
  } else if (A->columns != B->rows) {
    ret = CALC_ERROR;
  } else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return ret;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int ret = OK;
  if (!A->rows || !A->columns) {
    ret = INCORRECT;
  } else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return ret;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int ret = OK;
  if (!A->rows || !A->columns) {
    ret = INCORRECT;
  } else if (A->rows != A->columns) {
    ret = CALC_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t tmp;
        s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
        s21_get_minor(i, j, A, &tmp);
        result->matrix[i][j] = s21_get_determinant(&tmp);
        if ((j + i) % 2) {
          result->matrix[i][j] *= (-1);
        }
        s21_remove_matrix(&tmp);
      }
    }
  }
  return ret;
}

int s21_determinant(matrix_t *A, double *result) {
  int ret = OK;
  if (!A->rows || !A->columns) {
    ret = INCORRECT;
  } else if (A->rows != A->columns) {
    ret = CALC_ERROR;
  } else {
    *result = s21_get_determinant(A);
  }
  return ret;
}

double s21_get_determinant(matrix_t *A) {
  double det = 0;
  if (A->rows == 1) {
    det = A->matrix[0][0];
  } else {
    double sign = 1;
    matrix_t tmp;
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int i = 0; i < A->rows; i++) {
      s21_get_minor(0, i, A, &tmp);
      det += A->matrix[0][i] * sign * s21_get_determinant(&tmp);
      sign *= -1;
    }
    s21_remove_matrix(&tmp);
  }
  return det;
}

void s21_get_minor(int row, int col, matrix_t *A, matrix_t *result) {
  int act_row = 0, act_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    act_col = 0;
    for (int j = 0; j < A->rows; j++) {
      if (j == col) continue;
      result->matrix[act_row][act_col] = A->matrix[i][j];
      act_col++;
    }
    act_row++;
  }
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double det;
  int ret = s21_determinant(A, &det);
  if (!ret) {
    double eps = pow(10, -7);
    if (fabs(det - 0) < eps) {
      ret = CALC_ERROR;
    } else {
      matrix_t comp_mat;
      s21_calc_complements(A, &comp_mat);
      matrix_t trans_mat;
      s21_transpose(&comp_mat, &trans_mat);
      s21_mult_number(&trans_mat, 1 / det, result);
      s21_remove_matrix(&comp_mat);
      s21_remove_matrix(&trans_mat);
    }
  }
  return ret;
}