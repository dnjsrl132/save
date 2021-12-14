#include<stdio.h>
#include<stdlib.h>

int main(){
	int * a;
	a=(int *) malloc(sizeof(int));
	printf("%d",a);
}
