/* file   :     dataswap.c                               */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Mon Oct 7 2024                           */
/* version:     1.0                                      */

/* Description:
 * swap integers in an array and check if its ordered or not after
 */

#include <stdio.h>
#include <stdlib.h>

// swap the arrays at the index
void swap(int idx0, int idx1, int *arr) {
  int temp;
  temp = arr[idx0];
  arr[idx0] = arr[idx1];
  arr[idx1] = temp;
}

// check if ordered correctly
int checkIfOrdered(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int n;
  int *arr;
  int idx0, idx1;

  (void)scanf("%d ", &n);
  // allocate enough memory, and then fill the array
  arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    (void)scanf("%d", &arr[i]);
  }
  // scan and process input
  while (scanf("%d %d", &idx0, &idx1) == 2 && !(idx0 == 0 && idx1 == 0)) {
    swap(idx0, idx1, arr);
  }
  printf(checkIfOrdered(arr, n) ? "YES\n" : "NO\n");
  free(arr);
  return 0;
}
