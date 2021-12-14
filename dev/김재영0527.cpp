#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

typedef struct {
	char name[20];
	int num;
	char email[50];
}STUDENT;

int main(){
	STUDENT st[40];
	int i=0;
	int total=0;
	char find[20];
	
	FILE *f_file=fopen("KNU_EE_Freshman.txt","r");
	
	while(!feof(f_file)){
		fscanf(f_file, "%s %d %s", st[i].name,&st[i].num,st[i].email);
		i++;
		if(feof(f_file)) break;
	}
	total=i;
	for(i=0;i<total;i++){
		printf("%s %d %s\n",st[i].name,st[i].num,st[i].email);
	}
	
	printf("찾고싶은 이름을 입력하세요:");
	
	scanf("%s",find);
	
	for(i=0;i<total;i++){
		if(!strcmp(find,st[i].name)){
			printf("%s %d %s\n",st[i].name,st[i].num,st[i].email);
			break;
		}
	}
	
	return 0;
}
