#include <stdio.h>
#include<string.h>

int main() {
	int a, b, c, d, e, f,k=0;
	char id[3][10];
	char pw[3][10];
	char check[10];
	while (1) {
    	printf("1.ȸ������\n2.�α���\n3. ��й�ȣ ã��\n4.�������\n");
    	scanf("%d", &a);
    	if(a==1){
        	printf("������ ID�� �Է��ϼ���<�ִ�9��>:");
        	scanf("%s", id[k]);
         	printf("������ PW�� �Է��ϼ���<�ִ�9��>:");
         	scanf("%s",pw[k]);
         	k++;
		}
      	else if (a == 2) {
         	printf("���̵� �Է��ϼ���");
         	scanf("%s", check);
         	for(b=0;b<3;b++){
         		if(!strcmp(check,id[b])){
         			printf("��й�ȣ�� �Է��ϼ���");
            		scanf("%s", check);
         			if(strcmp(check,pw[b])) printf("��й�ȣ�� Ʋ�Ƚ��ϴ�");
					else printf("�α��� �Ǿ����ϴ�");
					break;
				 }
			 }
			if(b==3) printf("�������� �ʴ� ���̵� �Դϴ�");
			printf("\n");
        }
      
    	else if (a == 3) {
         	printf("ID�� �Է��ϼ���:");
         	scanf("%s", check);
         	for(b=0;b<3;b++){
         		if(!strcmp(check,id[b])){
         			printf("�ش� ID�� PW:%s ", pw[b]);
					break;
				}
			}
         	if(b==3) printf("�������� �ʴ� ���̵� �Դϴ�");
			printf("\n");
      	}
        else if (a == 4) {
        	 break;
      	}

        if (k == 4) { break; }
   }
   return 0;
}
