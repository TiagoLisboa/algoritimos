#include <stdio.h>
#include <string.h>

int main () {
  long d = 1, sum;
  char s[32];

  while (d) {
    scanf("%li", &d);

    if (!d) break;
    if ((d < 1) | (d > 2147483647)) continue;
    
    s[0] = '\0';
    sum = 0;

    int remainder;
    long n = d;

  
    while(n != 0) {
      remainder = n%2;
      char st[32];

      sprintf(st, "%d", remainder);
      sprintf(st + strlen(st), "%s", s);
      strcpy(s, st);
      sum += remainder;

      n = n/2;
    }

    printf("The parity of %s is %ld (mod 2).\n", s, sum);
  }


  return 0;
}
