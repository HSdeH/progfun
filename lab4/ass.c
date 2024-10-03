/* file   :     ass.c                                    */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Tue Oct 1 2024                           */
/* version:     1.0                                      */

/* Description:
 * small assembly simulator
 */

#include <stdio.h>
#include <stdlib.h>

void execute(char instruction[], int* reg1, int* reg2) {
  char arg1[3], arg2[3];
  int n;
  switch (instruction[0]) {
    case 'O':
      scanf("%s", arg1);
      if (arg1[1] == '1') {
        printf("%d\n", *reg1);
      } else {
        printf("%d\n", *reg2);
      }
      break;
    case 'L':
      scanf("%s %d", arg1, &n);
      if (arg1[1] == '1') {
        *reg1 = n;
      } else {
        *reg2 = n;
      }
      break;
    case 'I':
      scanf("%s", arg1);
      if (arg1[1] == '1') {
        *reg1 += 1;
      } else {
        *reg2 += 1;
      }
      break;
    case 'D':
      scanf("%s", arg1);
      if (arg1[1] == '1') {
        *reg1 -= 1;
      } else {
        *reg2 -= 1;
      }
      break;
    case 'A':
      scanf("%s %s", arg1, arg2);
      if (arg1[1] == '1') {
        if (arg2[1] == '1') {
          *reg1 = 2 * *reg1;
        } else {
          *reg2 = *reg1 + *reg2;
        }
      } else if (arg2[1] == '1') {
        *reg1 = *reg1 + *reg2;
      } else {
        *reg2 = 2 * *reg2;
      }
      break;
    case 'S':
      scanf("%s %s", arg1, arg2);
      if (arg1[1] == '1') {
        if (arg2[1] == '1') {
          *reg1 = 0;
        } else {
          *reg2 = *reg1 - *reg2;
        }
      } else if (arg2[1] == '1') {
        *reg1 = *reg2 - *reg1;
      } else {
        *reg2 = 0;
      }
      break;
    case 'M':
      scanf("%s %s", arg1, arg2);
      if (arg1[1] == '1') {
        if (arg2[1] == '1') {
          *reg1 = *reg1 * *reg1;
        } else {
          *reg2 = *reg1 * *reg2;
        }
      } else if (arg2[1] == '1') {
        *reg1 = *reg1 * *reg2;
      } else {
        *reg2 = *reg2 * *reg2;
      }
      break;
    default:
      break;
  }
}

int main(int argc, char* argv[]) {
  int r1, r2;
  char instruction[4];
  while (scanf("%s", &instruction) == 1 && (instruction[0] != 'E')) {
    execute(instruction, &r1, &r2);
  }
  return 0;
}
