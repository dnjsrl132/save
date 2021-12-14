#include<stdio.h>

int main(){
	int n,r,c,k;
	scanf("%d %d %d",&n,&r,&c);
	k=(r+c)%2;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((i+j)%2==k) printf("v");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}
