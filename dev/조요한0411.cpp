#include <stdio.h>
int transform(int m, int n)
{
   int a = 0;
   int b = 0;
   int td[][3] = { {1, 2, 3} ,{4, 5, 6} ,{7, 8, 9} };

   for (a = 0; a < 3; a++)
   {
      for (b = 0; b < 3; b++)
         printf(" %d ", td[b][a]);
      puts("");
   }

   
}
int main(void)
{
   int td[][3] = { {1, 2, 3} ,{4, 5, 6} ,{7, 8, 9} };
   int i, j ;

   printf("Original Matrix\n");
   
   for (i = 0; i < 3; i++)
   {
      for (j = 0; j < 3; j++)
         printf(" %d ", td[i][j]);
      puts("");
   }

   printf("Transformed Matrix\n");
   printf("%d", transform(j,i));

   return 0;
}


