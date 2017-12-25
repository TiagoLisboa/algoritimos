#include <stdio.h>

int main () {
	int v, m, moeda, i = -1, j, trocavel = 0;
	
	scanf("%d %d", &v, &m);
	int troco[v+2];

	while (++i <= m) {
		if (i != 0) scanf("%d ", &moeda);
		j = -1;
		while (++j <= v) {
			if (i == 0){ troco[j] = 0;}
			else {
				if (j == moeda) {
					troco[j] = moeda;
				} else if (troco[j] != 0 && troco[j] != moeda) {
					troco[j] = troco[j];
				} else if (j-moeda >= 0 && troco[j-moeda] != 0 && troco[j-moeda] != moeda) {
					troco[j] = moeda;
				} else {
					troco[j] = 0;
				}
			}	
		}
		if(troco[j-1] != 0) {
			trocavel = 1;
			break;
		}
	}

	i=-1;
	/*while(++i<=v){
		printf("%d ", troco[i]);
	}*/

	if (trocavel) printf("S\n"); else printf("N\n");
	return 0;
}
