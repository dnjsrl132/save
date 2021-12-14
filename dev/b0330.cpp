#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int check(int n){
	double c=sqrt(n);
	int x=c;
	return (c-x>0.0000001);
}
int main(){
	int count[10]={0,};
	int i[10]={0,};
	printf("A MERRY XMAS TO ALL\n");
	for( i[0]=1;i[0]<10;i[0]++){//a
		if(check(i[0])) continue;
		for( i[1]=1;i[1]<10;i[1]++){//t
			for( i[2]=0;i[2]<10;i[2]++){//o
				if(check(i[1]+i[2])) continue;
				if(check(i[1]*10+i[2])) continue;
				for( i[3]=0;i[3]<10;i[3]++){//l
					if(check(i[0]+2*i[3])) continue;
					if(check(i[0]*100+i[3]*11)) continue;
					for( i[4]=1;i[4]<10;i[4]++){//x
						for( i[5]=1;i[5]<10;i[5]++){//m
							for( i[6]=0;i[6]<10;i[6]++){//s
							if(check(i[0]+i[4]+i[5]+i[6])) continue;
							if(check(i[4]*1000+i[5]*100+i[0]*10+i[6])) continue;
								for( i[7]=0;i[7]<10;i[7]++){//e
									for( i[8]=0;i[8]<10;i[8]++){//r
										for(i[9]=0;i[9]<10;i[9]++){//y
											if(check(i[5]+i[7]+i[8]*2+i[9])) continue;
											if(check(i[5]*10000+i[7]*1000+i[8]*110+i[9])) continue;
											int sum=0;
											for(int j=0;j<10;j++){
												if(count[i[j]]) continue;
												count[i[j]]=1;
												sum++;
											}
											for(int j=0;j<10;j++){
												count[j]=0;
											}
											if(sum==10)printf("%d %d%d%d%d%d %d%d%d%d %d%d %d%d%d\n",i[0],i[5],i[7],i[8],i[8],i[9],i[4],i[5],i[0],i[6],i[1],i[2],i[0],i[3],i[3]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
