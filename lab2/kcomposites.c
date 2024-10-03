/* file   :     kcomposites.c                            */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Fri Sep 20 2024                          */
/* version:     1.1                                      */

/* Description:
 * finds the smallest k-composite
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int k, candidate;
  int n = scanf("%d", &k);
  /*this loop simply bruteforces the problem, the loops creates a canditate by
  multiplying it with i and then checks if all integers smaller than k can
  divide the candidate without a remainder, if it can, then candidate is the
  k-composite, else i increments, this loop does not end until a k-composite has
  been found*/
  int i = 1, j;
  while (1) {
    candidate = k * i;
    j = 1;
    /*every integer below k gets checked, if it fails this loop ends*/
    while (j < k) {
      if ((candidate % (k - j)) == 0) {
        j++;
      } else {
        break;
      }
    }
    /*final check, if j has become k it means every digit below k can divide
    candidate, and thus it is the smallest k-composite and first that has
    been found*/
    if (j == k) {
      printf("%d\n", candidate);
      break;
    }
    i++;
  }
  return 0;
}
