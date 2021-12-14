#include <stdio.h>
#define MN 1000

int main(void) {
	int n,i,j=0,m,c=1,k=0;
    int a[MN];
    int b[MN]={0,1,};
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scanf("%d",&a[i]);
	}
	while(n!=0){
		m=a[0];
		for(i=1;i<n;i++){
			if(m!=a[i]){
				b[j]=c;
				c=1;
				j++;
				m=a[i];
			}
			else c++;
		}
		n=j;
		j=0;
		for(i=0;i<n;i++){
			a[i]=b[i];
		}
		a[n]=0;
		k++;
	}
	if(a[0]!=1) k++;
	printf("%d",k);
    return 0;
}
