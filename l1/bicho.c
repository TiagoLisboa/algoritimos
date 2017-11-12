#include <stdio.h>

int main () {
  int n = 1, m = 1;
  double v = 1;
  int auxn, auxm; 

  while (n | m | v != 0.0) {
    scanf("%lf %d %d", &v, &n, &m);

    if (n >= 0 & n <= 1000000 & m >= 0 & m <= 1000000) {
      if (v == 0.0 & n == 0 & m == 0) break;

      auxn = n % 10000;
      auxm = m % 10000;
      
      if (auxn == auxm) {
        printf("%.2f\n", v * 3000);
        continue;
      }
      
      auxn = n % 1000;
      auxm = m % 1000;

      if (auxm == auxn) {
        printf("%.2f\n", v * 500);
        continue;
      }

      auxn = n % 100;
      auxm = m % 100;


      if (auxm == auxn) {
        printf("%.2f\n", v * 50);
        continue;
      }

      int f1 = n % 100, f2 = m % 100;
      int g1 = f1 == 0 ? 97 : ((f1 - 1) / 4) * 4 + 1;
      int g2 = f2 == 0 ? 97 : ((f2 - 1) / 4) * 4 + 1;
      if (g1 == g2) {
        printf("%.2f\n", v * 16);
      } else {
        printf("0.00\n");
      }   
    }
  }

  return 0;
}
