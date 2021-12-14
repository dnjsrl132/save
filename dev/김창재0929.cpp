#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[10];
	int num;
	int i,j;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
		for(j=i;j>0;j--){
			if(a[j-1]>a[j]){
				a[j-1]+=a[j];
				a[j]=a[j-1]-a[j];
				a[j-1]-=a[j];
			}
			else break;
		}
		for(j=0;j<=i;j++){
			printf("%d ",a[j]);
		}
		printf("\n");
	}
}
