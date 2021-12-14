#include<stdio.h>

int main(){
	int array[10];
	int first=0,last=9;
	int i,j;
	int num,temp;
	for(i=0;i<10;i++){
		scanf("%d",&num);
		if(num%2){
			for(j=0;j<first;j++){
				if(num<array[j]) temp=array[j],array[j]=num,num=temp;
			}
			array[first++]=num;
		}
		else{
			for(j=9;j>last;j--){
				if(num<array[j]) temp=array[j],array[j]=num,num=temp;
			}
			array[last--]=num;
		}
	}
	for(i=0;i<10;i++){
		printf("%d ",array[i]);
	}
	return 0;
}
