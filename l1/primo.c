#include <stdio.h>

int main () {
	int primo = 1, numero = 0;
	scanf("%d", &numero);

	for (int i = (int)(numero/2); i > 1; i--) {
		if (numero%i == 0) primo = 0;
	}

	if (primo) printf("sim\n"); else printf("não\n");

}
