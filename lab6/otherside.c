/* file   :     otherside.c                              */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Wed Oct 16 2024                          */
/* version:     1.0                                      */

/* Description:
 * recursively find the cheapest path to the other side
 */

#include <stdio.h>
#include <stdlib.h>

int traverse(int x, int y, int rows, int cols, int **grid);

int main(int argc, char **argv) {
  // input
  int rows, cols;
  (void)scanf("%d %d", &rows, &cols);
  int **grid = malloc(sizeof(int *) * rows);
  for (int row = 0; row < rows; row++) {
    grid[row] = malloc(sizeof(int) * rows);
    for (int col = 0; col < cols; col++) {
      (void)scanf("%d", &grid[row][col]);
    }
  }
  // use recursive function traverse, take the cheapest
  int cheapest = traverse(0, 0, rows, cols, grid);
  int temp;
  for (int row = 1; row < rows; row++) {
    temp = traverse(0, row, rows, cols, grid);
    if (temp < cheapest) {
      cheapest = temp;
    }
  }
  // print and free
  printf("%d\n", cheapest);
  for (int row = 0; row < rows; row++) {
    free(grid[row]);
  }
  free(grid);
  return 0;
}

// if in the final column, return its value, else return current value + the
// cheapest possible traversal route
int traverse(int x, int y, int rows, int cols, int **grid) {
  if (x + 1 == cols) {
    return grid[y][x];
  }
  int temp;
  int smallest = traverse(x + 1, y, rows, cols, grid);
  if (y == 0) {
    temp = traverse(x + 1, 1, rows, cols, grid);
    if (temp < smallest) {
      smallest = temp;
    }
  } else if (y + 1 == rows) {
    temp = traverse(x + 1, y - 1, rows, cols, grid);
    if (temp < smallest) {
      smallest = temp;
    }
  } else {
    temp = traverse(x + 1, y - 1, rows, cols, grid);
    if (temp < smallest) {
      smallest = temp;
    }
    temp = traverse(x + 1, y + 1, rows, cols, grid);
    if (temp < smallest) {
      smallest = temp;
    }
  }
  return grid[y][x] + smallest;
}
