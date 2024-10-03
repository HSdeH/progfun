/* file   :     template.c                               */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Tue Oct 1 2024                           */
/* version:     1.0                                      */

/* Description:
 * solves a word puzzle and then prints the remaining characters
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
 int obfuscated;
 char a;
} cell;

void findInPuzzle(int n, char word[], cell puzzle[][20]) {

}

void printWord(int n, cell puzzle[][20]) {
  for(int row = 0; row < n; row++) {
    for(int col = 0; col < n; col++) {
      if (puzzle[row][col].obfuscated == 0) {
        printf("%c", row, col, puzzle[row][col].a);  
      }
    }
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int n;
  cell puzzle[20][20];
  char word[20];
  char wordInvert[20];
  (void) scanf("%d ", &n);

  // fill puzzle with values and initialize obfuscated 
  char c;
  for(int row = 0; row < n; row++) {
    for(int col = 0; col < n; col++) {
      (void) scanf("%c ", &c);
      puzzle[row][col].a = c;
      puzzle[row][col].obfuscated = 0;
    }
  }
  while (scanf("%s", word) == 1 && word[0] != '.') {
    findInPuzzle(n, word, puzzle);
    // reset word[]
    for (int i = 0; i < 20; i++) {
      word[i] = '\0';
    }
  }
  printWord(n, puzzle);
  return 0;
}
