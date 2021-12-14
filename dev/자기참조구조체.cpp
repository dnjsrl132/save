#include<stdio.h>
#include<stdlib.h>
struct data{
	int da;
	struct data *link;
};
int main(){
	int a,b;
	struct data *xc,*x;
	
	xc=(struct data *) malloc(sizeof(struct data));
	
	x=xc;
	
	scanf("%d %d",&a,&b);
	
	for(int i=1;i<a;i++){
		x->da=i;
		x->link=(struct data *) malloc(sizeof(struct data));
		x=x->link;
	}

	x->da=a;
	x->link=xc;
	x=xc;
	
	while(x!=x->link){
		xc=x;
		for(int i=0;i<b-2;i++){
			xc=xc->link;
		}
		x=xc->link;
		xc->link=x->link;
		x=x->link; 
	}
	
	printf("%d ",x->da);
	
	return 0;
}
