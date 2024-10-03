/* file   :     mulpals.c                                */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Fri Sep 20 2024                          */
/* version:     2.0                                      */

/* Description:
 * finds the amount of mulpals from a to b
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, b;
  /*various helper variables*/
  int aLength, aLengthStore, aStore;
  int mulpalCount = 0;
  int n = scanf("%d %d", &a, &b);
  int product;
  /*the main loop, for every single digit between a and b perform the test for a
  mulpal, if an a has been tested it is not necessary anymore and thus the new
  a will become a+1 until a becomes b*/
  for (; a <= b; a++) {
    /*find a's length by counting how many times it can be div'd by 10 before
     * becoming 0, reset the variables for every new loop*/
    aLength = 0;
    aStore = a;
    while (aStore > 0) {
      aStore /= 10;
      aLength++;
    }
    aStore = a;
    /*in this loop, d*a is calulated and compared to a to see if its a mulpal, I
    don't know exactly what the right upper bound for d is but it can't be more
    than 9 at least because then the product would be bigger than a, if a mulpal
    is found the loop is ended because one integer can't be a mulpal multiple
    times*/
    aLengthStore = aLength;
    for (int d = 1; d < 10; d++) {
      product = a * d;
      aLength = aLengthStore;
      /*this loop works as the following: as long as aLength is more than 1 the
      first digit of aStore gets compared to the last digit of product, if they
      are equal, aLength gets reduced and the second digit of aStore get
      compared to the second to last digit of product, this works by div'ing
      product by 10, this continues until aLength becomes 1*/
      while (aLength > 1) {
        aStore = a;
        for (int i = 1; i < aLength; i++) {
          aStore /= 10;
        }
        if (aStore % 10 == product % 10) {
          product /= 10;
        } else {
          break;
        }
        aLength--;
      }
      /*final check comparing the final digit of a compared to (what's left of)
      product, if it's true, the mulpal count gets increased by one and the
      loop stops*/
      if (a % 10 == product) {
        mulpalCount++;
        break;
      }
    }
  }
  printf("%d\n", mulpalCount);
  return 0;
}
