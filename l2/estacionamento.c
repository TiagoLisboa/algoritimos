#include <stdio.h>

void mostar (int est[], int c) {
  int i;
  for(i = 0; i < c; i++) {
    printf("%d\n", est[i]);
  }
}

void remover (int est[], int c) {
  int i, p;
  
  scanf ("%d", &p);

  for (i = 0; i < c; i++) 
    if (est[i] == p) est[i] = 0;

}

int entrada (int est[], int c) {
  int i, j, p, q, tmp = 1;

  scanf("%d %d", &p, &q);

  if (q > c) return 0;

  for (i = 0; i < c; i++)
    if (est[i] == p) return 0;

  for (i = 0; i < c; i++) { 
    if (est[i] == 0 & i + q - 1 < c) {
      tmp = 1;
      for (j = 0; j < q; j++) {
        if (est[j + i] != 0) {
          tmp = 0;
          break;
        }
      }
      if (tmp == 1) {
        for (j = 0; j < q; j++)
          est[j + i] = p;
        return 1;
      }
    }
  }

  return 0;
}

int main () {
  int c, n, t;
  char op;


  while (scanf("%d %d", &c, &n)!= EOF) {
    int est[c];
    int i;
    t = 0;

    for (i = 0; i < c; i++)
      est[i] = 0;
    

    while (n-- > 0) {
      scanf(" %c", &op);
      
      if (op == 'C' | op == 'c') {
        if (entrada(est, c) == 1) t++;
      } else if (op == 'M') {
        mostar(est, c);
      } else if (op == 'S' | op == 's') {
        remover(est, c);
      }
    }

    printf("%d\n", t*10);

    
  }

  return 0;
}
