#include <stdio.h>
#include <stdlib.h>


#define MAX 100001

typedef struct {
	int ini;
	int fim;
} Consulta;

int compare (const void *a, const void *p) {
	Consulta *x = (Consulta *) a;
	Consulta *y = (Consulta *) p;
	return x->fim - y->fim;
}


int contaConsultas (Consulta consultas[MAX], int size, int qtd, int next, int ant) {
	int i = next-1;
	while (++i < size) {
		if (consultas[i].ini >= consultas[ant].fim) {
			return contaConsultas(consultas, size, qtd+1, i+1, i);
		}
	}
	return qtd;
}

int main () {
	int n, ini, fim, i = -1;
	Consulta consultas[MAX];
	
	scanf("%d", &n);

	while (++i < n) {
		scanf("%d %d", &ini, &fim);

		consultas[i].ini = ini;
		consultas[i].fim = fim;
	}

	qsort(consultas, n, sizeof(Consulta), compare);


	printf("%d\n", contaConsultas(consultas, n, 1, 1, 0));

	return 0;
}
