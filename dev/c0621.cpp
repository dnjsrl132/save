#include<stdio.h>

int Answer;
int db[100000000000][2];
int max(int n,int m){
	return n>m ? n : m;
}
int main(){
	int T, test_case;
	int x,y;
	int i,j;
	
	setbuf(stdout, NULL);

	scanf("%d", &T);
	db[0][0]=db[0][1]=1;
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer=0;
		scanf("%d %d",&x,&y);
		for(i=1;i<y;i++){
			if(db[i][0]) continue;
			for(j=i;j>0;j--){
				if(db[i-j][1]==j-1) break;
			}
			if(!j) j=1;
			db[i][0]=db[i-j][0]+1;
			db[i][1]=j;
			for(j=0;j<=i/2;j++){
				if(db[i][0]>db[j][0]+db[i-j-1][0]){
					db[i][0]=db[j][0]+db[i-j-1][0];
					db[i][1]=max(db[j][1],db[i-j-1][1]);
				}
			}
		}
		for(int i=x-1;i<y;i++){
			if(Answer<db[i][0]) Answer=db[i][0];
		}
		printf("Case #%d\n", test_case+1);
	        	printf("%d\n", Answer);
        
	}
	return 0;
}
