#include <stdio.h>
#include <string.h>

int main () {
  int n, i, j, a, b, minus, equals;
  char stra[32], strb[32];
    
  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    scanf("%d %d", &a, &b);
    equals = 0;

    if (a >= b) {
      sprintf(stra, "%d", a);
      sprintf(strb, "%d", b);

      minus = strlen(stra) - strlen(strb);

      equals = 1;

      for (j = minus; j < strlen(stra); ++j) {
        if (stra[j] != strb[j - minus]) {
          equals = 0;
          break;
        }
      }  
    }

    equals ? printf("encaixa") : printf("nao encaixa");
    printf("\n");
  }

  return 0;
}
