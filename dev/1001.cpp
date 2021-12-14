#include<iostream>
using namespace std;
int main(){
	int N,M;
	int c[10]={0,};
	int nu[6];
	int i,x,l=0;
	int smal=0,big=9;
	int count;
	cin>>N>>M;
	for(i=0;i<M;i++){
		cin>>x;
		c[x]++;
	}
	for(i=1;i<10;i++){
		if(c[smal]) smal++;
		if(c[big]) big--;
		if(!c[smal]&&!c[big])break;
	}
	printf("%d %d",smal,big);
	while(N){
		nu[l]=N%10;
		N/=10;
		l++;
	}
	for(;l>=0;l--){
		if(c[nu[l]]){
			
		}
	}
}
