/* file   :     takuzu.c                                 */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Mon Oct 7 2024                           */
/* version:     1.0                                      */

/* Description:
 * check if a takuzu puzzle is solved correctly or incorrectly
 */

#include <stdio.h>
#include <stdlib.h>

// returns 1 if solved, might have been overcomplicated
int checkIfSolved(int takuzu[][8]) {
  int takLine[8];
  int bordering = 0;
  int line = 0;
  // test if just as much 0 as 1 and if there arent too many digits next to each oher, for both rows and columns
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      if (takuzu[row][col] == 1) {
        line++;
        if (bordering < 0) {
          bordering = 1;
        } else {
          bordering++;
        }
      } else {
        if (bordering > 0) {
          bordering = -1;
        } else {
          bordering--;
        }
      }
      if (bordering > 2 || bordering < -2) {
        return 0;
      }
    }
    if (line != 4) {
      return 0;
    }
    bordering = 0;
    line = 0;
  }
  for (int col = 0; col < 8; col++) {
    for (int row = 0; row < 8; row++) {
      if (takuzu[row][col] == 1) {
        line++;
        if (bordering < 0) {
          bordering = 1;
        } else {
          bordering++;
        }
      } else {
        if (bordering > 0) {
          bordering = -1;
        } else {
          bordering--;
        }
      }
      if (bordering > 2 || bordering < -2) {
        return 0;
      }
    }
    if (line != 4) {
      return 0;
    }
    bordering = 0;
    line = 0;
  }
  //convert the grid into a line again and check for equality, for both rows and cols
  int newTakLine = 0;
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      newTakLine = 10 * newTakLine + takuzu[row][col];
    }
    takLine[row] = newTakLine;
    newTakLine = 0;
  }

  for (int i = 0; i < 7; i++) {
    for (int j = i + 1; j < 8; j++) {
      if (takLine[i] == takLine[j]) {
        return 0;
      }
    }
  }
  newTakLine = 0;
  for (int col = 0; col < 8; col++) {
    for (int row = 0; row < 8; row++) {
      newTakLine = 10 * newTakLine + takuzu[row][col];
    }
    takLine[col] = newTakLine;
    newTakLine = 0;
  }
  for (int i = 0; i < 7; i++) {
    for (int j = i + 1; j < 8; j++) {
      if (takLine[i] == takLine[j]) {
        return 0;
      }
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int takuzu[8][8];
  int takLine[8];
  // read data
  int x;
  // scan single lines
  for (int row = 0; row < 8; row++) {
    (void)scanf("%d", &takLine[row]);
  }
  // convert those lines into a grid
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      takuzu[i][7 - j] = takLine[i] % 10;
      takLine[i] /= 10;
    }
  }
  printf(checkIfSolved(takuzu) ? "CORRECT\n" : "INCORRECT\n");
  return 0;
}
