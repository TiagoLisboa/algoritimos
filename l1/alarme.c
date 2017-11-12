#include <stdio.h>

int main () {
  int h1 = 1, m1 = 1, h2 = 1, m2 = 1, sum;

  while (h1 | m1 | h2 | m2) {
    scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
    sum = 0;

    if (h1 >= 0 & h1 <= 23 & h2 >= 0 & h2 <= 23 & m1 >= 0 & m1 <= 59 & m2 >= 0 & m2 <= 59) {
      if (h1 == 0 & h2 == 0 & m1 == 0 & m2 == 0) {
        break;
      } else {
        h2 = (h2 < h1) | (h2 == h1 & m2 < m1) ? h2 + 24 : h2;
        sum += (h2 * 60) + m2;
        sum -= (h1 * 60) + m1;
        printf("%d\n", sum);
      }
    }
  }

  return 0;

}
