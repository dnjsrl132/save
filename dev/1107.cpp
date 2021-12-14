#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define FOR(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main(){
	vector<char> str;
	char s[30],f[30],t[30];
	int n,m;
	int i;
	cin>>n>>m;	//n개중 m개 배열 
	
	FOR(i,m){
		str.push_back('a'+i);
	}
	for(i=0;i<str.size();i++) t[i]=str[i];
	t[i]='\0';
	printf("%s",t);
	return 0;
}
