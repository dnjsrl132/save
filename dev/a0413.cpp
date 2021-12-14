#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 100
FILE *f1, *f2;
int j=1;
typedef struct queue{
   int *queue;
   int rear;
   int front;
} queue;

int full(queue *q);
void push(queue *q, int value);
int empty(queue *q);
int pop(queue *q);
int size(queue *q);
int front1(queue *q);
int back(queue *q);

int main(void){
   f1 = fopen("input_a0413.txt", "r");
   f2 = fopen("output_a0413.txt", "w");
   int num;
   fscanf(f1, "%d", &num);
   char str[num][10];
   int x;
   
   queue q;
   q.queue = (int*)malloc(sizeof(int)*j);
   q.front=-1;
   q.rear=-1;
   
   for (int i=0; i<num; i++){
      fscanf(f1, "%s", str[i]);
      if (!strcmp("push", str[i])){
         fscanf(f1, "%d", &x);
         push(&q, x);
      }
      else if (!strcmp("pop", str[i])){
         pop(&q);
      }
      else if (!strcmp("size", str[i])){
         size(&q);
      }
      else if (!strcmp("empty", str[i])){
         if (empty(&q) == true){
            printf("1\n");
            fprintf(f2, "1\n");
         }
         else{
            printf("0\n");
            fprintf(f2, "0\n");
         }
      }
      else if (!strcmp("front", str[i])){
         front1(&q);
      }
      else if (!strcmp("back", str[i])){
         back(&q);
      }
   }
   
   fclose(f1);
   fclose(f2);
   return 0;
}

int full(queue *q){ //했음 
   int tmp = (q->rear+1)%j;
   if(tmp==q->front)
        return true;
    else
        return false;
}

void push(queue *q, int value){ //했음 
   if(full(q)==true){
      j*=2;
      q->queue[(q->rear)++]=value;
   }   
    else{
       q->queue[q->rear++]=value;
   }
}

int pop(queue *q){ // 
   if(empty(q)==true){
        printf("-1\n");
        fprintf(f2, "-1\n");
    }
    else{
       printf("%d\n", q->queue[q->front]);
       fprintf(f2, "%d\n", q->queue[q->front++]);
   }
}

int size(queue *q){ //했음 
   printf("%d\n", q->rear-q->front);
   fprintf(f2, "%d\n", q->rear-q->front);
}

int empty(queue *q){ //했음 
   if(q->front==q->rear)
        return true;
    else
        return false;
}

int front1(queue *q){ //했음 
   if(empty(q)==true){
        printf("-1\n");
        fprintf(f2, "-1\n");
    }
    else{
       printf("%d\n", q->queue[q->front]);
       fprintf(f2, "%d\n", q->queue[q->front]);
   }
}

int back(queue *q){ //했음 
   if(empty(q)==true){
        printf("-1\n");
        fprintf(f2, "-1\n");
    }
    else{
       printf("%d\n", q->queue[q->rear-1]);
       fprintf(f2, "%d\n", q->queue[q->rear-1]);
   }
}
