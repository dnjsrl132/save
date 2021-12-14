#include <stdio.h>

int main(void) {
	int n,k,temp;
	int a[10][200];
	int b,c,check,m=0;
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
    	for(int j=0;j<k;j++){
    		scanf("%d",&a[i][j]);
		}
	}
	for(int h=0;h<n;h++){
		for(int i=0;i<k;i++){
			for(int j=i;j<k;j++){
				if(a[h][i]>a[h][j]){
					temp=a[h][i];
					a[h][i]=a[h][j];
					a[h][j]=temp;
				}
			}
		}
	}
    for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){
    		b=c=0;
    		check=0;
    		while(b<k&&c<k){
    			if(a[i][b]==a[j][c]){
    				b++;
    				c++;
    				check++;
				}
				else if(a[i][b]>a[j][c]){
					c++;
				}
				else{
					b++;
				}
			}
			if(m<check)m=check;
		}
	}
    printf("%d", m);
    return 0;
}
