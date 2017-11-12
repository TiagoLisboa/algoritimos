#include <stdio.h>

int descobrirVencedor (int j, int r, int rodadas[]) {
  int jr = j * r, i, v, ja = 0;
  int jogadores[j];

  for (i = 0; i < j; ++i) {
    jogadores[i] = 0;
  }

  for (i = 0; i < jr; ++i) {
    jogadores[ja] += rodadas[i];
    ja = ++ja >= j ? 0: ja;
  }

  v = 0;

  for (i = 1; i < j; ++i) {
    v = jogadores[v] <= jogadores[i] ? i : v;
  }
  
  return v + 1;
}

void contarRodadas(int j, int r) {
  int jr = j * r, i, x;
  int rodadas[jr];

  for (i = 0; i < jr; ++i) {
    scanf("%d", &x);
    rodadas[i] = x;
  }

  printf("%d\n", descobrirVencedor (j, r, rodadas));
}

int main () {
  int j, r;

  scanf ("%d %d", &j, &r);

  contarRodadas(j, r);

  return 0;
}
