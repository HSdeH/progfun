/* file   :     div13.c                                  */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Fri Sep 20 2024                          */
/* version:     1.1                                      */

/* Description:
 * checks if an input is divisible by 13 and shows the steps involved
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int inputOutput;
  int n = scanf("%d", &inputOutput);
  /*if the input number is larger than 2 decimal digits, add all but the last
  digit to 4 times the last digit, repeat with the output until it's 2
  digits*/
  while (inputOutput > 99) {
    printf("%d->", inputOutput);
    inputOutput = (inputOutput % 10) * 4 + inputOutput / 10;
  }
  printf("%d=", inputOutput);

  /*find both the div and mod with a while loop*/
  int iterator = 0;
  while (inputOutput > 12) {
    inputOutput -= 13;
    iterator++;
  }
  printf("%d*13+%d\n", iterator, inputOutput);

  /*if output is anything but 0 the if statement will be true, so it will print
  NO, because any number but 0 means it is not divisable by 13, else it must be
  0, so it prints YES*/
  if (inputOutput) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  return 0;
}
