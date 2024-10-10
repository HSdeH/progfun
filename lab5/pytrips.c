/* file   :     pytrips.c                                */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Mon Oct 7 2024                           */
/* version:     1.0                                      */

/* Description:
 * find the amount of pythagorean triples for n where a + b + c = n and a < b
 */

#include <stdio.h>
#include <stdlib.h>

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
  for (int i = 3; i * i <= number; i+=2) {
    if (number % i == 0) {
      return 0;
    }
  }
  return 1;
}

int pyTrip(int n, int *output) {
  int a = 1, b = 2, c = 0;
  while (b < n/2) {
    if (a == b) {
      a = 1;
      b++;
    }
    c = n - a - b;
    if (((a * a) + (b * b)) == (c * c)) {
      for (int i = 2; i < a; i++) {
        if (a%i == 0 && b%i == 0 && c%i == 0) {
          (*output)--;
          break;
        }
      }
        (*output)++;
    }
    a++;
  }
}

int main(int argc, char *argv[]) {
  int n, output = 0;
  (void)scanf("%d", &n);
  pyTrip(n, &output);
  printf("%d\n", output);
  return 0;
}
