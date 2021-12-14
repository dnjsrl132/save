#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_KEYS 1000
#pragma warning(disable:4996)
int comparison=0;
int n = NUM_KEYS;
int S[NUM_KEYS];

void swap(int S[], int i, int j)
{
   int t = S[i];
   S[i] = S[j];
   S[j] = t;
}
void partition3(int low, int high, int pivotpoint)
{
   int i, j, randspot;
   int pivotitem;

   //srand(time(NULL));
   
   randspot = rand() % (high - low) + low;
   pivotitem = S[randspot];
   //printf("%d\n",randspot);
   j = low;
   for (i = low + 1; i <= high; i++)
      if (S[i] < pivotitem) {
         j++;
         comparison++;
         swap(S, i, j);
      }
   pivotpoint = j;
   swap(S, low, pivotpoint);
}
int selection3(int low, int high, int k)
{
   int pivotpoint;
   if (low == high)
      return S[low];
   else {
      comparison++;
      partition3(low, high, pivotpoint);
      if (k == pivotpoint)
         return S[pivotpoint];
      else if (k < pivotpoint)
         return selection3(low, pivotpoint - 1, k);
      else
         return selection3(pivotpoint + 1, high, k);
   }
}
int main() {
   int i, j, k; double t = 0;
   srand(time(NULL));
   for (int z = 0; z < 100; z++) {
      for (i = 0; i < n; i++)
         S[i] = i + 1;
      for (i = 0; i < 10 * n; i++) {
         j = rand() % n;
         k = rand() % n;
         swap(S, j, k);
      }
      clock_t start = clock();
      selection3(1, NUM_KEYS, k);
      printf("%d %d %d ", k, S[k], comparison);
      clock_t end = clock();
      t = t + (double)(end - start) / CLOCKS_PER_SEC;
      printf("Time: %lf\n", t);
   }
}
