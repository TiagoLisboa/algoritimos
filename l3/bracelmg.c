#include <stdio.h>
#include <string.h>

int main () {
  char sp[10001], sb[10001];
  int n, i, j, oldi, achou = 0, spl, sbl;
  
  scanf("%d", &n);

  while(n-- > 0) {
    scanf("%s %s", sp, sb);
    spl = strlen(sp);
    sbl = strlen(sb);
    j = 0;
    for (i = 0; i < sbl; i++) {
      achou = 0;
      oldi = i;
      
      for (j = 0; j < spl; j++) {
        /*printf("DIRETO --> sp: %c (j: %d) sb: %c (i: %d)\n", sp[j], j, sb[oldi], oldi);*/
        if (sb[oldi] != sp[j]) {
          if (sb[oldi] != '\0') {
            break;
          } else {
            oldi = 0;
            j--;
            continue;
          }
        } else {
          achou++;
        }
        oldi++;
      }
      

      if (achou == spl) {
        printf("S\n");
        break;
      }

      oldi = i;
      achou = 0;
      for (j = spl-1; j >= 0; j--) {
        /*printf("REVERSO --> sp: %c (j: %d) sb: %c (oldi: %d)\n", sp[j], j, sb[oldi], oldi);*/
        if (sb[oldi] != sp[j]) {
          if (sb[oldi] != '\0') {
            break;
          } else {
            oldi = 0;
            j++;
            continue;
          }
        } else {
          achou++;
        }
        oldi++;
      }
      
      /*printf("achou: %d spl: %d\n", achou, spl);


      printf("----------\n");*/

      if (achou == spl) {
        printf("S\n");
        break;
      }
    }

    if (achou != spl) {
      printf("N\n");
    }
  }

  return 0;
}
