/* file   :     dnav2.c                                  */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Fri Oct 11 2024                          */
/* version:     1.0                                      */

/* Description:
 * checks if a pattern is found in a genome
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LENGTH 1000000

int findPattern(char *, char *, int *);

int main(int argc, char **argv) {
  int n, matches = 0, shift = 0, found = 0;
  char *pattern, numString[10];
  char **text, *name, *genome;
  pattern = malloc(1000000 * sizeof(char));
  scanf("%s", pattern);
  int patLen = strlen(pattern);
  int genLen;
  scanf("%d ", &n);
  char *buffer = calloc(BUFFER_LENGTH, sizeof(char));
  // read and process data
  for (int i = 0; i < n; i++) {
    fgets(buffer, BUFFER_LENGTH, stdin);
    name = strtok(buffer, ":");
    genome = strtok(NULL, "\n");
    if (findPattern(genome, pattern, &shift)) {
      printf("%s: shift=%d\n", name, shift);
      matches++;
    }
  }
  printf(matches != 1 ? "%d matches found.\n" : "1 match found.\n", matches);
  free(buffer);
  free(pattern);
  return 0;
}

// if 0, no pattern was found, if 1 a pattern was found and shift gets set to
// its index
int findPattern(char *genome, char *pattern, int *shift) {
  char *shiftPointer = strstr(genome, pattern);
  if (shiftPointer == NULL) {
    return 0;
  }
  *shift = (shiftPointer - genome);
  return 1;
}
