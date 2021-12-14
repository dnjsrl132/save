#include<stdio.h>
#define MN 5000
int main(){
	int n,c;
	int arr[MN];
	int temp;
	int sum=0;
	int i,j,k=0;
	scanf("%d %d",&n,&c);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	i=0;j=0;
	while(i<n&&j<n){
		if(sum==c){
			k=1;
			break;
		}
		else if(sum>c){
			sum-=arr[i];
			i++;
		}
		else{
			sum+=arr[j];
			j++;
		}
	}
	if(sum==c) k=1;
	printf("%d",k);
}
