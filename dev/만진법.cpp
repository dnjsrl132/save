#include <stdio.h>
#include <string.h>
#define MAX 1000

// 0��° ĭ���� �ڸ����� �����մϴ�. �������� ����մϴ�.
// 1��° ĭ���� ���� �ڸ�, 2��° ĭ���� ���� �ڸ�, 3��° ĭ���� ���� �ڸ�
// ... ���� �����մϴ�. �ִ� 3996�ڸ����� ����� �����մϴ�.

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
    for(i=1;i<=r[0];i+=1) {       // ���� �� �ڸ��� �ؿ��� �ö�� ����
        x+=a[i]+b[i];             // �����ݴϴ�.
        r[i]=x%10000;             // ���� 9999���� ũ�� ���ڸ��� ���� ����
        x/=10000;                // ���ڸ��� �ö󰩴ϴ�.
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


    for(i=1;i<=r[0];i+=1) { // ���� �� �ڸ���

        x=a[i]-b[i]+x;      // ����� �����ݴϴ�.

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

    for(i=1;i<=b[0];i+=1) {         // �¼��� �� �ڸ���

        for(j=1;j<=a[0];j+=1) {     // �ǽ¼��� ���ڸ��� ���մϴ�.

            r[i+j-1]+=b[i]*a[j];    // ����� �����ݴϴ�.

            x=r[i+j-1];             // ���� 9999���� ũ�� ���ڸ��� �ö󰩴ϴ�.

            r[i+j-1]=x%10000;       // ���ڸ��� ���� ����

            r[i+j] +=x/10000;       // ���ڸ��� �ö󰩴ϴ�.

        }

    }

    r[0]=a[0]+b[0];   // ����� �ڸ����� ���մϴ�.

    if(r[r[0]]==0) { r[0]-=1; }

}

void div(int a[], int b[], int q[], int r[]) {

    int v1[MAX]={1,};

    int v2[MAX]={1,};

    int one[MAX]={1,1,};

    int two[MAX]={1,};

    int i, j, x, e1, e2, ex;

    double d1, d2, dd;




    copy(a, r); // �������� �������� �����Ѵ�. 

                // ��а� �������� �ӽ÷� �����ִ� ������ �븩�� �Ѵ�.




    d2=0;       // ������ �ٻ簪�� d2�� e2�� ��Ÿ����.

    i=b[0];

    j=0;

    while(i>0 && j<4) {

        d2=10000*d2+b[i];

        i-=1; 

        j+=1;

    }

    e2=i;

 

    // �����ִ� �������� �������� Ŭ ���� ����Ѵ�.

    while(compare(r, b)>=0) { 

        // �������� �ٻ簪�� d1�� e1���� ��Ÿ����. 

        d1=0;                 

        i=r[0];

        j=0;

        while(i>0 && j<4) {

            d1=10000*d1+r[i];

            i-=1; 

            j+=1;

        }    

        e1=i;




        // �ӽ� ���� �ٻ簪�� dd�� ex�� ��Ÿ����

        dd=d1/d2;            




        while(dd>10000) { dd/=10000; e1+=1; }




        ex=e1-e2+1; 




        clear(v1);

        // �ӽ� ���� v1�̴�. dd�� ex�� ���� v1�� ���Ѵ�.

        v1[0]=ex;            

        i=0;

        while(ex>0&&i<3) {

            x=dd; dd-=x; dd*=10000; v1[ex]=x; ex-=1; i+=1;

        }




        // v1�� Ŭ ��� ���ִ� ���� one�̶��Ѵ�.

        clear(one);          

        one[ex+1]=1;

        one[0]=ex+1;




        // v1�� �Ʒ� �ڸ��� ��� 0���� ä���. 

        if(i==0) {           

            while(ex>0) { 

                v1[ex]=0; ex-=1; 

            } 

        }




        // �ӽø� v1�� �ʹ� ũ�ٸ� �ٿ��ش�.

        while(1) {

            // �ӽ� �� v1�� ������ ���� ����� v2�� �Ѵ�.

            mul(v1, b, v2);

            // �ӽ� �������� v2���� ũ�ٸ� ���������� �����Ѵ�.

            if(compare(r,v2)>=0) { break; }

            // ���� �ӽ� ���������� v2�� ũ�ٸ� ������ ���� �ӽ� �� v1�� �����ϰ� ũ��.

            // v1���� one�� ���ش�.

            sub(v1, one, two);

            copy(two, v1);

        } 

        // �ӽ� ���������� v2�� �� ����� �ӽ� �������� �Ѵ�.

        sub(r, v2, two);

        copy(two, r);

        // q�� v1�� ���� ����� q�� �Ѵ�.

        add(q, v1, two);

        copy(two, q);

    }   

    // q�� ���� ū �ڸ��� 0�� ���� 1 �ڸ��� �ٿ��ش�.

    while(q[q[0]]==0) { q[0]-=1; }

    if(q[0]<1) { q[0]=1; }

    // r���� �������� ���� �ְ� �ȴ�.

}

// ����� �ٽ� ū �� ���� ����� �ش�.

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

    int a[MAX]={1,};  // ������

    int b[MAX]={1,};  // ����

    int q[MAX]={1,};  // ��

    int r[MAX]={1,};  // ������

    char m1[MAX];

    char m2[MAX];

    int i, x, z;




    while(1) {

        printf("1.���� 2.���� 3.���� 4.������ 0.��ħ ");

        i=scanf("%d", &z);

        if(i<1) { 

            fflush(stdin);

            continue;

        }

        if(z==0) { 

            break; 

        } 

        printf("�Է�1: ");

        scanf("%s", m1);

        printf("�Է�2: ");

        scanf("%s", m2);




        // �Էµ� ���� ������ �ش�.

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

            printf("��      = ");

            printResult(q);

            printf("������  = ");

            printResult(r);

        }

        // ����� ����� �ش�.

        if(z<4) printResult(r);

    }




    return 0;

}

