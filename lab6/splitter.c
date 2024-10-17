/* file   :     splitter.c                               */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Wed Oct 16 2024                          */
/* version:     1.0                                      */

/* Description:
 * orders and attempts to split an array of numbers
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int *array = malloc(sizeof(int));

  // scan input
  int i = 0;
  while (scanf("%d", &array[i]) == 1 && (array[i] != 0)) {
    array = realloc(array, (i + 2) * sizeof(int));
    i++;
  }

  // order them
  int temp;
  for (int j = 0; j < i - 1; j++) {
    for (int k = j + 1; k < i; k++) {
      if (array[j] > array[k]) {
        temp = array[j];
        array[j] = array[k];
        array[k] = temp;
      }
    }
  }

  // check if its balanced or not
  int median = array[i / 2];
  int a = 0, b = 0;
  for (int j = 0; j < i; j++) {
    if (array[j] < median) {
      a++;
    }
    if (array[j] > median) {
      b++;
    }
  }
  // printf("a: %d, b: %d\n", a, b);
  printf(a == b ? "%d\n" : "UNBALANCED\n", median);
  free(array);
  return 0;
}
