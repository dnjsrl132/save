#include <stdio.h>
#include <stdlib.h>

#define MN 1e9
#define ML 99

FILE *f1, *f2;

int min(int x,int y){ return x>y ? y : x ;}

int main(){
	char name[30];
	int D[ML],W[ML],Ws[ML],A[ML];
	int ee[ML][ML][2],pp[ML][ML][2];
	int n,s;
	int i,j,k,c,t;
	printf("Input file name?\n");
	scanf("%s",name);	
	f1=fopen(name, "r");
	f2 = fopen("output.txt", "w");
	
	fscanf(f1, "%d",&n);
	fscanf(f1, "%d",&s);
	
	for(i=0;i<n;i++){
		fscanf(f1, "%d %d",&D[i],&W[i]);
	}
	
	for(i=0;i<n;i++){
		ee[i][i][0]=ee[i][i][1]=MN;
		pp[i][i][0]=pp[i][i][1]=0;
		for(j=0;j<=i;j++) Ws[i]+=W[j];
		for(j=i;j<n;j++){ee[i][j][0]=ee[i][j][1]=MN;}
	}
	ee[s-1][s-1][0]=ee[s-1][s-1][1]=0;
	
	
	i=s-1;
	for(j=n-1;j>=0;j--){
		if(i==j) continue;
		if(i<j){
			ee[i][j][1]=ee[i][j-1][1]+(D[j]-D[j-1])*(Ws[n-1]-(Ws[j-1]-Ws[i-1]));
			pp[i][j][1]=j;
		}
		else{
			ee[j][i][0]=ee[j+1][i][0]+(D[j+1]-D[j])*(Ws[n-1]-(Ws[i]-Ws[j]));
			pp[j][i][0]=j+2;
		}
	}
	
	for(i=s;i<n;i++){
		for(j=s-2;j>=0;j--){
			
			if(ee[j][i-1][0]+(D[i]-D[j])*(Ws[n-1]-(Ws[i-1]-Ws[j-1]))
			>ee[j][i-1][1]+(D[i]-D[i-1])*(Ws[n-1]-(Ws[i-1]-Ws[j-1]))){
				k=ee[j][i-1][1]+(D[i]-D[i-1])*(Ws[n-1]-(Ws[i-1]-Ws[j-1]));
				c=i-1;
			}
			else{
				k=ee[j][i-1][0]+(D[i]-D[j])*(Ws[n-1]-(Ws[i-1]-Ws[j-1]));
				c=j;
			}
			ee[j][i][1]=k;
			pp[j][i][1]=c+1;
			if(ee[j+1][i][0]+(D[j+1]-D[j])*(Ws[n-1]-(Ws[i]-Ws[j]))>
			ee[j+1][i][1]+(D[i]-D[j])*(Ws[n-1]-(Ws[i]-Ws[j]))){
				k=ee[j+1][i][1]+(D[i]-D[j])*(Ws[n-1]-(Ws[i]-Ws[j]));
				c=i;
			}
			else{
				k=ee[j+1][i][0]+(D[j+1]-D[j])*(Ws[n-1]-(Ws[i]-Ws[j]));
				c=j+1;
			}
			ee[j][i][0]=k;
			pp[j][i][0]=c+1;
		}
	}
	if(ee[0][n-1][0]<ee[0][n-1][1]){
		A[0]=1;
		c=0;
	}
	else{
		A[0]=n;
		c=1;
	}
	i=0;
	j=n-1;
	fprintf(f2, "%d\n",ee[i][j][c]);
	k=pp[i][j][c];
	for(t=1;t<n;t++){
		if(c){
			if(k==i+1){
				c=0;
			}
			j--;
		}
		else{
			if(k==j+1){
				c=1;
			}
			i++;
		}
		A[t]=k;
		k=pp[i][j][c];
	}
	for(i=n-1;i>=0;i--){
		fprintf(f2, "%d\n",A[i]);
	}
	
	fclose(f1);
	fclose(f2);
	return 0;
}
