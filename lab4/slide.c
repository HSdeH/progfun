/* file   :     slide.c                                  */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Tue Oct 1 2024                           */
/* version:     1.0                                      */

/* Description:
 * checks if a sliding puzzle is solved given a few moves
 */

#include <stdio.h>
#include <stdlib.h>

// returns if the cube is solved or not
int checkIfSolved(int n, int cube[][8]) {
  int zeroNotPassed = 1;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (!cube[row][col]) {
        zeroNotPassed--;
        continue;
      }
      if (cube[row][col] != (row * n + col + zeroNotPassed)) {
        return 0;
      }
    }
  }
  return 1;
}

// execute the intructions, returns if valid or not
int execute(int n, char instr[], int cube[][8]) {
  int target;
  int targetLoc[2];
  int zeroLoc[2];
  (void)scanf("%d", &target);
  // find and swap 0 and the target
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (cube[row][col] == target) {
        targetLoc[0] = row;
        targetLoc[1] = col;
        cube[row][col] = 0;
      } else if (cube[row][col] == 0) {
        zeroLoc[0] = row;
        zeroLoc[1] = col;
        cube[row][col] = target;
      }
    }
  }
  // edit targetLock depending on the instruction
  switch (instr[0]) {
    case 'L':
      targetLoc[1]--;
      break;
    case 'R':
      targetLoc[1]++;
      break;
    case 'U':
      targetLoc[0]--;
      break;
    case 'D':
      targetLoc[0]++;
      break;
    default:
      break;
  }
  // if targetLoc and zeroLoc are the same it should be correct, this also
  // automatically checks bounds because zeroLoc is found from within the bounds
  return ((targetLoc[0] == zeroLoc[0]) && (targetLoc[1] == zeroLoc[1]));
}

int main(int argc, char *argv[]) {
  int valid = 1;
  int n;
  int cube[8][8];
  char instr[5];
  int op;
  scanf("%d", &n);
  // load the cube with the values
  int x;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      scanf("%d", &x);
      cube[row][col] = x;
    }
  }
  // scan instructions
  while ((scanf("%s", instr) == 1) && (instr[0] != 'E')) {
    if (!execute(n, instr, cube)) {
      valid = 0;
      printf("INVALID\n");
      break;
    }
  }
  if (valid) {
    // solved or unsolved
    printf(checkIfSolved(n, cube) ? "SOLVED\n" : "UNSOLVED\n");
  }
  return 0;
}
