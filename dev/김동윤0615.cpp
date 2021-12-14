#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MAX_SIZE 10
FILE *f1, *f2;

typedef struct element *elementPointer;
typedef struct element {
   char name[100];
   int korean;
   int math;
   int english;
   elementPointer next;
}element;

elementPointer hash_table;
elementPointer input;
int arr[MAX_SIZE];

unsigned int stringToInt(char str[]);
void insert_hash_table(element input, int b);
void find(char s[], int b);

int main(void){
   f1 = fopen("input±èµ¿À±0615.txt", "r");
   f2 = fopen("output±èµ¿À±0615.txt", "w");
   
   int b, n;
   fscanf(f1, "%d %d", &b, &n);
   hash_table = (elementPointer)malloc(sizeof(element) * b);
   input = (elementPointer)malloc(sizeof(element) * n);
   
   for (int i=0; i<b; i++){
      hash_table[i].name[0] = '\0';
      hash_table[i].next = NULL;
      arr[i] = 0;
   }
   for (int i=0; i<n; i++){
      fscanf(f1, "%s %d %d %d", input[i].name, &input[i].korean, &input[i].math, &input[i].english);
      printf("i : %d, ", i);
      insert_hash_table(input[i], b);
   }
   
   int m;
   fscanf(f1, "%d", &m);
   char s[m][20];
   for (int i=0; i<m; i++){
      printf("Ãâ·Â i : %d,   ", i); 
      fscanf(f1, "%s", s[i]);
      find(s[i], b);
   }
   
   fclose(f1);
   fclose(f2);
   return 0;
}

void find(char s[], int b){
   int index = stringToInt(s)%b;
   int i=0;
   elementPointer temp;//= (elementPointer)malloc(sizeof(element));
   
   temp = &hash_table[index];
   printf("%s %s %d\n",s,temp->name,index);
   
   while(temp != NULL){
      if (!strcmp(s, temp->name)){
         printf("%s %d %d %d\n", temp->name, temp->korean, temp->math, temp->english);
         fprintf(f2, "%s %d %d %d\n", temp->name, temp->korean, temp->math, temp->english);
         break;
      }
      else{
         temp = temp->next;
      }
      i++;
   }
   if (i == b){
      printf("¾øÀ½\n");
      fprintf(f2, "¾øÀ½\n");
   }
}

unsigned int stringToInt(char str[]){
   int number = 0, i = 0;
   while (str[i])
      number += str[i++];
   return number;
}

void insert_hash_table(element input, int b){
   int index = stringToInt(input.name)%b;
   printf("index : %d\n", index);
   
   if (hash_table[index].name[0] == '\0'){
      hash_table[index].english = input.english;
      hash_table[index].korean = input.korean;
      hash_table[index].math = input.math;
      hash_table[index].next = NULL;
      strcpy(hash_table[index].name, input.name);
      arr[index]++;
   }
   
   else{
      elementPointer temp = (elementPointer)malloc(sizeof(element));
      temp->english = input.english;
      temp->korean = input.korean;
      temp->math = input.math;
      temp->next = NULL;
      strcpy(temp->name, input.name);
      hash_table[index].next = temp;
      arr[index]++;
   }
}
