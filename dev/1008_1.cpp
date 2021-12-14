#include<stdio.h>
#include<stdlib.h>
int fac(int n){
	if(n<=2) return n;
	return n*fac(n-1);
}
int main(void){
	int N,K;
	scanf("%d %d",&N,&K);
	printf("%d",fac(N)/(fac(K)*fac(N-K)));
	return 0;
}
