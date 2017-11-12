#include <stdio.h>

void fila (int n) {
  int a, m, i = n;
  int fila[n];

  while (i > 0) {
    scanf (" %d", &a);
    fila[n - i] = a;
    i--;
  }

  scanf ("%d", &m);

  while (m-- > 0) {
    scanf (" %d", &a);

    for (i = 0; i < n; i++) {
      if (fila[i] == a) {
        fila[i] = -1;
        break;
      }
    }
  }

  for (i = 0; i < n; i++) {
    if (fila[i] != -1) {
      printf("%d ", fila[i]);
    }
  }
  
  printf("\n");
}

int main () {
  int n = 0;

  scanf("%d", &n);

  fila(n);

  
  return 0;
}
