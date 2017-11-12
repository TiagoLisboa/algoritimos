#include <stdio.h>

int main () {
  int n, i, j, x;
  
  scanf("%d", &n);

  int m1 [n][n];

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf (" %d", &x);
      m1 [i][j] = x;
    }
  }
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf (" %d", &x);
      m1 [i][j] += x;
    }
  }
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", m1 [i][j]);
    }
    printf("\n");
  }
  return 0;
}
