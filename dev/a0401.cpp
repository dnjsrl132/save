#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *f1, *f2;
typedef struct{
   int gyesu;
   int jisu;
} polynomial;

int main(void){
   f1 = fopen("a0401.txt", "r");
   f2 = fopen("output7.txt", "w");
   
   int n,m;
   int temp1, temp2;
   fscanf(f1, "%d", &n);
   
   polynomial *p1 = (polynomial*)malloc(sizeof(polynomial)*102);
   for (int i=0; i<=n+1; i++){
      p1[i].gyesu=0;
      p1[i].jisu=i;
   }
   polynomial *p11 = (polynomial*)malloc(sizeof(polynomial)*4);
   for (int i=0; i<4; i++)
      fscanf(f1, "%d %d", &p11[i].gyesu,  &p11[i].jisu);
   
   int j=101, k=0;
   while(j>=0){
      if (p11[k].jisu == j){
         p1[j].gyesu = p11[k].gyesu;
         k++;
      }
      else
         j--;
   }
//   for (int i=100; i>=0; i--)
//      printf("%d %d\n   ", p1[i].gyesu, p1[i].jisu);
   //다항식A 
   
   
   
   fscanf(f1, "%d", &m);
   polynomial *p2 = (polynomial*)malloc(sizeof(polynomial)*102);
   for (int i=0; i<=m+1; i++){
      p2[i].gyesu=0;
      p2[i].jisu=i;
   }
   polynomial *p22 = (polynomial*)malloc(sizeof(polynomial)*5);
   for (int i=0; i<5; i++)
      fscanf(f1, "%d %d", &p22[i].gyesu,  &p22[i].jisu);
   
   j=101, k=0;
   while(j>=0){
      if (p22[k].jisu == j){
         p2[j].gyesu = p22[k].gyesu;
         k++;
      }
      else
         j--;
   }
//   for (int i=100; i>=0; i--)
//      printf("%d %d\n   ", p2[i].gyesu, p2[i].jisu);
   //다항식B  
   
   for (int i=100; i>=0; i--){
   	if(p1[i].gyesu+p2[i].gyesu)
      printf("%d %d\n", p1[i].gyesu+p2[i].gyesu, p1[i].jisu);
  }
   
   
   fclose(f1);
   fclose(f2);
   return 0;
}
