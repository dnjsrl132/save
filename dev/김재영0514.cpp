#include<stdio.h>

int main(){
	char str[20],strl[20];
	char *p=NULL;
	const char* q=NULL;
	scanf("%s",str);
	p=str;
	p="abcdefghij";	//���ڿ� �迭�� �ν� 

	q="abcdefghij";	//���ڿ� ����� �� 
	
	p[0]='c';		//�Ұ��� ���ڿ� �������, ���� ���� 
	q[0]='c';		//�Ұ��� ���ڿ� �������, ���� �Ұ� 
	printf("%c ",p[5]);
	printf("%c ",q[5]);
	printf("%s\n",p);
	printf("%d\n",p);
	printf("%s",q);
}
