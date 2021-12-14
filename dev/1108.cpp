#include<stdio.h>
#include<math.h>

typedef struct {
	int card[5];
}MEN;
int card[4][13]={0,};

int checkflush(MEN m){
	int color;
	color=m.card[0]/13;
	for(int j=1;j<5;j++){
		if(color!=m.card[j]/13) return 0;
	}
	return 1;
}
int checkstra(MEN m){
	int min;
	min=m.card[0];
	for(int i=1;i<5;i++) {
		min++;
		if(min==14&&i==4) min=1;
		if(min!=m.card[i]) return 0;
	}
	return 1;
}
int pair(MEN m){
	return 1;
}
int triple(MEN m){
	return 1;
}
int checkFourcard(MEN m){
	
}
int checkFullhouse(MEN m){
	if(!triple(m)) return 0;
	
}
int checkTOP(MEN m){
	return m.card[4];
}
int putcard(){
	int x;
	srand();
	while(1){
		x=rand()%52;
		if(card[x/13][x%13]) {
			card[x/13][x%13]++;
			return x;
		}
	}
}
int main(){
	int x;
	MEN user,computer[3];
	x=putcard();
	
}
