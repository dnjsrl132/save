#include <stdio.h>

int Answer;
int c;
int db[1000000]={0,0,1};

int g(int i){
	for(int j=4;j<=i+1;j+=2){
		if(!db[j]) continue;
		if((db[j/2])%2&&!db[j/2]) db[j/2]=db[j/2+1]+1;
		db[j]=db[j/2]+1;
	}
	return 0;
}
int f(int i){
	if(db[i]) return db[i];
	if(db[i/2]%2) db[i/2]=f(i/2+1)+1;
	db[i]=f(i/2)+1;
	return db[i];
}
int main(void)
{
	int T, test_case,c,t;
	int a[3];
	setbuf(stdout, NULL);

	scanf("%d", &T);
	
	for(test_case = 0; test_case < T; test_case++)
	{
	    Answer=0;
	    scanf("%d %d",&a[0],&a[1]);
	    for(int i=a[0];i<=a[1];i++){
	    	if(i%2) {
	    		f(i);
				db[i]=db[i+1]+1;
			}
	    	Answer+=db[i];
	    }
		printf("Case #%d\n", test_case+1);
	        	printf("%d\n", Answer);
        
	}

	return 0;
}
