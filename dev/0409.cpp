#include<stdio.h>
int main() {

   int c;
   scanf("%d", &c);
   int st;
   int i = 0;
   int sum = 0;
   int peo = 0;
   int number;
   float number1;
   int student[1000] = { 0, };
   for (c; c>0; c --) {
      scanf("%d", &st);
      number = st;
      number1 = st;
      for (st; st>0; st--) {
         scanf("%d", &student[i]);
         sum += student[i];
         i++;
      }
      i = 0;
      for (number; number>0; number--) {
         if (student[i] >= sum / 5)peo++;
      }
      double percent=peo/number1*100;
      printf("%.3lf%%\n",percent);
   }


}
