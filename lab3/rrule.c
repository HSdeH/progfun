/* file   :     rrule.c                                    */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl)   */
/* date   :     Fri Sep 27 2024                            */
/* version:     1.0                                        */

/* Description:
 * find the resolvent between 2 clauses with at most 1 complementary pair
 */

#include <stdio.h>
#include <stdlib.h>

// I dont know how useful this was, but it is here now, stores an atom together
// with if its negated or not
typedef struct {
  int negated;
  char value;
} expression;

// print a full sentence from an expression array
void printSentence(expression expression[]) {
  printf("[");
  for (int i = 0; i < 26; i++) {
    if (expression[i].value == '~') {
      continue;
    }
    if (expression[i].negated == 1) {
      printf("~");
    }
    printf("%c", expression[i].value);
    if (expression[i + 1].value != '~') {
      printf(",");
    }
  }
  // this used \b first but themis will print that as a character which broke my
  // code twice (the second time was accidental)
  printf("]\n");
}

// order the expression
void orderExpression(expression exp[]) {
  expression temp;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26 - i; j++) {
      if (exp[j].value > exp[j + 1].value) {
        temp = exp[j];
        exp[j] = exp[j + 1];
        exp[j + 1] = temp;
      }
    }
  }
}
// merges the right expression array into the left one
void mergeExpressions(expression left[], expression right[]) {
  int found;
  int k;
  for (int i = 0; i < 27; i++) {
    found = 0;
    for (int j = 0; j < 27; j++) {
      if (right[i].value == left[j].value) {
        found = 1;
        break;
      }
    }
    k = 0;
    if (!found) {
      while ((left[k].value != '~') && (left[k].value != ' ')) {
        k++;
      }
      left[k] = right[i];
    }
  }
}
/*returns 0 if a resolvent has not been found, 1 if it has been found*/
int findResolvent(expression leftClause[], expression rightClause[]) {
  int code = 0;
  // remove the complementary pair from both clauses
  for (int i = 0; i < 27; i++) {
    for (int j = 0; j < 27; j++) {
      // this conditional being 2 lines is because of visual studio's format
      // command, I'm sure it's fine
      if ((leftClause[i].value == rightClause[j].value) &&
          leftClause[i].negated != rightClause[j].negated) {
        code = 1;
        // shift both the left and right clause into the complementary pair so
        // it get deleted
        for (int k = i; k < 26; k++) {
          leftClause[k] = leftClause[k + 1];
        }
        for (int k = j; k < 26; k++) {
          rightClause[k] = rightClause[k + 1];
        }
      }
    }
  }
  // made this dependent on whether a resolvent can be found, technically not
  // necessary
  if (code) {
    mergeExpressions(leftClause, rightClause);
    orderExpression(leftClause);
  }
  return code;
}

int main(int argc, char *argv[]) {
  // made this with unchanging arrays, because it works
  expression leftClause[27], rightClause[27];
  char input;

  // fill them up, use ~ because it has a greater value than capitalized letters
  // and it orders better
  for (int i = 0; i < 27; i++) {
    rightClause[i].negated = 0;
    rightClause[i].value = '~';
    leftClause[i].negated = 0;
    leftClause[i].value = '~';
  }
  int iterator = 0;
  // read the first clause into the leftClause array
  while (scanf("%c", &input) == 1 && input != ']') {
    if (input == ',' || input == '[') {
      continue;
    }
    if (input == '~') {
      leftClause[iterator].negated = 1;
      continue;
    } else {
      leftClause[iterator].value = input;
    }
    iterator++;
  }
  iterator = 0;
  // read the second clause into the rightClause array
  while (scanf("%c", &input) == 1 && input != ']') {
    if (input == ',' || input == '[' || input == ' ') {
      continue;
    }
    if (input == '~') {
      rightClause[iterator].negated = 1;
      continue;
    } else {
      rightClause[iterator].value = input;
    }
    iterator++;
  }

  if (findResolvent(leftClause, rightClause)) {
    printSentence(leftClause);
  } else {
    printf("NO RESOLVENT\n");
  }
  return 0;
}
