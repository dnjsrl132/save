#include<stdio.h>

int main(){
	int array[2][2];
	int i,j,temp;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			scanf("%d",&array[i][j]);
		}
	}
	for(i=0;i<4;i++){
		printf("%d ",*(array+i));
	}
	/*
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(*(*(array+(i/2))+(i%2))<*(*(array+(j/2))+(j%2))){
				temp=*(*(array+(i/2))+(i%2));
				*(*(array+(i/2))+(i%2))=*(*(array+(j/2))+(j%2));
				*(*(array+(j/2))+(j%2))=temp;
			}
		}
	}
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
	*/
}
