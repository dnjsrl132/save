#include<stdio.h>
#include<stdlib.h>
int array[5][1000]={0,};
int count[5]={0,};
int len(int n){
	int c=0;
	while(n){
		c++;
		n/=10;
	}
	return c;
}
int sumperfact(int sum,int n){
	int array[6]={1,4,9,16,25,36};
	int sum_=0;
	for(int i=0;i<n;i++){
		sum_+=sum%10;
		sum/=10;
	}
	for(int i=0;i<6;i++){
		if(sum_==array[i]) return 1;
	}
	return 0;
}
int main(){
	int n=1;
	int sum=0;
	int l;
	int bol;
	int a[5];
	while(sum<100000){
		sum=n*n;
		l=len(sum);
		int temp=sum;
		for(int i=0;i<l;i++){
			a[l-1-i]=temp%10;
			temp/=10;
		}
		if(sumperfact(sum,l)){
			switch(l){
				case 3:
					bol=(a[1]==a[2]);
					break;
				case 4:
					bol=0;
					for(int i=0;i<count[0];i++) if(a[2]==array[0][i]) bol=1;
					break;
				case 5:
					bol=(a[2]==a[3]);
					break;
				default:
					bol=1;
					break;
			}
			if(bol) array[l-1][count[l-1]++]=sum;	
		}
		n++;
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<count[i];j++){
			printf("%d\t",array[i][j]);
		}
		printf("\n");
	}
	return 0;
}
