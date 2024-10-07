/* file   :     template.c                               */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Tue Oct 1 2024                           */
/* version:     1.0                                      */

/* Description:
 * solves a word puzzle and then prints the remaining characters
 */

#include <stdio.h>
#include <stdlib.h>

// cell of a puzzle
typedef struct {
  int obfuscated;
  char a;
} cell;

// look in 4 directions, return if found
int findInPuzzle(int n, char word[], cell puzzle[][20], int length) {
  int found = 0;
  // look horizontal
  for (int row = 0; (row < n) && !found; row++) {
    for (int col = 0; col + length <= n; col++) {
      for (int i = 0; i < length; i++) {
        if (puzzle[row][col + i].a != word[i]) {
          break;
        }
        if (i + 1 == length) {
          found = 1;
          for (int i = 0; i < length; i++) {
            puzzle[row][col + i].obfuscated = 1;
          }
        }
      }
    }
  }
  // look vertical
  for (int row = 0; (row + length <= n) && !found; row++) {
    for (int col = 0; col < n; col++) {
      for (int i = 0; i < length; i++) {
        if (puzzle[row + i][col].a != word[i]) {
          break;
        }
        if (i + 1 == length) {
          found = 1;
          for (int i = 0; i < length; i++) {
            puzzle[row + i][col].obfuscated = 1;
          }
        }
      }
    }
  }
  // look diagonal down
  for (int row = 0; (row + length <= n) && !found; row++) {
    for (int col = 0; col + length <= n; col++) {
      for (int i = 0; i < length; i++) {
        if (puzzle[row + i][col + i].a != word[i]) {
          break;
        }
        if (i + 1 == length) {
          found = 1;
          for (int i = 0; i < length; i++) {
            puzzle[row + i][col + i].obfuscated = 1;
          }
        }
      }
    }
  }
  // look diagonal up
  for (int row = length - 1; (row < n) && !found; row++) {
    for (int col = 0; col + length <= n; col++) {
      for (int i = 0; i < length; i++) {
        if (puzzle[row - i][col + i].a != word[i]) {
          break;
        }
        if (i + 1 == length) {
          found = 1;
          for (int i = 0; i < length; i++) {
            puzzle[row - i][col + i].obfuscated = 1;
          }
        }
      }
    }
  }
  return found;
}

// prints all cell characters that are not obfuscated
void printWord(int n, cell puzzle[][20]) {
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (puzzle[row][col].obfuscated == 0) {
        printf("%c", puzzle[row][col].a);
      }
    }
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int n;
  cell puzzle[20][20];
  char word[21];
  char invert[20];
  int length = 0;
  // initialize word
  for (int i = 0; i < 21; i++) {
    word[i] = '\0';
  }

  (void)scanf("%d ", &n);
  // fill puzzle with values and initialize obfuscated
  char c;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      (void)scanf("%c ", &c);
      puzzle[row][col].a = c;
      puzzle[row][col].obfuscated = 0;
    }
  }
  while (scanf("%s", word) == 1 && word[0] != '.') {
    while (word[length] != '\0') {
      length++;
    }
    // invert word
    for (int i = length; i > 0; i--) {
      invert[i - 1] = word[length - i];
    }
    // check if the word can be found in 4 directions, if it cant, invert and
    // check again, this is the same as checking all 4 directions
    if (!findInPuzzle(n, word, puzzle, length)) {
      findInPuzzle(n, invert, puzzle, length);
    }
    // reset everything
    for (int i = 0; i < 21; i++) {
      word[i] = '\0';
    }
    for (int i = 0; i < 20; i++) {
      invert[i] = '\0';
    }
    length = 0;
  }
  printWord(n, puzzle);
  return 0;
}
