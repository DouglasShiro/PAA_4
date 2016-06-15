/*
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*                                Trabalho 4
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* 	http://www.spoj.com/problems/KNAPSACK/
*/

#include <stdio.h>
#include <stdlib.h>

int maior(int a, int b){
    return a<b ? b:a;
}

int knapsack(int v[], int N, int t[], int S){
    int F[S+1];

    for(int i = 0; i < S+1; i++){
        F[i] = 0;
    }

    for(int i = 0; i < N; ++i){
        for(int j = S; j >= t[i]; --j){
            F[j] = maior(F[j], F[j - t[i]] + v[i]);
        }
    }
    return F[S];
}

int main(){
    int S; /* Capacidade */
    int N; /* Quantidade itens */

    scanf("%d %d", &S, &N);

    int t[N]; /* tamanho */
    int v[N]; /* valor */

    for(int i = 0; i < N; i++){
        scanf("%d %d", &t[i], &v[i]);
    }

    printf("%d\n", knapsack(v, N, t, S));

return 0;
}
