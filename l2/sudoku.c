#include <stdio.h>

int main () {
  int n, i, j, x, l, c, certo = 1;
  
  scanf ("%d", &n);

  int t = n;
  int sudoku [9][9];

  while (n-- > 0) {
    certo = 1;
    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        scanf (" %d", &x);
        sudoku [i][j] = x;
      }
    }

    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        l = sudoku [i][j];
        c = sudoku [j][i];
        for (x = j+1; x < 9; x++) {
          if (sudoku[i][x] == l | sudoku[x][i] == c) {
            certo = 0;
            i = 10;
            j = 10;
            break;
          }
        }

        if ((i == 0 | i%3 == 0) & (j == 0 | j%3 == 0)) {
          int ii, jj, tmp;

          for (ii = 0; ii < 9; ii++) {
            tmp = sudoku [i + ii%3][j + ii/3];
            for (jj = ii+1; jj < 9; jj++) {
              if (tmp == sudoku [i + jj%3][j + jj/3]) {
                certo = 0;
                i = 10;
                j = 10;
                ii = 10;
                jj = 10;
                break;
              }
            }
          }

        }
      }
    }

    printf("Instancia %d\n", t-n);
    printf("%s\n\n", certo ? "SIM" : "NAO");
  }

  return 0;
}
