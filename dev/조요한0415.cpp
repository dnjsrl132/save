#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
char ro[20][20];

int p(){
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			if(ro[i][j]!='*') ro[i][j]='0';
			printf("%c ",ro[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int main(){
	int a,b;
	int i=9,j=9;
	int m;
	while(1){
		srand((unsigned)time(NULL));
		m=rand()%8;
		
		if(m==0||m==7||m==1) a=-1;
		else if(m==3||m==4||m==5) a=+1; 
		else a=0;
		
		if(m==1||m==2||m==3) b=+1;
		else if(m==5||m==6||m==7) b=-1;
		else b=0;
		
		if(ro[i+a][j+b]=='*') continue;
		
		i+=a, j+=b;
		
		if(i<0||i>20||j<0||j>20) break;
		
		ro[i][j]='*';
		
		p();
		
		printf("%d %d",i+1,j+1);
		
		Sleep(500);
		system("@cls clear");
	}
}

