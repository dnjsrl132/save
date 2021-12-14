#include <iostream>

using namespace std;

int f(char a[5]){
	int sum=0;
	for(int i=0;i<5;i++){
		if(i==2) continue;
		sum+=a[i]-'0';
		sum*=10;
	}
	return sum/10;
}

int main(void) {
    char a[5];
    int x,y,n,m,c;
    int ai,bi[10],ci[10];
    cin>>a;
    cin>>x>>y;
    cin>>n>>m;
	ai=f(a);
    for(int i=0;i<n;i++){
    	cin>>a;
    	bi[i]=f(a);
	}
	for(int i=0;i<m;i++){
		cin>>a;
		ci[i]=f(a);
	}
	for(int i=0;i<n;i++){
		if(ai<bi[i]) {
			ai=bi[i]+x;
			break;
		}
	}
	for(int i=0;i<m;i++){
		if(ai<ci[i]){
			ai=ci[i]+y;
			break;
		}
	}
	if(ai%100>=60){
		ai+=40;
	}
	cout<<ai/100<<":"<<ai%100;
    return 0;
}
