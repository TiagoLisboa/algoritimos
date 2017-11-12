#include <stdio.h>
#include <math.h>


int main () {
  int d, vf, vg;
  double h, tf, tg;

  while (scanf("%d %d %d", &d, &vf, &vg) != EOF) { 
    if (d >= 1 & d <= 100 & vf >= 1 & vf <= 100 & vg >= 1 & vg <= 100) {
      double x = pow(d, 2);
      double y = pow(12.0, 2);
      h = sqrt(x + y);
      tg = h/vg;
      tf = 12.0/vf;

      tg <= tf ? printf("S\n") : printf("N\n");
    }
  }

  return 0;
}
