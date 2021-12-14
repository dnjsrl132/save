#include<stdio.h>
#include <stdlib.h>
#include <time.h>

struct person
{
   char hand[12];
   char deal[12];
};

void print(struct person m, int n)
{
   for (int i = 0; i < n; i++)
   {
      if (m.hand[i])
      {
         switch (m.hand[i] / 13)
         {
         case 0: printf("��"); break;
         case 1: printf("��"); break;
         case 2: printf("��"); break;
         case 3: printf("��"); break;
         }
         printf(" %d ", m.hand[i] % 13 + 1);
      }
   }
}
void print_deal(struct person m, int n) //���� �� ���
{
   for (int i = 0; i < n - 1; i++)
   {
      if (m.deal[i])
      {
         switch (m.deal[i] / 13)
         {
         case 0: printf("��"); break;
         case 1: printf("��"); break;
         case 2: printf("��"); break;
         case 3: printf("��"); break;
         }
         printf(" %d ", m.deal[i] % 13 + 1);
      }
   }
}
int main()
{
   struct person m;
   int co = 0, k = 0, kd = 0, go, co_1 = 0, hand_sum = 0, hand_num[4], co_2 = 0, dhand_sum = 0;
   char card[52] = { 0 };
   int deal_chip = 10000;
   int player_chip = 100000;
   int bet, playerwin = 0, dealwin = 0;
   printf("�����Ͻʽÿ�");
   scanf("%d", &bet);
   deal_chip -= bet;
   player_chip -= bet;
   while (1) //�÷��̾� 1��° ī��
   {
      srand(time(NULL));
      int num = rand() % 52;
      if (card[num] != 0)
      {
         continue;
      }
      else
      {
         m.hand[k] = num;
         card[num]++;
         k++;
         if (num % 13 > 9)
         {
            hand_sum += 10;
         }
         else

         {
            hand_sum += num % 13 + 1;
         }
         break;
      }
   }
   while (1) //���� 1��° ī��
   {
      srand(time(NULL));
      int deal_num = rand() % 52;
      if (card[deal_num] != 0)
      {
         continue;
      }
      else
      {
         m.deal[kd] = deal_num;
         card[deal_num]++;
         kd++;
         if (deal_num % 13 > 9)
         {
            dhand_sum += 10;
         }
         else if (deal_num == 1) {
            dhand_sum += 11;
         }
         else
         {
            dhand_sum += deal_num % 13 + 1;
         }
         break;
      }
   }
   while (1)
   {
      while (1) //����, �÷��̾� 2��° ī�� ���ÿ�
      {
         srand(time(NULL));
         int num = rand() % 52; //�÷��̾�
         int deal_num = rand() % 52; //����
         if (card[num] != 0 || card[deal_num] != 0)
         {
            continue;
         }
         else
         {
            m.hand[k] = num;
            card[num]++;
            k++;
            if (num % 13 > 9)
            {
               hand_sum += 10;
            }
            else if (num % 13 <= 9)
            {
               hand_sum += num % 13 + 1;
            }
            if (dhand_sum < 17) //������ 17 ���� ��쿣 x
            {
               m.deal[kd] = deal_num;
               card[deal_num]++;
               kd++;
               if (deal_num % 13 > 9)
               {
                  dhand_sum += 10;
               }
               else
               {
                  dhand_sum += deal_num % 13 + 1;
               }
            }
            break;
         }
      }
      printf("player's hand\n");
      print(m, k);
      printf("\nsum : %d\n", hand_sum);
      print_deal(m, kd);
      printf("\n");
      if (hand_sum > 21)
      {
         system("cls");
         printf("BUST\n");
         printf("plalyer sum : %d\n", hand_sum);
         print(m, k);
         printf("\ndealer sum : %d\n", dhand_sum);
         print_deal(m, kd + 1);

         dealwin++;
         printf("\ndealer win");

         break;
      }
      if (hand_sum == 21 && k == 2)
      {
         printf("BLACK JACK!");
         break;
      }

      printf("\n 1.GO 2.STAY"); //1�ݺ� 2����
      scanf("%d", &go);
      printf("\n");
      system("cls");
      if (go == 2) //����
      {
         printf("plalyer sum : %d\n", hand_sum);
         print(m, k);
         printf("\n");
         if (dhand_sum < 17) //�����ߴµ� �����а� 17 ������ ���
         {
            while (1) //���� 1�� �߰�
            {
               srand(time(NULL));
               int deal_num = rand() % 52;
               if (card[deal_num] != 0) continue;
               else
               {
                  m.deal[kd] = deal_num;
                  card[deal_num]++;
                  kd++;
                  if (deal_num % 13 > 9)
                  {
                     dhand_sum += 10;
                  }
                  else
                  {
                     dhand_sum += deal_num % 13 + 1;
                  }
                  if (dhand_sum < 17)
                     continue;
                  if (dhand_sum >= 17)
                     break;
               }
            }
            printf("dealer sum : %d\n", dhand_sum);
            print_deal(m, kd + 1);
         }
         else if (dhand_sum >= 17)
         {
            printf("dealer sum : %d\n", dhand_sum);
            print_deal(m, kd + 1);
            if (hand_sum > dhand_sum) {
               printf("playerwin!");
               playerwin++;
            }
            else {
               printf("dealerwin!");
               dealwin++;
            }

         }

         break;
      }


   }
   if (playerwin != 0) {
      player_chip += 2 * bet;
   }
   else if (dealwin != 0) {
      deal_chip += 2 * bet;
   }
   printf("�÷��̾� %d ���� %d", player_chip, deal_chip);
}
