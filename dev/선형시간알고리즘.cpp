#include<stdio.h>
#define FOR(i,n) for(int i=0;i<(n);i++)

int main(){
	int weight[12];
	float mean[12];
	int sum=0;
	int n=3;
	FOR(i,12)	scanf("%d",&weight[i]);
	FOR(i,n-1) sum+=weight[i];
	FOR(i,10){
		sum+=weight[i+n-1];
		mean[i]=(double)sum/n;
		sum-=weight[i];
	}
	
	FOR(i,10) printf("%.2f ",mean[i]);
	
	return 0;
}
