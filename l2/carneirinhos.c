#include <stdio.h>

int contarCarneirinhos (int n) {
  int c, i, j, t = n;
  int carneirinhos[n];

  for (i = 0; i < n; ++i) {
    scanf("%d", &c);
    carneirinhos[i] = c;
    for (j = i - 1; j >= 0; --j) {
      if (carneirinhos[j] == c) {
        t--;
        break;
      }
    }
  }
 return t;
}

int main () {
  int t, n;

  scanf("%d", &t);

  while (t) {
    --t;
    scanf("%d", &n);
    printf("%d\n", contarCarneirinhos(n));
  }

  return 0;
}
