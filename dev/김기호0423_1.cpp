#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10000
#define INF 99

int W[MAX][MAX];//W[i][j]=i에서 j로 바로 가는데 걸리는 거리 
int D[MAX][MAX];//D[i][A]=i에서 A를 걸쳐 1로가는데 걸리는 거리 
int P[MAX][MAX];//P[i][A]=i에서 A를 걸쳐 갈때 가장 최근에 거친 장소 집합 

void travel(int n,int size);
int minimum(int i,int A,int *minj,int n);
bool isinA(int A,int i);
int m(int x,int y){
	return x>y?y:x;
}
int diff(int A,int j){
	return A&~(1<<(j-1));
}

int main(){
	int n,size;
	scanf("%d",&n);
	size=(int)pow(2,n-1);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&W[i][j]);
		}
	}
	travel(n,size);
	printf("W\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%5d",W[i][j]);
		}
		printf("\n");
	}
	printf("D\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<size;j++){
			printf("%5d",D[i][j]);
		}
		printf("\n");
	}
	printf("P\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<size;j++){
			printf("%5d",P[i][j]);
		}
		printf("\n");
	}
}

void travel(int n,int size){
	int i,j,k,A;
	for(i=1;i<n;i++) D[i][0]=W[i][0];
	for(k=0;k<n;k++){
		for(A=1;A<size;A++){
			for(i=1;i<n;i++){
				if(!isinA(A,i)) continue;
				D[i][A]=minimum(i,A,&j,size);
				P[i][A]=j;
			}
			
		}
	}
	D[0][--A]=minimum(0,A,&j,size);
	P[0][A]=j;
}
bool isinA(int A,int i){
	return (A&(1<<i-1));
}
int minimum(int i,int A,int *minj,int size){
	int min=INF;
	int m;
	for(int j=0;j<size;j++){
		if(!isinA(A,j)) continue;
		m=W[i][j]+D[j][diff(A,j)];
		if(min>m){
			m=min;
			*minj=j+1;
		}
	}
	return min;
}
