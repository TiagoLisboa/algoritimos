#include <stdio.h>

int main () {
	int v, m, moeda, i = -1, j, trocavel = 0;
	
	scanf("%d %d", &v, &m);
	int troco[m+1][v+1];

	while (++i <= m) {
		if (i != 0) scanf("%d ", &moeda);
		j = -1;
		while (++j < v) {
			if (i == 0){ troco[i][j] = 0;}
			else {
				if (j+1 == moeda) {
					troco[i][j] = 1;
				} else if (troco[i-1][j] == 1) {
					troco[i][j] = 1;
				} else if (troco[i-1][j-moeda] == 1) {
					troco[i][j] = 1;
				} else {
					troco[i][j] = 0;
				}
			}	
		}
		if(troco[i][j-1] == 1) {
			trocavel = 1;
			break;
		}
	}

	if (trocavel) printf("S\n"); else printf("N\n");	

	return 0;
}
