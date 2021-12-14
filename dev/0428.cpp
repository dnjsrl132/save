#include<stdio.h>

int main(){
	int k;
	int a=0,b=1,c;
	scanf("%d",&k);
	for(int i=1;i<k;i++){
		c=a+b;
		a=b;
		b=c;
	}
	printf("%d %d",a,b);
	return 0;
}
