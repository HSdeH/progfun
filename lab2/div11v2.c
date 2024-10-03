/* file   :     div11v2.c                                */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Sat Sep 21 2024                          */
/* version:     2.1                                      */

/* Description:
 * checks if an input is divisible by 11 and shows the steps, now takes way
 * larger inputs
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char a;
  int result = 0, resultHolder, resultLength, finalAnswer;
  /*this first loop reads every single character from the input and then parses
  it showing the steps, while adding or deducting each digit from result*/
  int iterator = 0;
  while (scanf("%c", &a) == 1 && a != '\n') {
    if (iterator % 2 == 0) {
      printf("+%c", a);
      result += a - '0';
    } else {
      printf("-%c", a);
      result -= a - '0';
    }
    iterator++;
  }
  printf("=%d\n", result);
  /*the second loop, does the same if the absolute of result is still larger
  than 10, except it does so with an integer, as with a max input of 10^1000 the
  largest result can be at most 4 digits long it should be possible with just an
  integer this time, also I already had this code lying around from my previous
  attempt*/
  while (result > 10 || result < -10) {
    /*make result its absolute and then find its length*/
    if (result < 0) {
      result = -result;
    }
    resultHolder = result;
    resultLength = 0;
    do {
      resultLength++;
      resultHolder /= 10;
    } while (resultHolder > 0);
    /*parse the steps*/
    finalAnswer = 0;
    for (int i = 0; i < resultLength; i++) {
      resultHolder = result;
      for (int j = 1; j < (resultLength - i); j++) {
        resultHolder /= 10;
      }
      resultHolder %= 10;
      if (i % 2 == 0) {
        printf("+%d", resultHolder);
        finalAnswer += resultHolder;
      } else {
        printf("-%d", resultHolder);
        finalAnswer -= resultHolder;
      }
    }
    printf("=%d\n", finalAnswer);
    result = finalAnswer;
  }
  /*prints answer to if 11 is a divisor of the input, if result is anything but
  0, it means it's not divisible and the if statement evaluates it as true, if
  it is 0 it gets evaluated as false and thus it is divisible by 11*/
  if (result) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  return 0;
}
