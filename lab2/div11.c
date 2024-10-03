/* file:        div11.c                                  */
/* author:      Rik de Hoop (h.s.de.hoop@student.rug.nl) */
/* date:        Sun Sep 22 2024                          */
/* version:     1.0                                      */

/* Description:
 * checks if an input is divisible by 11 and shows the steps
 */

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {

    long long input, x, inputLength;   //assumes input length of at least 1
    long long answer;                           

    int n = scanf("%lli", &input);
    do {
        inputLength = 1;
        answer = 0;
        x = input;
        while(x > 9){
            x /= 10;
            inputLength++;
        }

        int iterator = 0;
        while (iterator < inputLength){

            x = input;
            for(int i = 1; i < (inputLength - iterator); i++) {
                x /= 10;
            }
            x %= 10;
            if(iterator % 2 == 0) {
                printf("+%lli", x);
                answer += x;
            } else {
                printf("-%lli", x);
                answer -= x;
            }
            iterator++;
        }
        printf("=%lli\n", answer);
        if (answer < 0) {
            input = answer * -1;
        }   else {
            input = answer;
        }
    } while (answer > 11 || answer < -10);
    if(answer) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}
