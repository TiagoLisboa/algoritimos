#include <stdio.h>

void organizarVoluntarios (int voluntarios[], int r) {
  int i, j;
  
  for (i = r - 1; i >= 0; --i) {
    for (j = 1; j <= i; ++j) {
      if ((j < r) & (voluntarios[j - 1] > voluntarios[j])) {
        int x = voluntarios[j - 1];
        voluntarios[j - 1] = voluntarios[j];
        voluntarios[j] = x;
      }
    }
  }
}

void verQuemFalta (int voluntarios[], int n, int r) {
  int i, j, x;

  for (i = 1; i <= n; ++i) {
    x = 1;
    for (j = 0; j < r; ++j) {
      if (i == voluntarios[j]) {
        x  = 0;
        break;
      }
    }
    if (x) printf("%d ", i);
  }

  printf("\n");
}

void lerVoluntarios (int n, int r) {
  int voluntarios[r];
  int i, v;

  for(i = 0; i < r; ++i) {
    scanf("%d", &v);
    voluntarios[i] = v;
  }

  if (n == r) {
    printf("*\n");
  } else {
    organizarVoluntarios(voluntarios, r);
    verQuemFalta(voluntarios, n, r);
  }
}

int main () {
  int n, r;
  
  while (scanf ("%d %d", &n, &r) != EOF) {
    lerVoluntarios(n, r);
  }
  
  return 0;
}
