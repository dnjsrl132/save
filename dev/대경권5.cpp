#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
//long long* solution(const char* s0, const char* s1, const char* line, long long k) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
int main(){
	const char* s0="1001";
	const char* s1="001";
	const char* line="1110";
	long long k=1;
    long long* answer = (long long*)malloc(sizeof(long long) * 2);
    char** temp=(char**)malloc(sizeof(char*)*k);
    int i,j;
    strcpy(temp[k-1],line);
    /*
    for(i=0;i<k;i++){
        for(j=0;j<sizeof(temp[k-i]);j++){
            if(temp[k][j]-'0'){
                
            }
        }
    }*/
    return 0;
}
