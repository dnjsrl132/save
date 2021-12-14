//2019113924_1 조요한
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

void main(void)
{
   char td[20];
   char temp;

   printf("광고문구를 입력하시오(최대 20자) : ");
   gets_s(td, 20);

   while (1)
   {
      for (int i = 0; i < strlen(td); i++)
      {
         if (i == 0)
         {
            temp = td[i];
         }
         else
         {
            td[i - 1] = td[i];
         }
      }
         td[strlen(td) - 1] = temp;
         
         for (int i = 0; i < strlen(td); i++)
            printf("%c", td[i]);
         Sleep(1000);
         system("cls");
      
   }

}
