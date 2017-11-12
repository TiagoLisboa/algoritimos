#include <stdio.h>

int main () {
  int n, i;
  char m[1001];

  scanf("%d", &n);

  while (n--) {
    scanf(" %[^\n]s", m);
    
    i = 0;
    while (i < 10001 & m[i] != '\0'){
      if (m[i] >= 'A' & m[i] <= 'z') {
        m[i] += 3;
      }
      i++;
    }
    i--;

    int x = i/2;
    while (x >= 0) {
      char tmp = m[x];
      m[x] = m[i - x];
      m[i - x] = tmp;
      x--;
    }


    x = i/2;
    x = i % 2 == 0 ? x : x + 1;
    while (x <= i) {
      m[x] -= 1;
      x++;
    }

    printf("%s\n", m);
  }

  return 0;
}
