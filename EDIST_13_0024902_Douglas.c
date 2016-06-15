/*
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*                                Trabalho 4
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* 	http://www.spoj.com/problems/Edist/
*/

#include<stdio.h>
#include<string.h>

int dist[2002][2002];

int dif(char i , char j){
	return (i == j) ? 0 : 1;
}

int min(int i , int j, int k){
	if(i <= j){
		return (i <= k) ? i : k;
	}else{
		return (j <= k) ? j : k;
	}
}

int main(){
	int T;			/* Numero de testes */
	char A[2002];	/* Numero maximo de caracteres: 2000 */
	char B[2002];
	int tamA,tamB;
	int i,j,k;

	scanf("%d",&T);

	for (j = 0; j < T; j++) {
		scanf("%s",A);
		scanf("%s",B);
		tamA = strlen(A);
		tamB = strlen(B);
		for(i = 0 ; i <= tamA ; i++){
			for(k = 0 ; k <= tamB ; k++){
				dist[i][k] = 0;
			}
		}

		for(i = 0 ; i <= tamA ; i++){
			dist[i][0] = i;
		}

		for(i = 0 ; i <= tamB ; i++){
			dist[0][i] = i;
		}

		for(i = 1 ; i <= tamA ; i++){
			for(k = 1 ; k <= tamB ; k++){
				dist[i][k] = min((1+dist[i-1][k]), (1+dist[i][k-1]), (dif(A[i-1], B[k-1]) + dist[i-1][k-1]));
			}
		}
		printf("%d\n",dist[tamA][tamB]);
	}
	return 0;
}
