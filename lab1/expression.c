/* file:        expression.c                             */
/* author:      Rik de Hoop (h.s.de.hoop@student.rug.nl) */
/* date:        Thu Sep 12 2024                          */
/* version:     1.0                                      */

/* Description:
* solves aXbYc
*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int a, b, c;
    char x, y;
    int result;
    scanf("%d%c%d%c%d", &a, &x, &b, &y, &c);
    if (y == '*') {
	    if (x == '*') {
	        result = a * b * c;
	    } else {
	        result = a + b * c;
	    }
    } else if (x == '*') {
	    result = a * b + c;
    } else {
	    result = a + b + c;
    }

    printf("%d\n", result);
    return 0;
}
