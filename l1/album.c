#include <stdio.h>

int main () {
  int x = 0, y = 0, l1 = 0, l2 = 0, h1 = 0, h2 = 0;

  scanf ("%d %d", &x, &y);
  if (x >= 1 & x <= 1000) {
    scanf ("%d %d", &h1, &l1);
    if (l1 >= 1 & h1 <= 1000) {
      scanf ("%d %d", &h2, &l2);
      if (l2 >= 1 & h2 <= 1000) {
        if (l1+l2 <= x & h1 <= y & h2 <= y) {
          printf("S\n");
        } else if (l1+h2 <= x & h1 <= y & l2 <= y) {
          printf("S\n");
        } else if (h1+l2 <= x & l1 <= y & h2 <= y) {
          printf("S\n");
        } else if (h1+h2 <= x & l1 <= y & l2 <= y) {
          printf("S\n");
        } else if (l1+l2 <= y & h1 <= x & h2 <= x) {
          printf("S\n");
        } else if (l1+h2 <= y & h1 <= x & l2 <= x) {
          printf("S\n");
        } else if (h1+l2 <= y & l1 <= x & h2 <= x) {
          printf("S\n");
        } else if (h1+h2 <= y & l1 <= x & l2 <= x) {
          printf("S\n");
        } else {
          printf("N\n");
        }
      }
    }
  }

  return 0;
}
