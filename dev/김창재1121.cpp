#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct person
{
   char hand[5];
};
void print(struct person m, int n)
{
   for (int i = 0; i < n; i++)
   {
      if (m.hand[i])
      {
         switch (m.hand[i] / 13)
         {
         case 0: printf("♠"); break;
         case 1: printf("◆"); break;
         case 2: printf("♥"); break;
         case 3: printf("♣"); break;
         }
         printf(" %d ", m.hand[i] % 13 + 1);
      }
   }
}

int main(){
	struct person m;
 int i, ch[5], co = 0, ch_num, k = 0, go, co_1 = 0, hand_sum = 0, hand_num[4], co_2 = 0;
 char card[52] = { 0 };
  while (1)
  {
          srand(time(NULL));
         int num = rand() % 52;
         if (card[num] != 0) continue;
         else      {
            m.hand[k] = num;
            card[num]++;
            k++;
         }
      if (k == 5)
         break;
   }
  print(m, k);
  i = 0;
  /*
  printf("몇개를 바꾸시겠습니까");
  scanf("%d", &ch_num);
  for(int j=0;j<ch_num;j++){
	printf("몇번카드를 바꾸시겠습니까?");
    scanf("%d", &ch[i]);
    while(1){
     srand(time(NULL));
     int num = rand() % 52;
     if (card[num] != 0) continue;
     else {
        m.hand[ch[i]-1] = num;
        card[num]++;
        break;
     }
 	}
  }*/
    while(1){
     printf("몇번카드를 바꾸시겠습니까?");
     scanf("%d", &ch[i]);
     srand(time(NULL));
     int num = rand() % 52;
     if (card[num] != 0) continue;
     else {
        m.hand[ch[i]-1] = num;
        card[num]++;
        i++;
        if (i == ch_num)break;
     }
  }

  
  print(m, 5);
  return 0;
}

