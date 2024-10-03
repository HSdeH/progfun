/* file   :     pangram.c                                */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Tue Oct 1 2024                           */
/* version:     1.0                                      */

/* Description:
 * prints out if a sentence is a pangram or not
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int found = 0;
  int total = 0;
  char a;
  char abc[26] = {0};
  // scan every character until '.'
  while (scanf("%c", &a) == 1 && (a != '.')) {
    found = 0;
    if (a == ' ') {
      continue;
    }
    // check if it can find the character in the abc array (it starts empty)
    for (int i = 0; i < 26; i++) {
      if (abc[i] == a) {
        found = 1;
      }
    }
    // if it doesnt find it in abc, add it and also increment total
    if (!found) {
      total++;
      for (int i = 0; i < 26; i++) {
        if (abc[i] == 0) {
          abc[i] = a;
          break;
        }
      }
    }
  }
  // print final result, if total is 26 its a pangram
  if (total == 26) {
    printf("PANGRAM\n");
  } else {
    printf("NO PANGRAM\n");
  }
  return 0;
}
