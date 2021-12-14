#include <iostream>
#define MN 1000

using namespace std;

char a[MN][MN];
int n,m;
int c[26];
int b[26];
int xi[4]={-1,0,1,0};
int yi[4]={0,1,0,-1};
int bo[MN][MN];
int M=0;

int f(int x,int y){
    int c;
    for(int i=0;i<4;i++){
    	if(x+xi[i]<0||x+xi[i]==n||y+yi[i]<0||y+yi[i]==m) continue;
    	if(a[x][y]==a[x+xi[i]][y+yi[i]]){
			bo[x][y]=1;
			break;
		}
    }
    return 0;
}
int g(int x,int y){
	int sum;
	int i,j;
	if(bo[x][y]) return 0;
	for(i=x;i<n;i++){
		if(bo[i][y]){
			i--;
			break;
		}
	}
	for(;i>=0;i--){
		for(j=y;j<m;j++){
			if(bo[i][j]){
				sum=(i-x)*(j-y);
				if(M<sum) M=sum;
				break;
			}
		}
	}
	return M;
}
int main(void) {
    int i,j,k;
    int Max=0;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            f(i,j);
        }
    }
    for(i=0;i<n;i++){
    	for(j=0;j<m;j++){
    		g(i,j);
		}
	}
    printf("%d",M);
    return 0;
}
