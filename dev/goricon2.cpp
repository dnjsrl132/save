#include<stdio.h>
#include<stdlib.h>
//B
int main(){
	int N,M;
	int i=0;
	int a[64];
	int j=0;
	int sum=0;
	scanf("%d",&N);
	if(N%2){
		M*=2;
		sum=1;
	}
	while(M){
		a[i]=M%2;
		M/=2;
		i++;
	}j=i;
	for(i;i>=0;i--){
		if(a[i]){
			sum+=2;
		}
		else{
			sum+=1;
		}
	}
	printf("%d\n",sum);
	for(i=j;i>=0;i--){
		if(a[i]){
			printf("[+] [*] ");
		}
		else{
			printf("[*] ");
		}
	}
	if(N%2) printf("[/]");
	return 0;
}
