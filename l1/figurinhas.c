#include <stdio.h>

int main () {
  int n, f1, f2, z;

  scanf("%d", &n);

  while (n) {
    --n;
    scanf("%d %d", &f1, &f2);

    int dividendo = f1 < f2 ? f1 : f2;
    int divisor = f1 > f2 ? f1 : f2;

    z = 1;

    while (z != 0) {
      z = dividendo % divisor;
      dividendo = divisor;
      divisor = z;
    }

    printf("%d\n", dividendo);
  }

  return 0;
}
