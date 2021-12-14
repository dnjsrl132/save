#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int i;
	srand(time(NULL));
	i=rand()%2+1;
	printf("%d",i);
	return 0;
}
