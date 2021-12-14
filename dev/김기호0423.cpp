#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10000
#define INF 99

int W[MAX][MAX];
int D[MAX][MAX];
int P[MAX][MAX];
 

int contains(int A,int k, int n);
int minimum(int i, int A, int *minJ, int n);
void travel(int n);
int diff(int A, int j){return A&~(1<<(j-2));}
bool isIn(int i,int A,int n) {return A & (1<<(i-2));}

int main(){
	int n,size;
	scanf("%d",&n);
	size=(int)pow(2,n-1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&W[i][j]);
		}
	}
	
	travel(n);
	
	printf("%d\nv1",D[1][size-1]);
	int A=size-1;
	int j=P[1][A];
	for(int i=0;i<n-1;i++){
		printf("->v%d",j);
		A=diff(A,j);
		j=P[j][A];
	}
	printf("->v1");
	return 0;
}

int minimum(int i, int A, int *minJ, int n) {
	int j, m, min;
	min = INF;
	for (j = 2; j <=n; j++) {
		if (!isIn(j, A, n)) continue;
		m = W[i][j] + D[j][diff(A, j)];
		if (min > m) { 
			min = m; 
			*minJ = j; 
		}
	}
	return min;
}

void travel(int n) {
	int i, j, A;
	int size = (int)pow(2, n - 1);
	for (i = 2; i <= n; i++)
		D[i][0] = W[i][1];
	for (A = 1; A < size; A++) {
		for (i = 2; i <= n; i++) {
			if (isIn(i, A, n)) continue; 
			D[i][A] = minimum(i, A, &j, n);
			P[i][A] = j; // the value that gave the minimum
		}
	}
	A = size - 1;
	// Find the minimum from 1 to j
	D[1][A] = minimum(1, A, &j, n);
	P[1][A] = j; // the value that gave the minimum
}
