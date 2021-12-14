#include<stdio.h>
int main(){
	int a;
	char b,c;
	scanf("%d",a);
	b=a%60;
	c=b%12;
	b=(b+6)%10;
	c=(c+8)%12;
	printf("%c %c",c+65,b+47);
	return 0;
}
