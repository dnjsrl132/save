
#include "pch.h"

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
	int i = 0;
	while (1)
	{

		printf("1. 추가\n2. 출력\n3. 검색\n4. 종료\n");
		printf("사용할 메뉴의 번호를 입력하십시오.");

		scanf_s("%d", &a, sizeof(int)+1);
		
		if (a == 4)      //종료 
		{
			printf("종료를 선택하셨습니다. 프로그램을 종료합니다. \n");
			break;
		}
		else if (a == 2)
		{
			for (int j = 0; j < i; j++) {
				printf("\n제목 : %s\n", mus[j].title);
				printf("가수 : %s\n", mus[j].singer);
				printf("앨범 : %s\n", mus[j].album);
				printf("장르 : %d\n", mus[j].genre);
			}
		}
		else if (a == 3)
		{
			printf("제목: ");
			gets_s( tetit);
			for (int j = 0; j < i; j++) {
				if (!strcmp(tetit, mus[j].title)) {
					printf("\n제목 : %s\n", mus[j].title);
					printf("가수 : %s\n", mus[j].singer);
					printf("앨범 : %s\n", mus[j].album);
					printf("장르 : %d\n", mus[j].genre);
					break;
				}
				if (j == i - 1) {
					printf("찾는음악이 없습니다. \n");
				}
			}

		}
		else if (a == 1)
		{
			printf("제목 : ");
			gets_s( mus[i].title,51);
			printf("가수 : ");
			gets_s( mus[i].singer,50);
			printf("앨범 : ");
			gets_s( mus[i].album,50);
			printf("장르 : ");
			scanf_s("%d", &mus[i].genre, sizeof(int));
			i++;
		}
		else {
			printf("다른 숫자를 눌러주세요\n");
		}
	}
	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
