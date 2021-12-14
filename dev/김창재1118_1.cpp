#include<stdio.h>
#include <stdlib.h>
#include <time.h>

struct person{
   char hand[12]={0,};
   int chip;
   int handsum=0;
   int n;
   bool dealer;
};

void print(struct person m, int n){
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

void cardset(struct person *m,char card[]){
	while (1){
      srand(time(NULL));
      int num = rand() % 52;
      if (card[num] != 0){
         continue;
      }
      else{
         m->hand[m->n] = num;
         card[num]++;
         m->n++;
         if (num % 13 > 9)
         {
            m->handsum += 10;
         }
         else if(m->dealer&&!num%13){
         	m->handsum+=11;
		 }
         else
         {
            m->handsum += num % 13 + 1;
         }
         break;
      }
   }
}

int main(){
	struct person m, d;
	int co = 0, go, co_1 = 0,  co_2 = 0;
	char card[52] = { 0 };
	int bet, playerwin = 0, dealwin = 0;
	
	d.chip=10000;
	m.chip=100000;
    d.n=0;
    m.n=0;
    d.dealer=true;
    m.dealer=false;
    
    printf("베팅하십시오");
    scanf("%d", &bet);
    d.chip -= bet;
    m.chip -= bet;
    
    cardset(&m,card);
    cardset(&d,card);
    while(1){
    	cardset(&m,card);
    	if(d.handsum<17) cardset(&d,card);
    	
    	printf("player's hand\n");
   	    print(m, m.n);
        printf("\nsum : %d\n", m.handsum);
        print(d, d.n-1);
        printf("\n");
        
        if (m.handsum > 21){
         system("cls");
         printf("BUST\n");
         printf("plalyer sum : %d\n", m.handsum);
         print(m, m.n);
         dealwin++;
         printf("\ndealer win");

         break;
        }
        if (m.handsum == 21 && m.n == 2)
        {
         printf("BLACK JACK!");
         break;
        }

        printf("\n 1.GO 2.STAY"); //1반복 2스톱
        scanf("%d", &go);
        printf("\n");
        system("cls");
        
    	if (go == 2){ //스톱
         printf("plalyer sum : %d\n", m.handsum);
         print(m, m.n);
         printf("\n");
         if (d.handsum < 17) {//스톱했는데 딜러패가 17 이하인 경우
         	cardset(&d,card);
            printf("dealer sum : %d\n", d.handsum);
            print(d, d.n);
         }
         else if(d.handsum>21){
         	system("cls");
        	printf("BUST\n");
       		printf("plalyer sum : %d\n", m.handsum);
       		print(m, m.n);
        	printf("\ndealer sum : %d\n", d.handsum);
        	print(d, d.n);

         	playerwin++;
        	printf("\player win!");

         	break;
		 }
         else if (d.handsum >= 17){
            printf("dealer sum : %d\n", d.handsum);
            print(d, d.n);
            if (m.handsum > d.handsum) {
               printf("\nplayerwin!");
               playerwin++;
            }
            else {
               printf("\ndealerwin!");
               dealwin++;
            }
         }
         break;
      }
   }
   if (playerwin ) {
      m.chip += 2 * bet;
   }
   else if (dealwin) {
      d.chip += 2 * bet;
   }
   printf("\n플레이어 %d 딜러 %d", m.chip, d.chip);
}
