#include<stdio.h>

int main(){
	long long int m,M;
	long long int n=0;
	
	scanf("%d %d",&m,&M);
	
	for(int i=1;i<=M/2;i++){
		if(m<=i*i&&i*i<=M) n++;
	}
	
	printf("%ld",M-m+1-n);
	
	return 0;
}
