#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MN 99
#define ML 1e10
// ages_len�� �迭 ages�� �����Դϴ�.
// wires_len�� 2���� �迭 wires�� ��(����) �����Դϴ�.
int main() {
	int ages[5]={30,25,3,5,6};
	int answer[5]={0,},c[5]={0,};
	int i,j,temp;
    for(i=0;i<5;i++){
    	k=i;
        for(j=0;j<i;j++){
            if(ages[k]<ages[answer[j]-1]){
            	temp=answer[j];
            	answer[j]=k+1;
            	k=answer[j]-1;
			}
        }
        answer[]
        answer[i]=min+1;
        ages[min]=ML;
        c[min]++;
        for(j=0;j<=i;j++){
    		printf("%d\t",answer[j]);
		}
		printf("\n");
		for(j=0;j<5;j++){
    		printf("%d\t",c[j]);
		}
		printf("\n");
    }
    
    return 0;
}
