#include<stdio.h>
int main(){
	int T;
	int M,N,x,y;
	int i,j,k;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		scanf("%d %d %d %d",&M,&N,&x,&y);

		for(j=0;j<M*N;j++){
			k=j*M+x;
			if(k%N==y) break;
			k=-1;
		}
		
		printf("%d\n",k);
	}
	return 0;
}
