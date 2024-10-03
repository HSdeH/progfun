/* file   :     superprime.c                               */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl)   */
/* date   :     Mon Sep 23 2024                            */
/* version:     1.1                                        */

/* Description:
 * find out how many numbers are superprimes between numbers  a and b
 */

#include <stdio.h>
#include <stdlib.h>

/*returns the sum of the digits of number*/
int sumOfDigits(int number) {
  int sum = 0;
  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }
  return sum;
}
/*if number is a prime return 1, if it isn't return 0*/
int isPrime(int number) {
  /*check for 1*/
  if (number == 1) {
    return 0;
  }
  if (number == 2) {
    return 1;
  }
  if (number % 2 == 0) {
    return 0;
  }
  if (number == 3) {
    return 1;
  }
  if (number % 3 == 0) {
    return 0;
  }
  /*check if number can be divided by any number, from 2 to sqrt(number),
  because 2 * 3 is the same as 3 * 2 and it would be redundant to calculate
  it again*/
  for (int i = 4; i * i <= number; i++) {
    if (number % i == 0) {
      return 0;
    }
  }
  return 1;
}
/*checks if a number is a superprime, returns 0 if not, 1 if it is, this would
probably be way better with recursion*/
int isSuperPrime(int number) {
  // first count how many steps of sumOfDigits you need to get to a single digit
  int numberStore = number;
  int iterator = 0;
  while (number > 9) {
    number = sumOfDigits(number);
    iterator++;
  }
  // then check bottom-up if the numbers are primes or not, if any are not return 0
  number = numberStore;
  while (iterator > 0) {
    for (int i = 0; i < iterator; i++) {
      number = sumOfDigits(number);
    }
    if (!isPrime(number)) {
      return 0;
    }
    number = numberStore;
    iterator--;
  }
  // if the original number is a prime, then return 1, else 0
  if (isPrime(number)) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) {
  int a, b;
  int superPrimeCount = 0;
  int n = scanf("%d %d", &a, &b);
  /*loop through every number from a to b, simply checks if a is a superprime
  with isSuperPrime(), if it is it adds to the counter, increments a until b
  is reached*/
  while (a < b) {
    if (a > 10 &&
        ((a % 2 == 0) || (a % 3 == 0) || (a % 5 == 0) || (a % 7 == 0))) {
      a++;
      continue;
    }
    if (isSuperPrime(a)) {
      superPrimeCount++;
    }
    a++;
  }
  printf("%d\n", superPrimeCount);
  return 0;
}
