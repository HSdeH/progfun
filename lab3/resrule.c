/* file   :     resrule.c                                  */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl)   */
/* date   :     Tue Sep 24 2024                            */
/* version:     1.0                                        */

/* Description:
 * find the resolvent between 2 clauses with at most 1 complementary pair
 */

#include <stdio.h>
#include <stdlib.h>

/*tree like struct*/
typedef struct {
  int isAtom;
  int negated;
  char value;
} expression;

int main(int argc, char *argv[]) {
  int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x,
      y, z;
  int negation;
  expression leftClause, rightClause;
  char input;
  while (scanf("%c", &input) == 1 && input != '\n') {
    switch (input) {
      case 'a':
        if (a == 0) {
          a++;
          if (negation == 1) {
            a++;
          }
        } break;

      default:
        break;
    }
  }
  printf("\n");
  return 0;
}
