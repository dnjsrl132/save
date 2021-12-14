#include<stdio.h>

int main(){
	int i,j;
	scanf("%d %d",&i,&j);
	if(i>j){
		printf("%d",(i*(i+1)/2)-(j*(j-1)/2));
	}
	else{
		printf("%d",(j*(j+1)/2)-(i*(i-1)/2));
	}
	return 0;
} 
