#include <stdio.h>

int getMaior (int n, int alunos[]) {
  int i, maior = 0;
  
  for (i = 0; i < n; ++i) 
    maior = alunos[i] > maior ? alunos[i] : maior;

  return maior;
  
}

int votacao (int n) {
  int i, j, voto, alunos[n];

  for (i = 0; i < n; ++i) {
    alunos[i] = 0;
  }

  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      scanf("%d", &voto);

      alunos[j] += voto == 1 ? 1 : 0;
      
    }
  }
  return getMaior(n, alunos);
}

int main () {
  int n = 1;

  while (n) {
    scanf("%d", &n);

    if (n == 0) break;
    
    printf("%d\n", votacao(n));
  }

  return 0;
}
