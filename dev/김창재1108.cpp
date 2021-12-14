#include<stdio.h>

void f1(int i,int j){
	int temp;
	temp=i;
	i=j;
	j=temp;
}
void f2(int *i,int *j){
	int temp;
	temp=*i;
	*i=*j;
	*j=temp;
}
void f3(int *i,int *j){
	int *temp;
	temp=i;
	i=j;
	j=temp;
}

int* f4(int *i,int *j){
	//
	return i;
}


int main(){
	int a,b;
	int c;
	int* d;
	a=5,b=4;
	
	f1(a,b);
	printf("%d %d \n",a,b);	
	f2(&a,&b);
	printf("%d %d \n",a,b);
	f3(&a,&b);
	printf("%d %d \n",a,b);
	d=f4(&a,&b);
	printf("%d %d",d,&a);
	return 0;
}
