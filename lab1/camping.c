/* file:        camping.c                                */
/* author:      Rik de Hoop (h.s.de.hoop@student.rug.nl) */
/* date:        Mon Sep 12 2024                          */
/* version:     1.0                                      */

/* Description:
* when given an integer input of liters, it calculates how many times of going 
* back and forth to get the required amount
*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int input, output;
    //printf("How many liters are need to fill the pool: ");  //on themis this line broke the output
    scanf("%d", &input);
    output = input / 24;
    if (input % 24 != 0) {
		output++;
    }
    printf("%d\n",output);
    return 0;
}
