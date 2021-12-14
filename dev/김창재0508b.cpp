#include<stdio.h>

int main(){
	int a[5];
	int * b;
	int c;
	char d[5];
	b=a;
	//scanf("%d",&c);
	scanf("%d",a);
	printf("%d %d %d",a[0],a,&a[0]);
	return 0;
}
