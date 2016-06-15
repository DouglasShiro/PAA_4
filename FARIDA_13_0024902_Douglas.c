/*
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*                                Trabalho 4
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* 	http://www.spoj.com/problems/FARIDA/
*/

#include <stdio.h>

long long int maior(long long int x, long long int y) {
    return (x > y) ? x : y;
}

int main() {
  int testes; /* numero de testes a serem feitos */
  int j;

  scanf("%d", &testes);

  for (j = 0; j < testes; j++) {
    int N; /* Numero de monstros */
    int i;

/* moedas com cada monstro <= 10^9 */
    long long int a[1001];
    long long int d[1001];

    scanf("%d", &N);

    /* moedas que cada monstro possui */
    for (i = 0; i < N; i++){
      scanf("%lld", &a[i]);
    }

    d[0] = a[0];
    d[1] = maior(d[0], a[1]);

    for (i = 2; i < N; i++){
      d[i] = maior(d[i - 1], a[i] + d[i - 2]);
    }

    printf("Case %d: %lld\n", j + 1, d[N - 1]);
  }

  return 0;
}
