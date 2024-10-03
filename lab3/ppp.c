/* file   :     ppp.c                                      */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl)   */
/* date   :     Mon Sep 23 2024                            */
/* version:     1.0                                        */

/* Description:
 * finds out if a number is a Proth number/panlindromic Proth
 * number/panlindromic Proth prime/Proth prime
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
/*if number is a prime return 1, if it isn't return 0*/
int isPrime(int number) {
  /*check for 1*/
  if (number == 1) {
    return 0;
  }
  /*check if number can be divided by any number, from 2 to sqrt(number),
  because 2 * 3 is the same as 3 * 2 and it would be redundant to calculate
  it again*/
  for (int i = 2; i * i <= number; i++) {
    if (number % i == 0) {
      return 0;
    }
  }
  return 1;
}
/*determines if a number is a Proth number*/
int isProth(int number) {
  int k, n = 0;
  if (number % 2 == 0) {
    return 0;
  }
  number -= 1;
  while (number % 2 == 0) {
    number /= 2;
    n++;
  }
  k = number;
  if ((k % 2 == 0) || (k > intPow(2, n))) {
    return 0;
  }
  return 1;
}
/*returns number reverted */
int reverseNumber(int number) {
  int reverse = 0;
  while (number > 0) {
    reverse = reverse * 10 + number % 10;
    number /= 10;
  }
  return reverse;
}
/*determines if a number is a palindrome*/
int isPalindrome(int number) {
  if (number == reverseNumber(number)) {
    return 1;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int input;
  int n = scanf("%d", &input);
  /*just check all the possible states, then print accordingly*/
  if (isProth(input)) {
    if (isPalindrome(input)) {
      if (isPrime(input)) {
        printf("%d is a palindromic Proth prime.\n", input);
      } else {
        printf("%d is a palindromic Proth number.\n", input);
      }
    } else if (isPrime(input)) {
      printf("%d is a Proth prime.\n", input);
    } else {
      printf("%d is a Proth number.\n", input);
    }
  } else {
    printf("%d is not a Proth number.\n", input);
  }
  return 0;
}
