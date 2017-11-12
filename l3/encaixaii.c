#include <stdio.h>
#include <string.h>

int main () {
  int n, i, sa, sb, minus, equals;
  char stra[10001], strb[10001];
    
  scanf("%d", &n);
  
  while(n-- > 0){
    scanf("%s %s", stra, strb);
    sa = strlen(stra);
    sb = strlen(strb);
    equals = 1;

    if (sa >= sb) {
      minus = sa - sb;
      for (i = sb-1; i >= 0; i--) {
        if (stra[minus + i] != strb[i]) {
          equals = 0;
          break;
        }
      }
    } else {
      equals = 0;
    }

    equals ? printf("encaixa") : printf("nao encaixa");
    printf("\n");
  }

  return 0;
}
