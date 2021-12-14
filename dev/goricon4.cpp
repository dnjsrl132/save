#include<stdio.h>
#include<stdlib.h>
//D
int main(){
	long int N,Q;
	scanf("%ld %ld",&N,&Q);
	int a[N];
	int count=0;
	long int num,x,y;
	for(long int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<Q;i++){
		scanf("%ld",&num);
		if(num==1){
			scanf("%ld %ld",&x,&y);
			a[count+x-1]+=y;	
		}
		else if(num==2){
			scanf("%ld",&x);
			count-=x%N;
			if(count<0) count+=N;
		}
		else{
			scanf("%ld",&x);
			count+=x%N;
			if(count>N) count-=N;
		}
	}
	for(int i=0;i<N;i++){
		printf("%d ",a[(i+count)%N]);
	}
	return 0;
}
