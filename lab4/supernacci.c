/* file   :     template.c                               */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Thu Oct 3 2024                           */
/* version:     1.0                                      */

/* Description:
 * This programma accepts on its input a positive integer n,
 * and outputs fib(n). The program works as longs as the
 * number of digits of fib(n) does not exceed 1000.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXDIG 1000

typedef struct {
  int numDigits;       // number of digits
  int digits[MAXDIG];  // decimal digits of big integer
} unsignedBigInt;

// turns int into unsignedBigInt
unsignedBigInt makeUnsignedBigIntFromInt(unsigned int n) {
  unsignedBigInt big;
  big.numDigits = 0;
  if (n == 0) {
    big.numDigits++;
    big.digits[0] = 0;
  }
  // counts the number of digits, and stores digits... in reverse
  int iterator = 0;
  while (n > 0) {
    big.digits[iterator] = n % 10;
    n /= 10;
    big.numDigits++;
    iterator++;
  }
  return big;
}

// prints an unsignedBigInt, in reverse of course
void printBigInt(unsignedBigInt big) {
  for (int i = big.numDigits - 1; i >= 0; i--) {
    printf("%d", big.digits[i]);
  }
}

void printlnBigInt(unsignedBigInt big) {
  printBigInt(big);
  printf("\n");
}

unsignedBigInt add(unsignedBigInt a, unsignedBigInt b) {
  unsignedBigInt big;
  // make sure youre always adding the shorter one to the longer one
  big = a.numDigits > b.numDigits ? a : b;
  b = a.numDigits > b.numDigits ? b : a;

  int carry = 0;
  for (int i = 0; i < big.numDigits; i++) {
    if (carry) {
      big.digits[i]++;
      carry = 0;
    }
    if (i < b.numDigits) {
      big.digits[i] += b.digits[i];
    }
    if (big.digits[i] > 9) {
      carry = 1;
      big.digits[i] -= 10;
    }
  }

  // special case for when theyre the same size
  if (carry) {
    big.numDigits++;
    big.digits[big.numDigits - 1] = 1;
  }

  return big;
}

unsignedBigInt subtract(unsignedBigInt a, unsignedBigInt b) {
  unsignedBigInt big;
  big = a;

  int borrow = 0;
  for (int i = 0; i < big.numDigits; i++) {
    if (borrow) {
      big.digits[i]--;
      borrow = 0;
    }
    if (i < b.numDigits) {
      big.digits[i] -= b.digits[i];
    }
    if (big.digits[i] < 0) {
      borrow = 1;
      big.digits[i] += 10;
    }
  }

  // for if the first digit has become 0
  if (big.digits[big.numDigits - 1] == 0) {
    big.numDigits--;
  }

  return big;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("fib(%d)=", n);

  unsignedBigInt a = makeUnsignedBigIntFromInt(0);
  unsignedBigInt b = makeUnsignedBigIntFromInt(1);

  while (n > 0) {
    b = add(a, b);
    a = subtract(b, a);
    n--;
  }
  printlnBigInt(a);
  return 0;
}
