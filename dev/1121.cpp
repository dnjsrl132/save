#include<stdio.h>
#define p 1000000007
#define MN 4000000

long long fac[MN]={1,1,0};
void factorial(int n){
	long long result;
	for(int i=2;i<=n;i++){
		result=i*fac[i-1];
		fac[i]=result%p;
	}
}
int main(){
	int n,k;
	long long r;
	scanf("%d %d",&n,&k);
	factorial(n);
	r=fac[n];
	while(1){
		if(r%fac[k]==0){
			r/=fac[k];
			break;
		}
		r+=p;
	}
	while(1){
		if(r%fac[n-k]==0){
			r/=fac[n-k];
			break;
		}
		r+=p;
	}
	printf("%d",r);
	return 0;
}
