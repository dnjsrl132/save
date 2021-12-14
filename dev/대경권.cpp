#include<iostream>

using namespace std;

int main(){
	int a,b;
	int db[101][101];
	cin>>a>>b;
	db[1][2]=2;db[3][5]=4;db[4][7]=6;
	for(int i=0;i<=a;i++){
		if(i==0) {
			for(int j=0;j<=b;j++){
				db[i][j]=1;
			}
		}
		db[i][i]=1;
		db[i][i+1]=3;
		for(int j=0;j<i;j++){
			
		}
		if(db[i][j]) continue;
	}
}
/*
0 0~	1
1 1	1
1 2	2
1 3~	3
2 2	1
2 3~	3
3 3	1
3 4	3
3 5	4
3 6~	5
4 4	1
4 5	3
4 6	5
4 7	
*/
