#include<stdio.h>

int swap(int *n, int *m){
	int temp;
	temp=*m;
	*m=*n;
	*n=temp;
}
int main(){
	int a=10;
	int b=5;
	swap(&a,&b);
	printf("%d %d",a,b);
	return 0;
}
