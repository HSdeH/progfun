/* file   :     lastdigits.c                               */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl)   */
/* date   :     Mon Sep 23 2024                            */
/* version:     1.0                                        */

/* Description:
 * given as input a, e, and n, give the last n digits from a^e
 */

#include <stdio.h>
#include <stdlib.h>

/*calculates powers for integers*/
int intPow(int base, int power) {
  int result = 1;
  while (power > 0) {
    result = result * base;
    power--;
  }
  return result;
}
/*prints the correct amount of digits (adds 0s)*/
void printDigits(int number, int numberOfDigits) {
  int numberStore = number;
  int length = 0;
  if (number == 0) {
    length++;
  }
  while (numberStore > 0) {
    numberStore /= 10;
    length++;
  }
  while ((numberOfDigits - length) > 0) {
    printf("0");
    length++;
  }
  printf("%d\n", number);
}

int main(int argc, char *argv[]) {
  // works because of modular arithmetic
  int a, e, n;
  int result = 1;
  scanf("%d %d %d", &a, &e, &n);
  /*turn n into an mod operand so it takes the last n digits*/
  int nPow = intPow(10, n);
  a = a % nPow;
  /*these are all the same in modular arithmatic, so continue lowering e until
  it's entirely reduced to 1, this is done by halving or deducting by 1 if
  e is odd, checks for 0*/
  while (e > 1) {
    if (e % 2 == 1) {
      // update result make sure it doesn't overflow either
      result = (result * a) % nPow;
      e--;
    } else {
      e /= 2;
      a = (a * a) % nPow;
    }
  }
  result *= a;
  result %= nPow;
  if (e == 0) {
    result = 0;
  }
  printDigits(result, n);
  return 0;
}
