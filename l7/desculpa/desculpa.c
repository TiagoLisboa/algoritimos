#include <stdio.h>

int main () {
	int c, f, n, d, i, j, t = 1;
	
	while (scanf("%d %d", &c, &f) && c != 0 && f != 0) {
		i = -1;
		int cartao[f][c];
		while (++i < f) {
			scanf("%d %d", &n, &d);
			j = -1;
			while (++j < c) {
				if (j >= n - 1) {
					if (i > 0 && cartao[i-1][j] > d) {
						cartao[i][j] = cartao[i-1][j];
					} else if (i > 0 && j > n){
						cartao[i][j] = d + cartao[i-1][j-n];
					} else {
						cartao[i][j] = d;
					}
				} else {
					cartao[i][j] = i > 0 ? cartao[i-1][j] : 0;
				}
			}
		}
		printf("Teste %d\n", t++);
		printf("%d\n\n", cartao[i-1][j-1]);
	}

	return 0;
}
