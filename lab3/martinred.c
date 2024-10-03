/* file   :     martinred.c                                */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl)   */
/* date   :     Mon Sep 23 2024                            */
/* version:     1.0                                        */

/* Description:
 * given an input of initial budget and the draws a roulette table will make,
 * find out what the final amount of money is after applying the martingale red
 * method
 */

#include <stdio.h>
#include <stdlib.h>

/*find if a draw is red or not*/
int foundRedDraw(int draw) {
  if (draw < 11 || (draw > 18 && draw < 29)) {
    if (draw % 2 == 1) {
      return 1;
    }
  } else {
    if ((draw % 2 == 0) && draw != 0) {
      return 1;
    }
  }
  return 0;
}
/*calculates powers for integers*/
int intPow(int base, int power) {
  int result = 1;
  while (power > 0) {
    result = result * base;
    power--;
  }
  return result;
}

int main(int argc, char *argv[]) {
  /*scan the first line for the budget*/
  int budget, draw;
  int n = scanf("%d", &budget);
  /*loop through all draws, end at -1*/
  int round = 0;
  while (1) {
    scanf("%d", &draw);
    if (draw == -1) {
      if ((budget - (intPow(2, round))) < 0) {
        printf("BUST\n");
        return 0;
      }
      break;
    }
    /*adjust budget for the round, if the budget would need to get negative, it
    goes BUST*/
    budget = budget - (intPow(2, round));
    if (budget < 0) {
      printf("BUST\n");
      return 0;
    }
    /*find if the draw is red, if it is then reset the rounds, add the winnings
    to the budget, and skip to the end of the loop*/
    if (foundRedDraw(draw)) {
      budget = budget + 2 * (intPow(2, round));
      round = 0;
      continue;
    }
    round++;
  }
  /*print budget if it hasn't BUSTed*/
  printf("%d\n", budget);
  return 0;
}
