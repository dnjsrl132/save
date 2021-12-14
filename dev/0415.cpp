#include<stdio.h>
#include<string.h>
char s[7]={0};
int f(){
		if(s=='black') return 0;
		if(s=='brown') return 1;
		if(s=='red') return 2;
		if(s=='orange') return 3;
		if(s=='yellow') return 4;
		if(s=='green') return 5;
		if(s=='blue') return 6;
		if(s=='violet') return 7;
		if(s=='grey') return 8;
		if(s=='white') return 9;
}
int main(){
	
	int i,j,k;
	scanf("%s",s);
	i=f();
	scanf("%s",s);
	j=f();
	scanf("%s",s);
	k=f();
	printf("%d%d",i,j);
	for(int i=0;i<k-1;i++){
		printf("0");
	}
	return 0;
}
