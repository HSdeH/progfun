/* file:        boundingbox.c                            */
/* author:      Rik de Hoop (h.s.de.hoop@student.rug.nl) */
/* date:        Thu Sep 12 2024                          */
/* version:     1.0                                      */

/* Description:
* returns the bounding box coords of 3 triangles
*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {

    int a, b, r;
    int bottomLeftX, bottomLeftY, topRightX, topRightY;

    scanf("%d %d %d", &a, &b, &r);
    bottomLeftX = a - r;
    bottomLeftY = b - r;
    topRightX = a + r;
    topRightY = b + r;

    scanf("%d %d %d", &a, &b, &r);

    if (bottomLeftX > a - r) {
        bottomLeftX = a - r;    
    }
    if (bottomLeftY > b - r) {
        bottomLeftY = b - r;
    }
    if (topRightX < a + r) {
        topRightX = a + r;
    }
    if (topRightY < b + r) {
        topRightY = b + r;            
    }

    scanf("%d %d %d", &a, &b, &r);

    if (bottomLeftX > a - r) {
        bottomLeftX = a - r;    
    }
    if (bottomLeftY > b - r) {
        bottomLeftY = b - r;
    }
    if (topRightX < a + r) {
        topRightX = a + r;
    }
    if (topRightY < b + r) {
        topRightY = b + r;            
    }

    printf("[(%d,%d),(%d,%d)]\n",bottomLeftX, bottomLeftY, topRightX, topRightY);
}
