#include "matrix.h"
#include "stdio.h"
#include <stdlib.h>

#define DIMISION 3

int (*matrix) [DIMISION];

void init()
{
   matrix = malloc(sizeof(int[DIMISION][DIMISION]));
}
void set(int i, int j, int value)
{
      matrix[i][j] = value;
}
void print()
{
    for (int i = 0; i < DIMISION; i++)
   {
      for (int j = 0; j < DIMISION; j++)
      {
         printf("%d\t", matrix[i][j]);
      }
       printf("\n");
   }
}
