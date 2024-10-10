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

int findPattern(int *genome, int *pattern);

int main(int argc, char **argv) {
  int e, matches = 0, shift = 0;
  char pattern[100], genome[10000], name[100];
  scanf("%s", pattern);
  scanf("%d", &e);
  int patLen = strlen(pattern);

  char c;
  scanf("%c", &c);
  for (int i = 0; i < e; i++) {
    while((scanf("%c", &c) == 1) && (c != '\n')) {
  
    }
    // process a single line
  }
  for (int i = 0; i < matches; i++) {
    // print name and shift here
  }
  printf(matches != 1 ? "%d matches found.\n" : "1 match found.\n", matches);
  return 0;
}

int findPattern(int *genome, int *pattern) {

}