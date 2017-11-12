#include <stdio.h>
#include <string.h>

int main () {
  int l, c, i, j, CONTINUA = 1;

  scanf ("%d %d", &l, &c);
  char matriz[l][c][255];
  int matrizV[l][c];
  int linhas[l];
  int colunas[c];

  for (i = 0; i < l; i++) {
    for (j = 0; j < c; j++) {
      matrizV[i][j] = -100000001;
      scanf ("%s", matriz[i][j]);
    }
    scanf ("%d", &linhas[i]);
  }

  for (i = 0; i < c; i++) {
    scanf("%d", &colunas[i]);
  }


  while (CONTINUA) {
    /*VARREDURA DAS LINHAS*/
    char *variavel;
    int acho = 0, valVar, qtd;

    for (i = 0; i < l; i++) {
      for (j = 0; j < c; j++) {
        if (matrizV[i][j] == -100000001) {
          variavel = matriz[i][j];
          break;     
        }
      }
      /*if (j == c-1) {
        continue;
      }*/
      for (; j < c; j++) {
        if ((strcmp(matriz[i][j], variavel) != 0) & (matrizV[i][j] == -100000001)) {
          acho = 0;
          break;
        } else {
          acho = 1;
        }
      }
      if (acho) {
        valVar = linhas[i];
        qtd = c;
        for (j = 0; j < c; j++) {
          if (matrizV[i][j] != -100000001) {
            valVar -= matrizV[i][j];
            qtd--;
          }
        }
        break;
      }
    }
    
    if (acho) {
      for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
          if (strcmp(matriz[i][j], variavel) == 0){
            matrizV[i][j] = valVar/qtd;
          }
        }
      }
      continue;
    }
    /* VARREDURA DE COLUNAS */

    for (j = 0; j < c; j++) {
      for (i = 0; i < l; i++) {
        if (matrizV[i][j] == -100000001) {
          variavel = matriz[i][j];
          break;
        }
      }
      /*if (i == l-1) {
        continue;
      }*/
      for (; i < l; i++) {
        if ((strcmp(matriz[i][j], variavel) != 0) & (matrizV[i][j] == -100000001)) {
          acho = 0;
          break;
        } else {
          acho = 1;
        }
      }
      if (acho) {
        valVar = colunas[j];
        qtd = l;
        for (i = 0; i < l; i++) {
          if (matrizV[i][j] != -100000001) {
            valVar -= matrizV[i][j];
            qtd--;
          }
        }
        break;
      }
    }

    if (acho) {
      for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
          if (strcmp(matriz[i][j], variavel) == 0){
            matrizV[i][j] = valVar/qtd;
          }
        }
      }
      continue;
    }
    CONTINUA = 0;
    for (i = 0; i < l; i++) {
      for (j = 0; j < c; j++) {
        if (matrizV[i][j] == -100000001) {
          CONTINUA = 1;
          break;
        }
      }
      if (CONTINUA) break;
    }
    

  }
  
  char cres[255];
  int x, acho, aux;

  strcpy(cres, matriz[0][0]);

  
  for (x = 0; x < l*c; x++) {
    strcpy(cres, "zz");
    acho = 0;
    for (i = 0; i < l; i++) {
      for (j = 0; j < c; j++){
        if ((matriz[i][j][0] != 'Z' && matriz[i][j][0] < cres[0]) || (matriz[i][j][0] == cres[0] && matriz[i][j][1] <= cres[1])) {
          strcpy(cres, matriz[i][j]);
          aux = matrizV[i][j];
          acho = 1;
        }
      }
    }
    if (acho == 0) break;
    for (i = 0; i < l; i++) {
      for (j = 0; j < c; j++) {
        if (strcmp(matriz[i][j], cres) == 0) {
          strcpy(matriz[i][j], "ZZ");
        }
      }
    }
    printf("%s %d\n", cres, aux);
  }

  

  return 0;
}
