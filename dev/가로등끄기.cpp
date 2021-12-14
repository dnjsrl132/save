#include <stdio.h>
#include <stdlib.h>

#define MN 1e9
#define ML 99


int min(int x,int y){ return x>y ? y : x ;}

int main(){
	
	int D[1000],W[1000],Ws[1000];
	int ee[ML][ML][2];
	int n,s;
	int i,j;
	
	scanf("%d",&n);
	scanf("%d",&s);
	
	for(i=0;i<n;i++){
		scanf("%d %d",&D[i],&W[i]);
	}
	/*
	for(i=0;i<n;i++){
		ee[i][i]=MN;
		if(i==s-1) ee[i][i]=0;
		for(j=0;j<-i;j++) Ws[i]+=W[j];
		for(j=i;j<n;j++) ee[i][j]=MN;
	}
	for(i=s-1;i<n;i++){
		for(j=i-1;j>=0;j--){
			ee[i][j]=min(ee[j][i-1]+(D[i]-D[j])*(Ws[n-1]-(Ws[i-1]-Ws[j-1])),
			ee[i-1][j]+(D[i]-D[i-1])*(Ws[n-1]-(Ws[i-1]-Ws[j-1])));
			ee[j][i]=min(ee[j+1][i]+(D[j+1]-D[j])*(Ws[n-1]-(Ws[i]-Ws[j])),
			ee[i][j+1]+(D[i]-D[j])*(Ws[n-1]-(Ws[i]-Ws[j])));
		}
	}
	*/
	for(i=0;i<n;i++){
		ee[i][i][0]=ee[i][i][1]=MN;
		for(j=0;j<=i;j++) Ws[i]+=W[j];
		for(j=i;j<n;j++){ee[i][j][0]=ee[i][j][1]=MN;}
	}
	ee[s-1][s-1][0]=ee[s-1][s-1][1]=0;

	for(i=s-1;i<n;i++){
		for(j=i-1;j>=0;j--){
			ee[j][i][1]=min(ee[j][i-1][0]+(D[i]-D[j])*(Ws[n-1]-(Ws[i-1]-Ws[j-1]))
			,ee[j][i-1][1]+(D[i]-D[i-1])*(Ws[n-1]-(Ws[i-1]-Ws[j-1])));
			ee[j][i][0]=min(ee[j+1][i][0]+(D[j+1]-D[j])*(Ws[n-1]-(Ws[i]-Ws[j])),
			ee[j+1][i][1]+(D[i]-D[j])*(Ws[n-1]-(Ws[i]-Ws[j])));
		}
	}
	printf("%d",min(ee[0][n-1][0],ee[0][n-1][1]));
	return 0;
}
