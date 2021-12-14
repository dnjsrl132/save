#include<stdio.h>

int main(){
	int array[10];
	int change[10];
	int i,j,temp,a=0,b=9;
	for(i=0;i<10;i++){
		scanf("%d",&array[i]);
	}
	for(i=0;i<10;i++){
		if(array[i]%2==0) continue;
		for(j=0;j<10;j++){
			if(array[j]%2==0) continue;
			if(array[i]<array[j]) temp=array[i],array[i]=array[j],array[j]=temp;
		}
	}
	for(i=0;i<10;i++){
		if(array[i]%2) continue;
		for(j=0;j<10;j++){
			if(array[j]%2) continue;
			if(array[i]<array[j]) temp=array[i],array[i]=array[j],array[j]=temp;
		}
	}
	for(i=0;i<10;i++){
		if(array[i]%2) change[a++]=array[i];
		else change[b--]=array[i];
	}
	for(i=0;i<10;i++){
		printf("%d ",change[i]);
	}
	return 0;
}
