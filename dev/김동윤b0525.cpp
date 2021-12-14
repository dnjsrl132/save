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

int cnt=0;
void dfs(nodePointer d, int n, int a);
int visit[MAX_SIZE];  //출력을 했으면 1, 안했으면 0 

int main(void){
   f1 = fopen("김동윤0525.txt", "r");
   f2 = fopen("output30.txt", "w");
   
   int n, m;
   fscanf(f1, "%d %d", &n, &m);
   //printf("%d %d\n",n,m);
   nodePointer head1 = (nodePointer)malloc(sizeof(node));
   nodePointer a;
   nodePointer temp1;
   a = head1;
   
   for (int i=0; i<n; i++){
      visit[i] = 0;
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
      temp = head1->next;
      fscanf(f1, "%d %d", &b, &c);
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
      
      if (c==0){
         temp->bridge[b].data = 1;
      }
      else {
         nodePointer seek = temp;
         for (int j=b; j<c; j++){
            seek = seek->next;
         }
         seek->bridge[b].data = 1;
         temp = seek;
      }
   }
   
   nodePointer d = head1->next;
   dfs(d, n, 0);
   
   fclose(f1);
   fclose(f2);
   return 0;
}

void dfs(nodePointer d, int n, int a){
   int i;
   while (cnt<n){
      for (i=a; i<n; i++){

         if (d->bridge[i].data == 1){
         	if(visit[d->main_number] == 0){
         		printf("%d ", d->main_number,i);
            	fprintf(f2, "%d ", d->main_number);
			 }
            cnt++;
            visit[d->main_number]++;
            
            if (visit[i] == 0){
               nodePointer temp = d;
               //int b = a + i - d->main_number;
               for (int j=a; j<i; j++){
                  temp = temp->next;
               }
               dfs(temp, n, i);
            }
         }
         if (i==n-1){
         	if(!visit[d->main_number]){
         		printf("%d ",d->main_number);
         		fprintf(f2,"%d ",d->main_number);
         		visit[d->main_number]++;
         	}
            return;
         }
         
      }
   }
}
