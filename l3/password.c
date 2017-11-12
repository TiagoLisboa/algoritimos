#include <stdio.h>

int main () {
  char s[255];
  int i, min = 0, mai = 0, num = 0, sim;

  while (scanf(" %[^\n]s\0", s) != EOF) {
    i = 0, min = 0, mai = 0, num = 0, sim = 0;
    while(s[i] != '\0') {
      if (s[i] >= '0' & s[i] <= '9') {
        num = 1;
      } else if (s[i] >= 'A' & s[i] <= 'Z') {
        mai = 1;
      } else if (s[i] >= 'a' & s[i] <= 'z') {
        min = 1;
      } else {
        sim = 1;
        break;
      }
      i++;
    }

    if ((i < 6) | (i > 32) | !num | !mai | !min | sim) {
      printf("Senha invalida.\n");
    } else {
      printf("Senha valida.\n");
    }
  }

  return 0;
}
