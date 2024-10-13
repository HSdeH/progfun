/* file   :     dnav2.c                                  */
/* author :     Rik de Hoop (H.S.de.Hoop@student.rug.nl) */
/* date   :     Fri Oct 11 2024                          */
/* version:     1.0                                      */

/* Description:
 * checks if a pattern is found in a genome
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bufferLength 1000000

int findPattern(char *, char *, int *);

int main(int argc, char **argv) {
  int e, matches = 0, shift = 0;
  char pattern[10000], buffer[bufferLength], numString[10];
  char name[100];
  char *genome;
  char **text;
  scanf("%s", pattern);
  scanf("%d ", &e);
  text = malloc(sizeof(char *) * e);
  // read and process data
  for (int i = 0; i < e; i++) {
    int test = 0;
    while (1) {
      scanf("%c", &buffer[test]);
      // if (buffer[test] == '\n') {
      //   break;
      // }
      if (test == 9900) {
        break;
      }
      test++;
    }
    //fgets(buffer, bufferLength, stdin);
    int iterate = 0;
    while (buffer[iterate] != ':') {
      name[iterate] = buffer[iterate];
      iterate++;
    }
    iterate++;
    name[iterate] = '\0';
    int j = 0;
    genome = malloc(bufferLength*sizeof(char));
    while ((buffer[iterate] != '\n') || (((iterate+1)%4096)==0)) {
      genome[j] = buffer[iterate];
      iterate++;
      j++;
    }
    genome[iterate] = '\0';
    if (findPattern(genome, pattern, &shift)) {
      sprintf(numString, "%d", shift);
      char *line = malloc(strlen(name)+strlen(numString)+(sizeof(char)*10));
      line[0] = '\0';
      strcat(line, name);
      strcat(line, ": shift=");
      strcat(line, numString);
      text[matches] = malloc(strlen(line)+1);
      strcpy(text[matches], line);
      free(line);
      matches++;
    }
    free(genome);
    // name = NULL;
  }
  for (int i = 0; i < matches; i++) {
    printf("%s\n", text[i]);
  }
  printf(matches != 1 ? "%d matches found.\n" : "1 match found.\n", matches);
  for (int i = 0; i < matches; i++) {
    free(text[i]);
  }
  free(text);
  return 0;
}

// if 0, no pattern was found, if 1 a pattern was found and shift gets set to
// its index
int findPattern(char *genome, char *pattern, int *shift) {
  // if (strlen(pattern) > strlen(genome)) {
  //   return 0;
  // }
  char *shiftPointer = strstr(genome, pattern);
  if (shiftPointer == NULL) {
    return 0;
  }
  *shift = (shiftPointer - genome);
  return 1;
}
