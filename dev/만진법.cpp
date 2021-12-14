#include <stdio.h>
#include <string.h>
#define MAX 1000

// 0번째 칸에는 자리수를 저장합니다. 만진법을 사용합니다.
// 1번째 칸에는 일의 자리, 2번째 칸에는 만의 자리, 3번째 칸에는 억의 자리
// ... 등을 저장합니다. 최대 3996자리까지 출력이 가능합니다.

void printResult(int []);

void copy(int a[], int b[]) {
    int i, n=a[0];
    
    for(i=0;i<MAX;i+=1) { b[i]=a[i]; }
}

void clear(int a[]) {
    int i;
    
    for(i=0;i<MAX;i+=1) { a[i]=0; }
    
    a[0]=1;
}

int compare(int a[], int b[]) {
    int i=a[0];
    
    if(a[0]<b[0]) { return -1; }
    if(a[0]>b[0]) { return 1; }
    
    while(i>0) {
        if(a[i]<b[i]) { return -1;  }
        if(a[i]>b[i]) { return 1; }
        i-=1;
    }

    return 0;
}

void add(int a[], int b[], int r[]) {

    int i, j, x=0;

    clear(r);
/*
    r[0]=a[0];

    if(b[0]>r[0]) { r[0]=b[0]; }
*/
	r[0]=b[0]>a[0]?b[0]:a[0];
    for(i=1;i<=r[0];i+=1) {       // 수의 각 자리와 밑에서 올라온 수를
        x+=a[i]+b[i];             // 더해줍니다.
        r[i]=x%10000;             // 값이 9999보다 크면 제자리의 수만 남고
        x/=10000;                // 윗자리로 올라갑니다.
    }
	
    if(x!=0) { 
        r[0]+=1;
        r[r[0]]=x;
    } 

}

void sub(int a[], int b[], int r[]) {

    int i, j, x=0;
    
    clear(r);

    r[0]=a[0];

    if(b[0]>r[0]) { r[0]=b[0]; }


    for(i=1;i<=r[0];i+=1) { // 수의 각 자리로

        x=a[i]-b[i]+x;      // 결과에 더해줍니다.

        if(x<0) {

            r[i]=x+10000;

            x=-1;

        } else {

            r[i]=x;

            x=0;

        }

    }




    if(x!=0) { 

        for(i=0;i<a[0]+1;i+=1) { printf("%d ", a[i]); } printf("\n");

        for(i=0;i<b[0]+1;i+=1) { printf("%d ", b[i]); } printf("\n");




        printf("*****************ERROR*************\n");

        getchar(); getchar();

    } 

    i=r[0];

    while(r[i]==0) { i-=1; }

    if(i==0) { i=1; }

    r[0]=i;

    //for(i=0;i<10;i+=1) { printf("%d ", r[i]); } printf("\n");

}

void mul(int a[], int b[], int r[]) {

    int i, j, x;

    clear(r);

    for(i=1;i<=b[0];i+=1) {         // 승수의 각 자리로

        for(j=1;j<=a[0];j+=1) {     // 피승수의 각자리를 곱합니다.

            r[i+j-1]+=b[i]*a[j];    // 결과에 더해줍니다.

            x=r[i+j-1];             // 값이 9999보다 크면 윗자리로 올라갑니다.

            r[i+j-1]=x%10000;       // 제자리의 수만 남고

            r[i+j] +=x/10000;       // 윗자리로 올라갑니다.

        }

    }

    r[0]=a[0]+b[0];   // 결과의 자리수를 구합니다.

    if(r[r[0]]==0) { r[0]-=1; }

}

