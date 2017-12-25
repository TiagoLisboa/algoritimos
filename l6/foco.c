#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

typedef struct {
	int ini;
	int fim;
} faixa;


int compare ( const void *o1, const void *o2 ) {
    faixa *f1 = (faixa *) o1;
    faixa *f2 = (faixa *) o2;
		return f1->ini - f2->ini ? f1->ini - f2->ini : f2->fim - f1->fim;
}

int contarFaixas (faixa faixas[MAX], int n, int prev, int qtd) {
	int i;
	for (i=prev+1; i < n; i++) {
		if (faixas[i].ini >= faixas[prev].fim) {
			return contarFaixas(faixas, n, i, qtd+1);
		}
	}
	return qtd;
}

int main () {
	int n, a, b, i = 0;
	faixa faixas[MAX];
	faixa faixa;

	while (scanf("%d", &n) != EOF) {
		i = -1;
		while (++i < n) {
			scanf("%d %d", &a, &b);
			faixa.ini = a;
			faixa.fim = b;
			faixas[i] = faixa;
		}

		qsort(faixas, n, sizeof(faixa), compare);
		i = -1;

		while (++i < n) {
			printf("%d %d\n", faixas[i].ini, faixas[i].fim);
		}	

		printf("%d\n", contarFaixas(faixas, n, 0, 1));
	}

	return 0;
}
