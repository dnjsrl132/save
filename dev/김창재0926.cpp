#include<stdio.h>
int main(){
	float F=0;
	for(int i=0;i<100;++i){
		F+=0.015625;
	}
	printf("%f",F);
}
