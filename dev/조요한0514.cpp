#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define _CRT_SECURE_NO_WARNINGS
#define TITLE_SIZE 50
#define NAME_SIZE 50
#define ALBUM_SIZE 50



enum music_type { KPOP, POP, CLASSIC, OST };

typedef struct music
{
   char title[TITLE_SIZE];
   char singer[NAME_SIZE];
   char album[ALBUM_SIZE];
   enum music_type genre;
} mu;

int main(void)
{
  	int key = 0;
   	int a = 0;
	mu mus[100];
	char tetit[TITLE_SIZE];
	int i=0;
	while(1)
	{
		
   		printf("1. 추가\n2. 출력\n3. 검색\n4. 종료\n");
   		printf("사용할 메뉴의 번호를 입력하십시오.");
   		
   		scanf("%d", &a);
   		
   		
   		
   		if (a == 4)      //종료 
   		{
      		printf("종료를 선택하셨습니다. 프로그램을 종료합니다. \n");
      		break;
   		}
   		else if (a == 2)
   		{
   			for(int j=0;j<i;j++){
   				printf("\n제목 : %s\n", mus[j].title);
      			printf("가수 : %s\n", mus[j].singer);
      			printf("앨범 : %s\n", mus[j].album);
      			printf("장르 : %s\n", mus[j].genre);
			   }
   		}
   		else if (a == 3)
   		{
   			gets(tetit);
   			printf("제목: ");
   			gets(tetit); 
   			for(int j=0;j<i;j++){
   				if(!strcmp(tetit,mus[j].title)){
   					printf("\n제목 : %s\n", mus[j].title);
      				printf("가수 : %s\n", mus[j].singer);
      				printf("앨범 : %s\n", mus[j].album);
      				printf("장르 : %d\n", mus[j].genre);
      				break;
				   }
				if(j==i-1){
					printf("찾는음악이 없습니다. \n");
				}
			   }
			
   		}
   		else if (a == 1)
   		{
   			gets(tetit);
      		printf("제목 : ");
      		gets( mus[i].title);
      		printf("가수 : ");
      		gets( mus[i].singer);
      		printf("앨범 : ");
      		gets( mus[i].album);
      		printf("장르 : ");
      		scanf("%d", &mus[i].genre);
      		i++;
  		}
   }
   return 0; 
}
