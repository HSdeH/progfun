/* file   :     arrred.c                                 */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Mon Oct 7 2024                           */
/* version:     1.0                                      */

/* Description:
 * remove the largest integer of an array if the sum of the other integers is
 * the largest number
 */

#include <stdio.h>
#include <stdlib.h>

// return 1 if it has been reduced
int redArray(int n, int **arr) {
  int biggest = 0, total = 0, *p;
  // sum everything and find the biggest
  for (int i = 0; i < n; i++) {
    if ((*arr)[i] > biggest) {
      biggest = (*arr)[i];
    }
    total += (*arr)[i];
  }
  // check if the biggest is the sum of the rest, if it is reduce the size of
  // the array
  if (biggest == (total - biggest)) {
    p = malloc((n - 1) * sizeof(int));
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
      if ((*arr)[j] == biggest) {
        j++;
      }
      p[i] = (*arr)[j];
      j++;
    }
    // free arr before making it point to the new memory block
    free(*arr);
    *arr = p;
    return 1;
  }
  return 0;
}
int main(int argc, char *argv[]) {
  int n;
  int *arr;
  (void)scanf("%d:", &n);
  // allocate enough memory, and then fill the array
  arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    (void)scanf("%d", &arr[i]);
  }
  // repeat until the condition is false and you're left with the right n
  while (redArray(n, &arr)) {
    n--;
  }
  printf("%d\n", n);
  free(arr);
  return 0;
}
