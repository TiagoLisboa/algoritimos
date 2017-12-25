#include <stdio.h>

#define MAX 10000

int partidas[MAX][MAX];

int saldo (int resultados[MAX][2], int n, int inicio, int fim) {
	if (inicio > fim) {
		int aux = inicio;
		inicio = fim;
		fim = aux;
	}
	if (partidas[inicio][fim] != -1) {
		return partidas[inicio][fim];
	}
	if (inicio == fim) {
		partidas[inicio][fim] = resultados[inicio][0] - resultados[inicio][1];
		return 	partidas[inicio][fim];
	}
	int meio = (inicio+fim)/2;
	int res = saldo(resultados, n, inicio, meio) + saldo(resultados, n, meio+1, fim);
	partidas[inicio][fim] = res;
	return partidas[inicio][fim];
}

int main () {
	int n, x, y, i, j, t = 1, aux = 0, melhor = 0, melhori = 0, melhorj = 0;
	int resultados[MAX][2];
	
	while (scanf("%d", &n) && n!= 0) {
		i = -1;
		while (++i < n) {
			j = -1;
			while (++j < n) {
				partidas[i][j] = -1;
			}
			scanf("%d %d", &x, &y);
			resultados[i][0] = x;
			resultados[i][1] = y;
		}

		printf("Teste %d\n", t++);
		
		i = -1;
		melhor = 0, melhori = 0, melhorj = 0;
		while (++i < n) {
			j = i-1;
			while (++j < n) {
				 aux = saldo (resultados, n, i, j);
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
