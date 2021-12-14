#include<stdio.h>

int main(){
	int t;
	int c;
	int coin[4]={25,10,5,1};
	int re;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&c);
		for(int j=0;j<4;j++){
			re=c/coin[j];
			c%=coin[j];
			printf("%d ",re);
		}
		printf("\n");
	}
	return 0;
}
