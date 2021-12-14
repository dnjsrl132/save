#include<iostream>
using namespace std;
int main(){
	unsigned long long HP=0;
	int ATK;
	int t,a,h;
	int n,M=0;
	int count;

	cin>>n>>ATK;
	for(int i=0;i<n;i++){
		cin>>t>>a>>h;
		if(t==1){
			count=(h-1)/ATK;
			//HP+=a*count;
			for(int j=0;j<a;j++){
				HP+=count;
			}
		}
		else{
			ATK+=a;
			if(h<HP) HP-=h;
			else{
				M=HP>M?HP:M;
				HP=0;
			}
		}
	}
	cout<<HP+1;
	return 0;
}
