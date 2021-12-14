#include<stdio.h>
int count[8]={0,};
int a[8]={1,2,3,4,5,6,7,8};
int b[8]={0,};
int n;
int coun(int i){
	for(;i<n;i++){
		if(!count[i]) {
			count[i]++;	
			return a[i];
		}
	}
	return 9;
}
int f(int k){
	int temp=0;
	if(!k){
		for(int i=0;i<n;i++){
			printf("%d ",b[i]);
		}
		printf("\n");
		return 0;
	}
	for(int i=0;i<k;i++){
		b[n-k]=coun(temp);
		f(k-1);
		temp=b[n-k];
		count[b[n-k]-1]=0;
	}
}

int main(){
	int b[8]={0};
	
	scanf("%d",&n);
	
	f(n);
	
	return 0;
}
