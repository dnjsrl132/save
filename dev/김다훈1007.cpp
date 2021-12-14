#include<stdio.h>

int main(){
   int cnt;
   char *arr[7] = {"SUN","MON", "TUE", "WED", "THU", "FRI", "SAT"};
   int x,y,max;
   cnt = 0;
   scanf("%d %d",&x,&y);
   for(int i=1; i<=x;i++){
      if(i==4&&i==6&&i==9&&i==11){
      max = 30;
      }else if(i==2){
         max = 28;
      }else{
         max = 31;
      }
      for(int k=1; k<=max;k++){
         cnt++;
         if(y==k&&x==i){
         	printf("%s",arr[cnt]);
            break;
         }
         
         if(cnt>6){
            cnt=0;
         }
      }
   }
   
   
}
