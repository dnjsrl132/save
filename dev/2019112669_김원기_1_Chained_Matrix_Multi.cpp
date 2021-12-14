#include <stdio.h>
#include <stdlib.h>

#define MN 1e9
#define ML 99

FILE *f1,*f2;

void printk(int n,int c){
	for(int i=0;i<n;i++){
		if(c>0) fprintf(f2,"(");
		else fprintf(f2,")");
	}
}
int main(){
	char name[30];
	int A[ML],p[ML];
	int M[ML][ML], c[ML][ML];
	int i,j,k, n, check=1;
	
	printf("input file name?");
	scanf("%s",name);
	
	f1=fopen(name, "r");
	f2=fopen("output.txt", "w");
	
	fscanf(f1,"%d",&n);
	
	for(i=0;i<n;i++){
		fscanf(f1,"%d",&A[i]);
	}
	
	for(i=0;i<n-1;i++){
		M[i][i]=0;
		M[i][i+1]=A[i]*A[i+1]*A[i+2];
		for(j=i+2;j<n-1;j++){
			M[i][j]=MN;
		}
	}
	for(i=2;i<n-1;i++){
		for(j=i-2;j>=0;j--){
			for(k=j;k<i;k++){
				if(M[j][i]>M[j][k]+M[k+1][i]+A[i+1]*A[j]*A[k+1]){
					M[j][i]=M[j][k]+M[k+1][i]+A[i+1]*A[j]*A[k+1];
					c[j][i]=k;
				}
			}
		}
	}
	i=0,j=n-2;
	while(1){
		if(i+1==j) break;
		k=c[i][j];
		if(k==i)	i++;
		if(k==j-1)	j--;
		p[i-1]++;
		p[j]++;
	}
	
	fprintf(f2,"(");
	for(i=0;i<n-1;i++){
		fprintf(f2,"%d",i+1);
		if(p[i]==0) check=-1;
		printk(p[i],check);
	}
	fprintf(f2,")");
	
	fclose(f1);
	fclose(f2);
	return 0;
}
