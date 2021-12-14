#include<stdio.h>
#include<math.h>
//ex2
int add(int i,int j){ return i+j;} 
int sub(int i,int j){ return i-j;} 
int multi(int i,int j){ return i*j;} 
int divide(int i,int j){ return i/j;} 
//ex4
void sort(int arr[],int n){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
//ex5
int inverter(int n){return !n;}
int And2(int a,int b){return a&&b;}
int And3(int a,int b,int c){return a&&b&&c;}
int Or(int a,int b,int c){return a||b||c;}

void ex1(){
	int a[100][100]={0};
	int i,j;
	while(1){
		printf("input a index of 2d array:");
		scanf("%d %d",&i,&j);
		if(i>100||j>100) break;
		a[i][j]++;
	}
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			if(a[i][j]) printf("index %d.%d:%d\n",i,j,a[i][j]);
		}
	}
}
void ex2(){
	int check,a,b;
	while(1){
		printf("1.add \n2.subtract\n3.multiply\n4.divide\n5.end\n"); 
		scanf("%d",&check);
		if (check==5) break;
		printf("연산할 숫자 입력:");
		scanf("%d %d",&a,&b);
		if(check==1){
			printf("%d+%d=%d\n",a,b,add(a,b));
		}
		else if(check==2){
			printf("%d-%d=%d\n",a,b,sub(a,b));
		}
		else if(check==3){
			printf("%d*%d=%d\n",a,b,multi(a,b));
		}
		else if(check==4){
			printf("%d/%d=%d\n",a,b,divide(a,b));
		}
	}
}
void ex3(){
	float a[5][3],min;
	int temp;
	int check[5]={0,1,2,3,4};
	int i,j,k;
	for(i=0;i<5;i++){
		printf("%d 번째의 좌표 :",i+1);
		scanf("%f %f",&a[i][0],&a[i][1]);
		a[i][2]=sqrt(pow(a[i][0],2)+pow(a[i][1],2));
	}
	for(i=0;i<4;i++){
		for(j=i;j<5;j++){
			if(a[check[j]][2]<a[check[i]][2]){
				temp=check[i];
				check[i]=check[j];
				check[j]=temp;
			}
		}
	}
	for(i=0;i<5;i++){
		printf("%d로 가까운 점 거리 : %f, 좌표 %f %f \n",i+1,a[check[i]][2],a[check[i]][0],a[check[i]][1]);
	}
}
void ex4(){
	int S_Arr[10]={52,10,33,27,82,49,7,0,61,74};
	sort(S_Arr,10);
	for(int i=0;i<10;i++) printf("%d ",S_Arr[i]);
}
void ex5(){
	int a,b,c;
	int i=0;
	for(int i=0;i<8;i++){
		c=i%2;
		a=i/4;
		b=i/2-a*2;
		printf("A : %d\tB : %d\tC : %d\t",a,b,c);
		printf("r : %d\n",Or(And3(a,b,c),And3(a,b,!c),And2(!a,c)));
	}
}

int main(){
	ex5();
	return 0;
}
