#include<iostream>
using namespace std;
int main(){
	char a[10]="abcde",b[10]="abc";
	int i=0;
	char m;
	while(1){
		if(a[i]=='\0'||b[i]=='\0') break;
		i++;
	}
	if(a[i]!='\0'){
		m='b';
	}
	else if(b[i]=='\0'){
		m='c';
	}
	else{
		m='a';
	}
	printf("%c",m); 
	return 0;
}
