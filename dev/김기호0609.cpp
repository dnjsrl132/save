#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define NUM_KEYS 1250

int comparison = 0;
int n = NUM_KEYS;
int S[NUM_KEYS];

void swap(int S[], int i, int j);
int selection2(int S[], int low, int high, int k);
int select(int n, int S[], int k);
int median(int first, int last, int S[]);
void partition2(int S[], int low, int high, int pivotpoint);
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
      selection2(S, 1, NUM_KEYS, k);
      printf("%d %d %d ", k, S[k], comparison);
      clock_t end = clock();
      t = t + (double)(end - start) / CLOCKS_PER_SEC;
      printf("Time: %lf\n", t);
   }
}
void swap(int S[], int i, int j)
{
   int t = S[i];
   S[i] = S[j];
   S[j] = t;
}
int selection2(int S[], int low, int high, int k)
{
   int pivotpoint=k;
   if (high == low)
      return S[low];
   else {
      partition2(S, low, high, pivotpoint);
      if (k == pivotpoint)
         return S[pivotpoint];
      else if (k < pivotpoint)
         return selection2(S, low, pivotpoint - 1, k);
      else
         return selection2(S, pivotpoint + 1, high, k);
   }
}
int select(int n, int S[], int k)
{
   return selection2(S, 1, n, k);
}
int median(int first, int last, int S[])
{
   for (int i = first; i <= last; i++) {
      for (int j = first; j < last; j++) {
         comparison++;
         if (S[j] > S[j + 1])
            swap(S, i, j);
      }
   }
   return S[(first + last) / 2];
}
void partition2(int S[], int low, int high, int pivotpoint)
{
   int arraysize = high - low + 1;
   int r = (int)floor(arraysize / 5);
   int i, j, mark, first, last;
   int pivotitem; int T[NUM_KEYS];
   if(!r) return;
   for (i = 1; i <= r; i++) {
      first = low + 5 * i - 5;
      last = low + 5 * i - 1;
      T[i] = median(first, last, S);
   }
   pivotitem = select(r, T, (int)floor((r + 1) / 2));
   j = low;
   for (i = low; i <= high; i++) {
      if (S[i] == pivotitem) {
         swap(S, i, j);
         mark = j;
         j++;
         comparison++;
      }
      else if (S[i] < pivotitem) {
         swap(S, i, j);
         j++;
         comparison++;
      }
   }
      pivotpoint = j - 1;
      swap(S, mark, pivotpoint);
}
