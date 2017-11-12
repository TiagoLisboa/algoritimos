#include <stdio.h>

int main () {
  int k = -1, n, m, x, y, i;

  while (k) {
    scanf("%d", &k);
   
    if (k == 0)
      continue;

    scanf("%d %d", &n, &m);

    for (i = 0; i < k; ++i) {
      scanf("%d %d", &x, &y);

      if (x == n || y == m) {
        printf("divisa");
      } else if (x < n & y < m) {
        printf("SO");
      } else if (x < n & y > m) {
        printf("NO");
      } else if (x > n & y < m) {
        printf("SE");
      } else if (x > n & y > m) {
        printf("NE");
      }

      printf("\n");
    }
  }

  return 0;
}
