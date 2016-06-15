/*
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*                                Trabalho 4
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* 	http://www.spoj.com/problems/TSORT/
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int *list, int ini, int fim);
int particao(int *list, int ini, int fim);

int main(int argc, char const *argv[]) {
    int t; /* Quantidade de números a ser ordenado [t <= 10^6] */
    int i;

    srand(time(NULL));

    scanf("%d", &t);

    int list[t];

    for (i = 0; i < t; i++){
        scanf("%d", &list[i]);
    }

    quick_sort(list, 0, t - 1);

    for (i = 0; i < t; i++){
        printf("%d\n", list[i]);
    }
return 0;
}

int particao(int *list, int ini, int fim) {

    int pivo = list[ini + (rand() % (fim - ini))];

    while (1) {

        for(;list[ini] < pivo; ini++);

        for(;list[fim] > pivo; fim--);

        if (ini >= fim){
            return fim;
        }

        int aux = list[ini];
        list[ini++] = list[fim];
        list[fim--] = aux;
    }
}

void quick_sort(int *list, int ini, int fim) {
    if (ini < fim) {
        int p = particao(list, ini, fim);
        quick_sort(list, ini, p);
        quick_sort(list, p + 1, fim);
    }
}
