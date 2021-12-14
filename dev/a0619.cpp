#include<stdio.h>

int main(){
	char s[10];
	int a[2]{0,0};
	int c=0,ck=1;
	scanf("%s",s);
	for(int i=0;i<10;i++){
		if(s[i]=='\0') break;
		a[c/5]=a[c/5]*10+s[i]-'0';
		c++;
	}
	a[0]*=4;
	a[1]*=4;
	for(int i=0;i<c-5;i++){
		ck*=10;
	}
	if(a[1]>ck){
		a[0]+=a[1]/ck;
		a[1]%=ck;
	}
	printf("%d",a[0]);
	if(a[1]) printf("%d",a[1]);
	else if(c>4) {
		for(int i=0;i<c-5;i++){
			printf("%d",a[1]);
		}
	}
	return 0;
}

