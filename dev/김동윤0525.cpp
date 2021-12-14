#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX_SIZE 10
FILE *f1, *f2;

typedef struct Tree_Node{
   int data;
}array;

typedef struct node *nodePointer;
typedef struct node{
   int main_number;
   array bridge[MAX_SIZE];
   nodePointer next;
}node;

void Add_Tree(nodePointer *phead, nodePointer *ptail, int data);

int main(void){
   f1 = fopen("±èµ¿À±0525.txt", "r");
   f2 = fopen("output35.txt", "w");
   
   int n, m;
   nodePointer head1=(nodePointer)malloc(sizeof(node));
   nodePointer a;
   nodePointer temp1;
   a = head1;
   
   fscanf(f1, "%d %d", &n, &m);
   //printf("%d %d\n",n,m);
   
   for (int i=0; i<n; i++){
      temp1 = (nodePointer)malloc(sizeof(node));
      temp1->main_number = i;
      temp1->next=NULL;
      for (int j=0; j<n; j++){
         temp1->bridge[j].data=0;
      }
      a->next=temp1;
      a = a->next;
   }
   
   int b, c;
   nodePointer temp = head1;
   for (int i=0; i<m; i++){
   		temp=head1->next;
      fscanf(f1, "%d %d", &b, &c);
      //printf("%d %d %d\n",b,c,temp->main_number);
      if (b==0){
         temp->bridge[c].data = 1;
      }
      else {
         nodePointer seek = temp;
         for (int j=0; j<b; j++){
            seek = seek->next;
         }
         seek->bridge[c].data = 1;
         temp = seek;
      }
      //printf("%d %d %d\n",b,c,temp->main_number);
      if (c==0){
         temp->bridge[b].data = 1;
      }
      else {
         nodePointer seek = temp;
         for (int j=b; j<c; j++){
            seek = seek->next;
         }
         seek->bridge[b].data = 1;
         temp=seek;
      }
      //printf("%d %d %d\n",b,c,temp->main_number);
   }
   
   nodePointer d = head1->next;
   while (d != NULL){
      for (int i=0; i<n; i++){
         if (d->bridge[i].data == 1){
            fprintf(f2,"%d ", i);
         }
      }
      fprintf(f2,"\n");
      d = d->next;
   }
   
   fclose(f1);
   fclose(f2);
   return 0;
}
