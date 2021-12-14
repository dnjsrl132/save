#include <stdio.h>
#include<string.h>

int main() {
	int a, b, c, d, e, f,k=0;
	char id[3][10];
	char pw[3][10];
	char check[10];
	while (1) {
    	printf("1.회원가입\n2.로그인\n3. 비밀번호 찾기\n4.사용종료\n");
    	scanf("%d", &a);
    	if(a==1){
        	printf("생성할 ID를 입력하세요<최대9자>:");
        	scanf("%s", id[k]);
         	printf("생성할 PW를 입력하세요<최대9자>:");
         	scanf("%s",pw[k]);
         	k++;
		}
      	else if (a == 2) {
         	printf("아이디를 입력하세요");
         	scanf("%s", check);
         	for(b=0;b<3;b++){
         		if(!strcmp(check,id[b])){
         			printf("비밀번호를 입력하세요");
            		scanf("%s", check);
         			if(strcmp(check,pw[b])) printf("비밀번호가 틀렸습니다");
					else printf("로그인 되었습니다");
					break;
				 }
			 }
			if(b==3) printf("존재하지 않는 아이디 입니다");
			printf("\n");
        }
      
    	else if (a == 3) {
         	printf("ID를 입력하세요:");
         	scanf("%s", check);
         	for(b=0;b<3;b++){
         		if(!strcmp(check,id[b])){
         			printf("해당 ID의 PW:%s ", pw[b]);
					break;
				}
			}
         	if(b==3) printf("존재하지 않는 아이디 입니다");
			printf("\n");
      	}
        else if (a == 4) {
        	 break;
      	}

        if (k == 4) { break; }
   }
   return 0;
}
