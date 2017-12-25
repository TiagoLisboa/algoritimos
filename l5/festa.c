#include <stdio.h>

#define MAX 20

/*
 *
 * PARA CADA ELEMENTO DE GRUPO EXECUTAR A FUNÇÃO PASSANDO
 * O PROPRIO GRUPO MENOS OS ELEMENTOS DA LINHA Q TRETAM
 *
 * */
int testa (int tretas[MAX][MAX], int n, int grupo[MAX], int qtdRm, int next) {
	int i, j, meu_grupo[MAX], qtdRmTmp = qtdRm;
		
	if (qtdRm >= n || (qtdRm == 0 && next != 0))
		return qtdRm;

	int qtdRmMin = MAX;

	i = -1;

	while (++i < n) {
		if (grupo[i] == 0) {
			j = -1;
			qtdRmTmp = 0;
			while (++j < n) {
				if (tretas[next][j] || grupo[j]) {
					meu_grupo[j] = j+1;
					qtdRmTmp++;
				} else {
					meu_grupo[j] = 0;
				}
			}

			j = -1;

			if (qtdRmTmp != qtdRm) {
				qtdRmTmp = testa (tretas, n, meu_grupo, qtdRmTmp, i+1);
			}

			qtdRmMin = qtdRmMin < qtdRmTmp ? qtdRmMin : qtdRmTmp;
		}
		
	}

	return qtdRmMin;
	
}

int main () {
	int n, i, j, k = 0, li, leituras[MAX][MAX], grupo[MAX];

	while(scanf ("%d", &n) && n){
		i = -1, j = -1;
		k++;
	 
	 	while (++i < n) {
			while (++j < n) {
				leituras[i][j] = 0;
			}
		 	j = -1;
			grupo[i] = 0;
	 	}

		i = -1, j = 0;

	 	while (++i < n) {
		 	while (scanf ("%d", &li) && li) {
				leituras[i][li-1] = li;
			}
			j = 0;
		}
		
		i = -1, j = -1;

				printf ("Teste %d\n%d\n\n", k, n - testa (leituras, n, grupo, 0, 0));
	}

	return 0;
}
