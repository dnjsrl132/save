#include<stdio.h>
int main(){
    int t;
    int a,b;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d %d",&a,&b);
        printf("%d %d\n",2*b-a,a-b);
    }
    return 0;
}
