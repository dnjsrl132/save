#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
FILE *f1, *f2;

typedef struct polyNode *polyPointer;
typedef struct polyNode{
   int coef;
   int expon;
   polyPointer link;
}polyNode;
polyPointer a,b;

void attach(int coefficient, int exponent, polyPointer *ptr);
polyPointer asumb(polyPointer a, polyPointer b);

int main(void){
   f1 = fopen("input_0420.txt", "r");
   f2 = fopen("output18.txt", "w");
   
   polyPointer head1=(polyPointer)malloc(sizeof(polyPointer));
   polyPointer a;
   polyPointer temp1;
   int num1;
   fscanf(f1, "%d", &num1);
   a=head1;
   for (int i=0; i<num1; i++){
      temp1 = (polyPointer)malloc(sizeof(polyPointer));
      fscanf(f1, "%d %d", &temp1->coef, &temp1->expon);
      temp1->link=NULL;
      a->link=temp1;
      a = a->link;
   }
   
   polyPointer head2=(polyPointer)malloc(sizeof(polyPointer));
   polyPointer b ;
   polyPointer temp2;
   int num2;
   fscanf(f1, "%d", &num2);
   b=head2;
   for (int i=0; i<num2; i++){
      temp2 = (polyPointer)malloc(sizeof(polyPointer));
      fscanf(f1, "%d %d", &temp2->coef, &temp2->expon);
      temp2->link=NULL;
      b->link=temp2;
      b = b->link;
   }
   polyPointer c;
   c=asumb(head1, head2)->link;
   printf("print\n");
   while(c!=NULL){
   	printf("%d %d\n",c->coef,c->expon);
   	c=c->link;
   }
   
   free(a);
   free(b);
   free(c);
   free(temp1);
   free(temp2);
   free(head1);
   free(head2);
   fclose(f1);
   fclose(f2);
   return 0;
}

polyPointer asumb(polyPointer a, polyPointer b){
   polyPointer c, head, temp;
   int sum;
   head = (polyPointer)malloc(sizeof(*head));
   c = head;
   
   while (a!=NULL || b!=NULL){
      temp = (polyPointer)malloc(sizeof(polyPointer));
      if(a->expon < b->expon){
         attach(b->coef, b->expon, &temp);
         c->link = temp;
         b = b->link;
         c = c->link;
      }
      else if(a->expon == b->expon){
         sum = a->coef + b->coef;
         if (sum){
            attach(sum, b->expon, &temp);
            c->link = temp;
            c = c->link;
         }
         a = a->link;
         b = b->link;
      }
      else if(a->expon > b->expon){
         attach(a->coef, a->expon, &temp);
         c->link = temp;
         a = a->link;
         c = c->link;
      }
   }
   c->link=NULL;
   
   return head;
}

void attach(int coefficient, int exponent, polyPointer *ptr){
   polyPointer temp = (polyPointer)malloc(sizeof(*temp));
   temp->coef = coefficient;
   temp->expon = exponent;
   (*ptr)->link = temp;
   *ptr = temp;
}
