#include<stdio.h>

int main(){
	char str[20],strl[20];
	char *p=NULL;
	const char* q=NULL;
	scanf("%s",str);
	p=str;
	p="abcdefghij";	//문자열 배열로 인식 

	q="abcdefghij";	//문자열 상수로 인 
	
	p[0]='c';		//불가능 문자열 상수여서, 실행 가능 
	q[0]='c';		//불가능 문자열 상수여서, 실행 불가 
	printf("%c ",p[5]);
	printf("%c ",q[5]);
	printf("%s\n",p);
	printf("%d\n",p);
	printf("%s",q);
}