void div(int a[], int b[], int q[], int r[]) {

    int v1[MAX]={1,};

    int v2[MAX]={1,};

    int one[MAX]={1,1,};

    int two[MAX]={1,};

    int i, j, x, e1, e2, ex;

    double d1, d2, dd;




    copy(a, r); // 피제수를 나머지에 복사한다. 

                // 당분간 나머지가 임시로 남아있는 피제수 노릇을 한다.




    d2=0;       // 제수의 근사값을 d2와 e2로 나타낸다.

    i=b[0];

    j=0;

    while(i>0 && j<4) {

        d2=10000*d2+b[i];

        i-=1; 

        j+=1;

    }

    e2=i;

 

    // 남아있는 피제수가 제수보다 클 동안 계속한다.

    while(compare(r, b)>=0) { 

        // 피제수의 근사값을 d1과 e1으로 나타낸다. 

        d1=0;                 

        i=r[0];

        j=0;

        while(i>0 && j<4) {

            d1=10000*d1+r[i];

            i-=1; 

            j+=1;

        }    

        e1=i;




        // 임시 몫의 근사값을 dd와 ex로 나타낸다

        dd=d1/d2;            




        while(dd>10000) { dd/=10000; e1+=1; }




        ex=e1-e2+1; 




        clear(v1);

        // 임시 몫은 v1이다. dd와 ex로 부터 v1을 구한다.

        v1[0]=ex;            

        i=0;

        while(ex>0&&i<3) {

            x=dd; dd-=x; dd*=10000; v1[ex]=x; ex-=1; i+=1;

        }




        // v1이 클 경우 빼주는 값을 one이라한다.

        clear(one);          

        one[ex+1]=1;

        one[0]=ex+1;




        // v1의 아래 자리는 모두 0으로 채운다. 

        if(i==0) {           

            while(ex>0) { 

                v1[ex]=0; ex-=1; 

            } 

        }




        // 임시몫 v1이 너무 크다면 줄여준다.

        while(1) {

            // 임시 몫 v1과 제수를 곱한 결과를 v2라 한다.

            mul(v1, b, v2);

            // 임시 피제수가 v2보다 크다면 정상적으로 진행한다.

            if(compare(r,v2)>=0) { break; }

            // 만약 임시 피제수보다 v2가 크다면 위에서 구한 임시 몫 v1이 과도하게 크다.

            // v1에서 one을 빼준다.

            sub(v1, one, two);

            copy(two, v1);

        } 

        // 임시 피제수에서 v2를 뺀 결과를 임시 피제수로 한다.

        sub(r, v2, two);

        copy(two, r);

        // q에 v1을 더한 결과를 q로 한다.

        add(q, v1, two);

        copy(two, q);

    }   

    // q의 가장 큰 자리가 0일 경우는 1 자리를 줄여준다.

    while(q[q[0]]==0) { q[0]-=1; }

    if(q[0]<1) { q[0]=1; }

    // r에는 나머지가 남아 있게 된다.

}

// 출력은 다시 큰 수 부터 출력해 준다.

void printResult(int result[]) {

    int i, x;

    x=result[0];

    printf("%d", result[x]);

    for(i=1;i<x;i+=1) {

        printf("%04d", result[x-i]);

    }

    printf("\n");

}

void convert(char a[], int b[]) {

    int i, j, k, x;

    

    i=strlen(a)-1;

    x=0;

    j=1;

    k=1;

    while(i>=0) {

        x+=k*(a[i]-'0');

        k*=10;

        i-=1;

        if(k==10000) {

            k=1;

            b[j]=x;

            j+=1;

            x=0;

        }

    }

    if(k>1) {

        b[j]=x;

        j+=1;

    }

    b[0]=j-1;

}

int main() {

    int a[MAX]={1,};  // 피제수

    int b[MAX]={1,};  // 제수

    int q[MAX]={1,};  // 몫

    int r[MAX]={1,};  // 나머지

    char m1[MAX];

    char m2[MAX];

    int i, x, z;




    while(1) {

        printf("1.덧셈 2.뺄셈 3.곱셈 4.나눗셈 0.마침 ");

        i=scanf("%d", &z);

        if(i<1) { 

            fflush(stdin);

            continue;

        }

        if(z==0) { 

            break; 

        } 

        printf("입력1: ");

        scanf("%s", m1);

        printf("입력2: ");

        scanf("%s", m2);




        // 입력된 수를 뒤집어 준다.

        convert(m1, a);

        convert(m2, b);




        if (z==1) {

            add(a, b, r);

        } else if(z==2) {

            sub(a, b, r);

        } else if(z==3) {

            mul(a, b, r);

        } else if(z==4) {

            clear(q);

            clear(r);

            div(a, b, q, r);

            printf("dividend= ");

            printResult(a);

            printf("divider = ");

            printResult(b);

            printf("몫      = ");

            printResult(q);

            printf("나머지  = ");

            printResult(r);

        }

        // 결과를 출력해 준다.

        if(z<4) printResult(r);

    }




    return 0;

}

