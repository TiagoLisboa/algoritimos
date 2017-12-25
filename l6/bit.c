#include <stdio.h>


const static	int cedulas[4] = {50, 10, 5, 1};

void saque (int valor, int notas[4], int next) {
	int i = -1;
	
	while (++i < 4) {
		if (valor - cedulas[i] >= 0) {
			valor -= cedulas[i];
			notas[i] += 1;
			saque (valor, notas, next+1);
			return;
		}
		if (valor == 0) {
			return;
		}
	}


}	

int main () {
	int valor = 0, n= 0;

	while (scanf ("%d", &valor) && valor != 0) {
		n++;
		int notas[4] = {0, 0, 0, 0};
		saque (valor, notas, 0);
	
		printf("Teste %d\n", n);
		printf("%d %d %d %d\n\n", notas[0], notas[1], notas[2], notas[3]);
	}
	return 0;
}
