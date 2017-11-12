#include <stdio.h>

int main () {
  int n, rs, i;
  char cifra[50];

  scanf ("%d", &n);

  while (n--) {
    scanf("%s", cifra);
    scanf("%d", &rs);
    
    i = 0;
    while (i < 50 & cifra[i] != '\0') {
      cifra[i] -= rs;
      while (cifra[i] < 'A') {
        cifra[i] = 'Z' - ('A' - cifra[i] - 1);
      }
      i++;
    }

    printf("%s\n", cifra);
  }

  return 0;
}
