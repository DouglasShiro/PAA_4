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

int knapsack(int v[], size_t sizeV, int w[], int W){
    int n = sizeV;
    int F[W+1];

    for(int i = 0; i < W+1; i++)
        F[i] = 0;

    for(int i = 0; i < n; ++i)
        for(int a = W; a >= w[i]; --a)
            F[a] = maior(F[a], F[a - w[i]] + v[i]);

    return F[W];
}

int main(){
    int W, n;
    scanf("%d %d", &W, &n);
    int v[n];
    int w[n];

    for(int i = 0; i < n; i++)
        scanf("%d %d", &w[i], &v[i]);

    printf("%d\n", knapsack(v, sizeof v / sizeof *v, w, W));

return 0;
}
