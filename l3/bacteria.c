#include <stdio.h>
#include <string.h>

int main () {
  char d[10001], s[10001];
  int i, j, oldi;

  while(scanf("%s %s", d, s) != EOF) {
    j = 0;
    for (i = 0; i < strlen(d); i++) {
      if (j == 0 && d[i] == s[0]) {
        oldi = i++;
        j++;
      }


      if (j > 0) {
        if (d[i] != s[j]) {

          if (s[j] == '\0'){
            break;
          } else {
            i = oldi;
            j = -1;
          }
        }
        j++;
      }
    }
    if (j == strlen(s)) {
      printf("Resistente\n");
    } else {
      printf("Nao resistente\n");
    }
  }

  return 0;
}
