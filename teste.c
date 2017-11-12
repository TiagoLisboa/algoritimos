#include <stdio.h>
#include <math.h>


int main () {
  int n, i, a, b;

  scanf("%d", &n);

  while (n) {
    scanf("%d %d", &a, &b);

    if (a > b) {
      i = 0;
      
      while (1) {
        i++;
        int x = (int)pow(10, i);

        if (b%x == b) break;
      }

      int x = (int)pow(10, i);

      if (a%x == b) {
        printf("encaixa\n");
      } else {
        printf("nao encaixa\n");
      }

    } else {
      printf("nao encaixa\n");
    }
    
    n--;
  }

  return 0;
}
