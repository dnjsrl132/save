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
		
   		printf("1. �߰�\n2. ���\n3. �˻�\n4. ����\n");
   		printf("����� �޴��� ��ȣ�� �Է��Ͻʽÿ�.");
   		
   		scanf("%d", &a);
   		
   		
   		
   		if (a == 4)      //���� 
   		{
      		printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�. \n");
      		break;
   		}
   		else if (a == 2)
   		{
   			for(int j=0;j<i;j++){
   				printf("\n���� : %s\n", mus[j].title);
      			printf("���� : %s\n", mus[j].singer);
      			printf("�ٹ� : %s\n", mus[j].album);
      			printf("�帣 : %s\n", mus[j].genre);
			   }
   		}
   		else if (a == 3)
   		{
   			gets(tetit);
   			printf("����: ");
   			gets(tetit); 
   			for(int j=0;j<i;j++){
   				if(!strcmp(tetit,mus[j].title)){
   					printf("\n���� : %s\n", mus[j].title);
      				printf("���� : %s\n", mus[j].singer);
      				printf("�ٹ� : %s\n", mus[j].album);
      				printf("�帣 : %d\n", mus[j].genre);
      				break;
				   }
				if(j==i-1){
					printf("ã�������� �����ϴ�. \n");
				}
			   }
			
   		}
   		else if (a == 1)
   		{
   			gets(tetit);
      		printf("���� : ");
      		gets( mus[i].title);
      		printf("���� : ");
      		gets( mus[i].singer);
      		printf("�ٹ� : ");
      		gets( mus[i].album);
      		printf("�帣 : ");
      		scanf("%d", &mus[i].genre);
      		i++;
  		}
   }
   return 0; 
}
