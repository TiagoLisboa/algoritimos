#include <stdio.h>
#include <string.h>

int main () {
  int n, t = 0, i = 0;
  char v[101] = "";

  scanf ("%d", &n);

  while (n--) {
    scanf(" %[^\n]s", v);
    i = 0;
    t = 0;

    while (i < strlen(v)) {
      
      if (v[i] == '1') {
        t += 2;
      } else if (v[i] == '2' | v[i] == '3' | v[i] == '5') {
        t += 5;
      } else if (v[i] == '4') {
        t += 4;
      } else if (v[i] == '6' | v[i] == '9' | v[i] == '0') {
        t += 6;
      } else if (v[i] == '7') {
        t += 3;
      } else if (v[i] == '8') {
        t += 7;
      }
      i++;
    }

    printf("%d leds\n", t);
  }

  return 0;
}
