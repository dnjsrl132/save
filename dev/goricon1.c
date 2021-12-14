#include<stdio.h>
#include<stdlib.h>
//j
int main(){
	int n, invert;
	int i,j;
	scanf("%d %d", &n, &invert);
	int arr[n];
	int temp;
	int count=0;
	int check;
	check=n*(n-1)/4;
	if(check<invert){
		for(i = 0; i < n; i++)
			arr[i] = n-i;
		invert=check*2-invert;
	}
	else{
		for(i = 0; i < n; i++)
			arr[i] = i+1;
	}
	for(i = 0; i < n-1; i++) {
		if(count==invert) break;
		temp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=temp;
		count++;
	}
    if(invert<0) printf("-1");
    else{
	for(i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
    }
	return 0;
}
