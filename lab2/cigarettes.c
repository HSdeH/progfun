/* file   :     cigarettes.c                             */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Fri Sep 20 2024                          */
/* version:     2.0                                      */

/* Description:
 * calculates how much cigarettes a homeless man can smokes with n butts
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int butts, cigarettesSmoked;
  int n = scanf("%d", &butts);
  /*simply div the amount of butts by 3 for the answer, remove 1 to account for
  the fact that you can't materialize the butt you'd get from smoking a full
  cigarette before actually smoking it*/
  butts--;
  cigarettesSmoked = butts / 3;
  /*1.0 code: as long as there are more than 3 butts, remove 4 butts and add 1
  back, so remove 3, and then increment cigarettesSmoked, in the old code
  cigarettesSmoked was initialized to 0*/
  //   while(butts > 3) {
  //     butts -= 3;
  //     cigarettesSmoked++;
  //   }
  printf("%d\n", cigarettesSmoked);
  return 0;
}
