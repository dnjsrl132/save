#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>
FILE *f1, *f2;

typedef struct listNode *listPointer;
typedef struct listNode {
    char* data;
    int tdat;
    listPointer link;
} listNode;

listPointer ptr1 = NULL;
listPointer ptr2 = NULL;
listPointer ptr[2];

listPointer concatenate(listPointer ptr1, listPointer ptr2){
   listPointer head=ptr1;
   listPointer temp=head->link;
   while(temp!=NULL){
   		if(temp->data=="\n") break;
   		temp=temp->link;
   }
   temp=ptr2->link;
   
   return head;
}


int main(void){
   f1 = fopen("±èµ¿À±0420.txt", "r");
   f2 = fopen("output15.txt", "w");
   int num, j=0, len=0;
   char s[2][50];
   
   	  		listPointer temp;
   	fgets(s[0],50,f1);
   	fgets(s[1],50,f1);
   	for(int i=0;i<2;i++){
   		listPointer head=(listPointer)malloc(sizeof(listPointer));
  		listPointer tail;

   		tail=head;
   		fprintf(f2, "ptr%d : ",i+1);
   		printf("ptr%d  : ",i+1);
		char *ptr11 = strtok(s[i], " ");
    	while (ptr11 != NULL){
    		temp = (listPointer)malloc(sizeof(listPointer));
    		printf("%s ", ptr11);
   		 	fprintf(f2, "%s ", ptr11);
    	  	temp->data = ptr11;
    	  	temp->link=NULL;
    	  	tail->link = temp;
    	  	tail=tail->link;
    	  	ptr11 = strtok(NULL, " ");
   		}
   		fprintf(f2, "\n");
   		printf("\n");
   		ptr[i]=head->link;
   	}
	   temp=concatenate(ptr[0], ptr[1]);
   	for(int i=0;i<2;i++){
   		temp=ptr[i];
   		while(temp!=NULL){
   			printf("%s  ",temp->data);
   			temp=temp->link;
		   }
	   }
   
   fclose(f1);
   fclose(f2);
   return 0;
}
