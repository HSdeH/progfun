/* file   :     whosnext.c                               */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Wed Oct 16 2024                          */
/* version:     1.0                                      */

/* Description:
 * gives the lexicographic successor of a given permutation
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char *array = malloc(sizeof(char));
  // get input
  int scan = 0;
  while (scanf("%c", &array[scan]) == 1 && (array[scan] != '.')) {
    array = realloc(array, sizeof(char) * (scan + 3));
    scan++;
  }
  array[scan] = '\0';

  char temp;
  char smallestBigger;
  int sbIdx;
  // find (if) from the right a character is bigger than the one to its left
  for (int i = scan + 1; i > 0; i--) {
    // if there is, find the smallest character that is still bigger than its
    // left
    if (array[i] > array[i - 1]) {
      smallestBigger = array[i];
      sbIdx = i;
      for (int j = i; j < scan; j++) {
        if (array[j] > array[i - 1]) {
          if (array[j] < smallestBigger) {
            smallestBigger = array[j];
            sbIdx = j;
          }
        }
      }
      // swap them
      temp = array[i - 1];
      array[i - 1] = array[sbIdx];
      array[sbIdx] = temp;

      // order the rest
      for (int j = i; j < scan; j++) {
        for (int k = j + 1; k < scan; k++) {
          if (array[j] > array[k]) {
            temp = array[j];
            array[j] = array[k];
            array[k] = temp;
          }
        }
      }
      break;
    }
  }
  printf("%s\n", array);
  free(array);
  return 0;
}
