/*
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*                                Trabalho 4
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* 	http://www.spoj.com/problems/TSORT/
*
*/
#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *A, int *B, int k, int size) {
  int *C = (int *)calloc((k + 1), sizeof(int));
  int i, j;
  for (i = 0; i <= k; i++)
    C[i] = 0;
  for (j = 1; j <= size; j++)
    C[A[j]] = C[A[j]] + 1;
  for (i = 1; i <= k; i++)
    C[i] = C[i] + C[i - 1];
  for (j = size; j >= 1; j--) {
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }
}
int main(int argc, char const *argv[]) {
  int size, i;
  scanf("%d", &size);
  int *A = (int *)calloc((size + 1), sizeof(int));
  int *B = (int *)calloc((size + 1), sizeof(int));
  for (i = 1; i <= size; i++)
    scanf("%d", &A[i]);
  counting_sort(A, B, 1000000, size);
  for (i = 1; i <= size; i++)
    printf("%d\n", B[i]);
  return 0;
}
