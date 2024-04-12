#include <stdio.h>
#include <stdlib.h>

int *CreateMatrix(int);
int FillMatrix(int, int *);
void MultMatrix(int, int *, int *, int *);
void print(int n, int *);

int main() {
  int n = 0;
  int correct = scanf("%d", &n);
  if (n < 1) correct = 0;
  if (!correct) printf("n/a");

  int *A = NULL, *B = NULL, *C = NULL;
  if (correct) {
    A = CreateMatrix(n);
    B = CreateMatrix(n);
    C = CreateMatrix(n);
    if (!A || !B || !C) correct = 0;
  }
  if (correct) correct = FillMatrix(n, A);
  if (correct) correct = FillMatrix(n, B);

  /*	char c = 0;
  scanf("%c", &c);
  if (c != 10) correct = 0;
  */
  if (correct) MultMatrix(n, A, B, C);
  if (correct) print(n, C);

  if (A) free(A);
  if (B) free(B);
  if (C) free(C);

  return 0;
}

int *CreateMatrix(int n) { return calloc(n * n, sizeof(int)); };

int FillMatrix(const int n, int *m) {
  int res = 1;
  for (int i = 0, size = n * n; i < size; ++i) {
    res = scanf("%d", (m + i));
    if (!res) i = n;
  }
  return res;
};

void MultMatrix(int n, int *A, int *B, int *C) {
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < n; ++k) {
      for (int m = 0; m < n; ++m) {
        *(C + i * n + k) += *(A + i * n + m) * *(B + m * n + k);
      }
    }
  }
};

void print(int n, int *matrix) {
  for (int i = 0, size = n * n; i < size; ++i) {
    if (i && i % n == 0) printf("\n");
    printf("%d", matrix[i]);
    if (i % n < n - 1) printf(" ");
  }
};
