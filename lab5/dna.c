/* file   :     dna.c                                    */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Tue Oct 8 2024                           */
/* version:     1.0                                      */

/* Description:
 * desc
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// returns 1 if found
int checkSeq(char *pattern, char *sequence, int *shift) {
  int test = strlen(sequence)-strlen(pattern);
  int seqlen = strlen(sequence);
  int patlen = strlen(pattern);
  for (int i = 0; i < test; i++) {
    for (int j = 0; j < strlen(pattern); j++) {
      if (pattern[j] != sequence[i + j]) {
        break;
      }
      if (j == strlen(pattern)-1) {
        *shift = i;
        return 1;
      }
    }
  }
  return 0;
}

int main(int argc, char **argv) {
  char pattern[100], name[1000], sequence[10000];
  char names[100][1000];
  int shifts[10];
  int e, matches = 0, shift = 0;
  // read first parts
  scanf("%s", pattern);
  scanf("%d ", &e);
  for (int i = 0; i < e; i++) {
    // read name
    int j = 0;
    while ((scanf("%c", &name[j]) == 1) && (name[j] != ':')) {
      j++;
    }
    name[j] = '\0';
    // read sequence
    j = 0;
    while (scanf("%c", &sequence[j]) == 1 && (sequence[j] != '\n')) {
      j++;
    }
    sequence[j] = '\0';
    // check if its there
    if (checkSeq(pattern, sequence, &shift)) {
      strcpy(names[matches], name);
      shifts[matches] = shift;
      matches++;
    }
  }
  // print results
  for (int i = 0; i < matches; i++) {
    printf("%s", names[i]);
    printf(": shift=%d\n", shifts[i]);
  }
  printf(matches != 1 ? "%d matches found.\n" : "%d match found.\n", matches);
  return 0;
}
