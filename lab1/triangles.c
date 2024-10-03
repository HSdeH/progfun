/* file:        triangles.c                              */
/* author:      Rik de Hoop (h.s.de.hoop@student.rug.nl) */
/* date:        Thu Sep 12 2024                          */
/* version:     1.0                                      */

/* Description:
* determines if a triangle is rectangular, obtuse, or acute
*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {

    int a, b, c, temp;

    int n = scanf("%d %d %d", &a, &b, &c);
    //reverse pythagoras :(, Im pretty sure these should be ordered from smallest to greatest but whatever Ill see what happens first

    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    } //yeah I figured anyway only c is supposed to be the greatest a and b dont need to be ordered

    if (a + b < c) {
        printf("NONE\n");
        return 0; //this feels kind of dirty    
    }

    
    if (a*a + b*b == c*c) {
        printf("RECTANGULAR\n");    
    } else if (a*a + b*b < c*c){
        printf("OBTUSE\n");    
    } else {
        printf("ACUTE\n");    
    }
    
    return 0;
}
