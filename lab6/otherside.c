/* file   :     otherside.c                              */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Wed Oct 16 2024                          */
/* version:     1.0                                      */

/* Description:
 * recursively find the cheapest path to the other side
 */

#include <stdio.h>
#include <stdlib.h>

int traverse(int x, int y, int rows, int cols, int **grid, int **vGrid);

int main(int argc, char **argv) {
  // input
  int rows, cols;
  (void)scanf("%d %d", &rows, &cols);
  int **grid = malloc(sizeof(int *) * rows),
      **valueGrid = malloc(sizeof(int *) * rows);
  for (int row = 0; row < rows; row++) {
    grid[row] = malloc(sizeof(int) * cols);
    valueGrid[row] = malloc(sizeof(int) * cols);
    for (int col = 0; col < cols; col++) {
      valueGrid[row][col] = -1;
      (void)scanf("%d", &grid[row][col]);
    }
  }

  // use recursive function traverse for every entry point, take the cheapest
  int cheapest = traverse(0, 0, rows, cols, grid, valueGrid);
  int temp;
  for (int row = 1; row < rows; row++) {
    temp = traverse(0, row, rows, cols, grid, valueGrid);
    if (temp < cheapest) {
      cheapest = temp;
    }
  }
  // print and free
  printf("%d\n", cheapest);
  for (int row = 0; row < rows; row++) {
    free(valueGrid[row]);
    free(grid[row]);
  }
  free(valueGrid);
  free(grid);
  return 0;
}

// if in the final column, return its value, else return current value + the
// cheapest possible traversal route, checks if a value for the smallest subpath
// has been already found and return that instead if possible
int traverse(int x, int y, int rows, int cols, int **grid, int **vGrid) {
  if (vGrid[y][x] != -1) {
    return vGrid[y][x];
  }
  if (x + 1 == cols) {
    return grid[y][x];
  }
  int temp;
  int smallest = traverse(x + 1, y, rows, cols, grid, vGrid);
  if (!(y + 1 == rows)) {
    temp = traverse(x + 1, y + 1, rows, cols, grid, vGrid);
    if (temp < smallest) {
      smallest = temp;
    }
  }
  if (!(y == 0)) {
    temp = traverse(x + 1, y - 1, rows, cols, grid, vGrid);
    if (temp < smallest) {
      smallest = temp;
    }
  }
  vGrid[y][x] = smallest + grid[y][x];
  return grid[y][x] + smallest;
}
