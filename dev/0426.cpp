#include<stdio.h>

int main()
{
	int a[2][41]={0,};
	int t;
	int n;
	scanf("%d",&t);
	a[0][0]=1,a[1][1]=1,a[0][1]=0,a[1][0]=0;
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		for(int j=2;j<=n;j++){
			if(a[0][j]||a[1][j]) continue;
			for(int k=0;k<2;k++){
				a[k][j]==a[k][j-1]+a[k][j-2];
			}
		}
		printf("%d %d\n",a[0][n],a[1][n]);
	}
	return 0;
}
