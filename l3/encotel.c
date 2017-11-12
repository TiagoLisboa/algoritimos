#include <stdio.h>
#include <string.h>

int main () {
  int i;
  char es[31];

  while (scanf("%s\0", es) != EOF) {
    i = 0;
    while (es[i] != '\0') {
      if (es[i] == '1' | es[i] == '0' | es[i] == '-') {
        printf("%c", es[i]);
      } else if (es[i] == 'A' | es[i] == 'B' | es[i] == 'C') {
        printf("2");
      } else if (es[i] == 'F' | es[i] == 'D' | es[i] == 'E') {
        printf("3");
      } else if (es[i] == 'I' | es[i] == 'G' | es[i] == 'H') {
        printf("4");
      } else if (es[i] == 'L' | es[i] == 'J' | es[i] == 'K') {
        printf("5");
      } else if (es[i] == 'O' | es[i] == 'M' | es[i] == 'N') {
        printf("6");
      } else if (es[i] == 'R' | es[i] == 'P' | es[i] == 'Q' | es[i] == 'S') {
        printf("7");
      } else if (es[i] == 'T' | es[i] == 'U' | es[i] == 'V') {
        printf("8");
      } else if (es[i] == 'W' | es[i] == 'X' | es[i] == 'Y' | es[i] == 'Z') {
        printf("9");
      } 
      i++;
    }
    printf("\n");
  }

  return 0;
}
