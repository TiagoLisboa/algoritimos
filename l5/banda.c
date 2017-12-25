#include <stdio.h>

int banda (int afinidades[1001][1001], int grupo[3], int n, int prox, int qtd) {
	int i = prox, soma = 0, j, nsoma = 0;
	
	if (qtd == 3)
		return afinidades[grupo[0]][grupo[1]] + afinidades[grupo[0]][grupo[2]] + afinidades[grupo[1]][grupo[2]];
	
	while (++i<=n) {
		int proto_grupo[3] = {grupo[0], grupo[1], grupo[2]};
		proto_grupo[qtd] = i;
		nsoma = banda (afinidades, proto_grupo, n, i, qtd+1);
		if (nsoma > soma) {
			soma = nsoma;
			for (j=0 ; j<3 ; ++j)
				grupo[j] = proto_grupo[j];
		}
	}
	return soma;
}

int main () {
	int n, m, i, j, x, y, z;
	int afinidades[1001][1001], grupo[3] = {1, 2, 3};

	scanf("%d %d", &n, &m);
	
	for (i=0 ; i<n ; ++i) {
		for (j=0 ; j<n ; ++j) {
			afinidades[i][j] = 0;
		}
	}

	for (i=0 ; i<m ; ++i) {
		scanf ("%d %d %d", &x, &y, &z);
		afinidades[x][y] = z;
		afinidades[y][x] = z;
	}

	banda (afinidades, grupo, n, 0, 0);
	
	printf ("%d %d %d\n",grupo[0], grupo[1], grupo[2]);
	
	return 0;
}
