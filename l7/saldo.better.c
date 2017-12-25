#include <stdio.h>

#define MAX 10000

int partidas[MAX][MAX];
int resultados[MAX][2];


int main () {
	int n, x, y, i, j, t = 1, aux = 0, melhor = 0, melhori = 0, melhorj = 0;
	
	while (scanf("%d", &n) && n!= 0) {
		i = -1;
		while (++i < n) {
			j = -1;
			
			scanf("%d %d", &x, &y);
			resultados[i][0] = x;
			resultados[i][1] = y;
			while (++j < n) {
				if (i == j) partidas[i][j] = x - y;
				else partidas[i][j] = -1;
			}
		}

		printf("Teste %d\n", t++);
		
		i = -1;
		melhor = 0, melhori = 0, melhorj = 0;
		while (++i < n) {
			j = i-1;
			while (++j < n) {
				int inicio = i, fim = j;

				if (partidas[inicio][fim] != -1) {
					aux = partidas[inicio][fim];
				} else if (inicio == fim) {
					partidas[inicio][fim] = resultados[inicio][0] - resultados[inicio][1];
					aux =	partidas[inicio][fim];
				} else {
					partidas[inicio][fim] = partidas[inicio][fim-1] + partidas[fim][fim];
					aux = partidas[inicio][fim];
				}
				if (aux > melhor || (aux == melhor && j - i > melhorj - melhori)) melhor = aux, melhorj = j, melhori =  i;
			}
		}
		if (melhor > 0)
			printf ("%d %d\n\n", melhori+1, melhorj+1);
		else
			printf("nenhum\n\n");
	}

	return 0;
}
