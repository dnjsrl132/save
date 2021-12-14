#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
	int card[5];
	int lank[9]={0,};
	int Mp,mp;
	int num;
}MEN;
int card[13][4]={0,};
int checkTOP(MEN m){return m.card[4]/4;}
int checktwopair(MEN m){
	int i,c=0;
	if(m.mp!=2)return 0;
	for(i=0;i<4;i++){
		if(m.card[i]/4!=m.card[i+1]/4) c+=i;
	}
	if(c<4||c>6) return 0;
	if(c==6&&m.card[2]/4!=m.card[3]/4) return 0;
	return (m.card[3]/4)*100+m.card[1]/4;
}
int checkonepair(MEN m){
	if(m.mp!=2||m.mp!=2) return 0;
	if(checktwopair(m)) return 0;
	for(int i=1;i<5;i++){
		if(m.card[i]/4==m.card[i-1]/4) return m.card[i]/4;
	}
	return 0;
}
int checktriple(MEN m){
	if(m.mp!=3) return 0;
	return m.card[2]/4;
}
int checkstra(MEN m){
	int min;
	int i=0;
	min=m.card[i]/4;
	if(!min&&m.card[1]/4==8) min=8; 
	for(;i<5;i++) {
		min++;
		if(min!=m.card[i]/4) return 0;
	}
	if(m.card[4]/4==12){
		if(m.card[0]/4!=1) return 0;
		else return 13;
	}
	return m.card[4]/4;
}
int checkflush(MEN m){
	int color;
	color=m.card[0]%4;
	for(int j=1;j<5;j++){
		if(color!=m.card[j]%4) return 0;
	}
	return m.card[4]/4;
}
int checkFullhouse(MEN m){
	if(m.Mp!=3||m.mp!=2) return 0;
	return checktriple(m)*100+checkonepair(m);
}
int checkFourcard(MEN m){
	if(m.Mp!=4) return 0;
	return m.card[2]/4;
}
int checkSF(MEN m){
	if(!checkstra(m)||!checkflush(m)) return 0;
	return checkstra(m);
}
int putcard(){
	int x;
	srand(time(NULL));
	while(1){
		x=rand()%52;
		if(!card[x/4][x%4]) {
			card[x/4][x%4]++;
			return x;
		}
	}
}
void lanked(MEN *m){
	m->lank[0]=checkSF(*m);
	m->lank[1]=checkFourcard(*m);
	m->lank[2]=checkFullhouse(*m);
	m->lank[3]=checkflush(*m);
	m->lank[4]=checkstra(*m);
	m->lank[5]=checktriple(*m);
	m->lank[6]=checktwopair(*m);
	m->lank[7]=checkonepair(*m);
	m->lank[8]=checkTOP(*m);
}
void end(MEN m){
	int i;
	int a,b;
	char c[4]={'J','Q','K','A'};
	for(i=0;i<9;i++) if(m.lank[i]) break;
	printf("%d`s ",m.num);
	a=m.lank[i]/100;
	b=m.lank[i]%100;
	if(a){
		if(a>9){
			printf("%c ",c[m.lank[i]-9]+1);
		}
		else{
			printf("%d ",m.lank[i]+1);
		}
	}
	if(b>9){
		printf("%c ",c[m.lank[i]-9]+1);
	}
	else{
		printf("%d ",m.lank[i]+1);
	}
	switch(i){
		case 0: printf("straight flush");break;
		case 1: printf("Fourcard");break;
		case 2: printf("Fullhouse");break;
		case 3: printf("flush");break;
		case 4: printf("straight");break;
		case 5: printf("triple");break;
		case 6: printf("twopair");break;
		case 7: printf("onepair");break;
		case 8: printf("top");break;
		default : break;
	}
}
void print(MEN m){
	char c[4]={'a','b','c','d'};
	for(int i=0;i<5;i++) printf("%c %2d ",c[m.card[i]%4],m.card[i]/4);
}
void sortM(MEN *m){
	int temp;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(m->card[i]>m->card[j]){
				temp=m->card[i];
				m->card[i]=m->card[j];
				m->card[j]=temp;
			}
		}
	}
}
int main(){
	int x;
	MEN user[2],computer;

	for(int j=0;j<2;j++){
		for(int i=0;i<5;i++){
			user[j].num=j+1;
			x=putcard();
			user[j].card[i]=x;
		}
		lanked(&user[j]);
	}
	print(user[0]);
	printf("\n");
	print(user[1]);
	printf("\n");
	sortM(&user[0]);
	sortM(&user[1]);
	print(user[0]);
	printf("\n");
	print(user[1]);
	printf("\n");
	for(int i=0;i<9;i++){
		if(user[0].lank[i]>user[1].lank[i]){
			end(user[0]);
			printf(" win\n");
			end(user[1]);
			printf(" lose\n");
			break;
		}
		else if(user[0].lank[i]<user[1].lank[i]){
			end(user[1]);
			printf(" win\n");
			end(user[0]);
			printf(" lose\n");
			break;
		}
	}
	return 0;
}
