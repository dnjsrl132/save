#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int i=1;
	int a[10]={0,};
	string s;
	getline(cin, s);
	while(s[i]!='\n'){
		a[i]=int(s[i])*4;
		if(a[i]>9){
			a[i-1]++;
			a[i]-=10;
		}
		i++;
	}
	for(int j=0;i<j;i++){
		if(!a[j]) continue;
		cout<<a[j];
	}
	return 0;
}
