#include <stdio.h>

#define MAX 21

int moverPeca (int tabuleiro[MAX][MAX], int n, int m, int li, int lj, int qtd) {
	int movesI[] = {-1, -1, 1, 1};
	int movesJ[] = {-1, 1, -1, 1};
	int ni, nj, nni, nnj, i, aux, best = qtd;
	for (i = 0; i < 4; i++) {

		ni = li + movesI[i];
		nj = lj + movesJ[i];	
		nni = ni + movesI[i];
		nnj = nj + movesJ[i];

		if ( nni >= 0 && nnj >= 0 && nni < n && nnj < m && tabuleiro[ni][nj] == 2 && tabuleiro[nni][nnj] == 0) {
			tabuleiro[li][lj] = 0;
			tabuleiro[ni][nj] = 0;
			tabuleiro[nni][nnj] = 1;
			aux = moverPeca (tabuleiro, n, m, nni, nnj, qtd+1);
			if (aux > best) {best = aux;}
			tabuleiro[ni][nj] = 2;
			tabuleiro[nni][nnj] = 0;
			tabuleiro[li][lj] = 1;
		} 
	}

	return best;
}

int contarJogadas (int tabuleiro[MAX][MAX], int pos[MAX][2], int npos,  int n, int m) {
	int best = 0, aux = 0, i, j, x;
	for (x = 0; x < npos; x++) {
		i = pos[x][0];
		j = pos[x][1];
		aux = moverPeca(tabuleiro, n, m, j, i, 0);
		if (aux > best) best = aux;
	}

	return best;
}

int main () {

	int n, m, i, j, x, npos = 0;
	int tabuleiro[MAX][MAX];
	int pos[MAX][2];

	while (scanf ("%d %d", &n, &m) && n != 0 && m != 0) {
		npos = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				tabuleiro[i][j] = 3;
			}
		}
		
		for (i = 0; i < n; i++) {
			for (j = i&0x1; j < m; j += 2) {
				scanf("%d ", &x);
				tabuleiro[i][j] = x;
				if (x == 1) {pos[npos][0] = j; pos[npos++][1] = i;}
			}
		}


		printf("%d\n", contarJogadas (tabuleiro, pos, npos, n, m));
		
	}

	return 0;
}
