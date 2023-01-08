#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int *row, int *col) {
  char c;
  int count, tmp = 0;
  count = scanf("%d%d%c", row, col, &c);
  if (count == 3 && c == '\n' && *row > 0 && *col > 0) {
    *matrix = malloc(*row * *col * sizeof(int));
    for (int i = 0; i < *row; i++) {
      for (int j = 0; j < *col; j++) {
        scanf("%d%c", *matrix + *col * i + j, &c);

        if ((c == '\n' && j != *col - 1) || (c == ' ' && j == *col - 1))
          return 1;
      }
    }

    for (int i = 0; i < *row * *col; i++) {
      for (int *p = *matrix + 1; p - *matrix < *row * *col; p++) {
        if (*p < *(p - 1)) {
          tmp = *p;
          *p = *(p - 1);
          *(p - 1) = tmp;
        }
      }
    }

  } else {
    return 1;
  }
  return 0;
};

void sort_horizontal(int *matrix, int row, int col, int *result_matrix) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (i % 2 == 0) {
        result_matrix[i * col + j] = matrix[i * col + j];
      } else if (i % 2 == 1) {
        result_matrix[i * col + j] = matrix[i * col + (col - j - 1)];
      }
    }
  }
};

void sort_vertical(int *matrix, int row, int col, int *result_matrix) {
  int i = 0, j = 0;
  for (int k = 0; k < row * col; k++) {
    j = k / row;
    i = k % row;
    if (j % 2 == 1) i = row - 1 - i;
    result_matrix[i * col + j] = matrix[k];
  }
}

void output(int *matrix, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d ", matrix[i * col + j]);
    }
    printf("\b\n");
  }
};

int main() {
  int *matrix;
  int *result;
  int row, col, inp;
  inp = input(&matrix, &row, &col);

  if (inp == 1) {
    printf("n/a");
  } else {
    result = malloc(row * col * sizeof(int));
    sort_vertical(matrix, row, col, result);
    output(result, row, col);
    printf("\n");
    sort_horizontal(matrix, row, col, result);
    output(result, row, col);
    printf("\b");
    free(result);
  }
  free(matrix);
  return 0;
}