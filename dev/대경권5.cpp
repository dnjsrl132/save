#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
//long long* solution(const char* s0, const char* s1, const char* line, long long k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
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
