#include <stdio.h>
#include <stdlib.h>

#define MN 1e9

FILE *f1, *f2;

int main(){
	char name[30];
	
	int i,j,k,xc,yc,x,y;
	int xi[4]={0,-1,0,1},yi[4]={-1,0,1,0};
	int temp,n;
	
	printf("Input file name?\n");
	scanf("%s",name);	
	f1=fopen(name, "r");
	f2 = fopen("output.txt", "w");
	
	fscanf(f1, "%d",&n);
	
	int InArr[n][n], touch[n][n],path[n][n];
	int load[n*n];
	
	for(i=0;i<n;i++){
		fscanf(f1,"%d",&temp);
		for(j=n-1;j>=0;j--){
			InArr[i][j]=temp%10;
			touch[i][j]=MN;
			temp/=10;
		}
	}
	touch[0][0]=0;
	path[0][0]=0;
	
	for(x=0;x<n;x++){
		for(y=0;y<n;y++){
			for(i=0;i<4;i++){
				xc=x-xi[i],yc=y-yi[i];
				if(xc<0||xc>=n||yc<0||yc>=n) continue;
				k=1-InArr[xc][yc];
				if(touch[x][y]+k<touch[xc][yc]){
					touch[xc][yc]=touch[x][y]+k;
					path[xc][yc]=i;
				}
			}
		}
	}
	k=0;
	x=y=n-1;
	while(1){
		if(x==0&&y==0) break;
		temp=path[x][y];
		load[k]=x*n+y;
		x+=xi[temp];
		y+=yi[temp];
		k++;
	}
	load[k]=0;
	fprintf(f2,"%d\n",touch[n-1][n-1]);
	for(;k>=0;k--){
		fprintf(f2,"%d %d\n",load[k]/n+1,load[k]%n+1);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
