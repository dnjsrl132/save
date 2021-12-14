#include<iostream>

using namespace std;

int main(){
	int n,q,b;
	int st,t;
	char s[300000];
	int k[150000];
	int j=0;
	cin>>n>>q>>b;
	gets(s);
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			k[j++]=i;
		}
		else if (s[i]==')'){
			s[k[j]]==i-'0';
			s[i]==k[j--]-'0';
		}
	}
	for(int i=0;i<q;i++){
		cin>>st>>t;
		if(st>t){
			b=st;
			st=t;
			t=b;
		}
		b=t-st;	
		for(j=st;j<n;j++){
			if(s[j]!='.'){
				if(b>s[j]-st+2) b=s[j]-st+2;
			}
		}
		cout<<b<<"\n";
	}
	return 0;
}
