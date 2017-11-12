#include <stdio.h>

int lerSapatos (int n) {
  int i, j, m, ms[n], p = 0;
  char l, ls[n];

  for (i = 0; i < n; ++i) {
    scanf("%d %c", &m, &l);
    if ((m < 30 | m > 60) | (l != 'D' & l != 'E')) break;
    
    for (j = i - 1; j >= 0; --j) {
      if (ms[j] != 0 & ms[j] == m & ls[j] != l) {
        p++;
        m = 0;
        ms[j] = 0;
        break;
      }
    }

    ms[i] = m;
    ls[i] = l;
  }

  return p;
}

int main () {
  int n, i, j, m, p = 0;
  char l;

  while (scanf("%d", &n) != EOF) {
    int ms[n];
    char ls[n];
    if (n % 2 == 0) {
      p = 0;
      for (i = 0; i < n; ++i) {
        scanf("%d %c", &m, &l);
        if ((m < 30 | m > 60) | (l != 'D' & l != 'E')) break;
    
        for (j = i - 1; j >= 0; --j) {
          if (ms[j] != 0 & ms[j] == m & ls[j] != l) {
            p++;
            m = 0;
            ms[j] = 0;
            break;
          }
        }

        ms[i] = m;
        ls[i] = l;
      }

      printf("%d\n", p); 
    }
  }

  return 0;
}
