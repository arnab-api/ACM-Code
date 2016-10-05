#include<bits/stdc++.h>
using namespace std;
#define oo INT_MAX

struct Queue{
    int ara[1000],st=0,nd=0;
    int Front();
    int Rear();
    void push(int x);
    void pop();
    int Size();
    void display();
};

int Queue :: Front()
{
    if(nd-st>0) return ara[st];
    else{
        printf("Queue is epmpty\n");
        return -oo;
    }
}

int Queue :: Rear()
{
    if(nd-st>0) return ara[nd-1];
    else{
        printf("Queue is epmpty\n");
        return -oo;
    }
}

void Queue :: push(int x)
{
    nd++;
    ara[nd-1]=x;
}

void Queue :: pop()
{
    if(nd-st>0) st++;
    else{
        printf("Queue is already empty\n");
        return;
    }
}

int Queue :: Size()
{
    return nd-st;
}

void Queue :: display()
{
    if(nd-st>0) for(int i=st;i<nd;i++) printf("%d ",ara[i]);
    else printf("Queue is empty");
    printf("\n");
}

int main()
{
    Queue Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(11);
    Q.push(22);
    Q.push(33);
    Q.push(44);
    Q.display();
    while(Q.Size()!=0){
        printf("%d\n",Q.Front());
        printf("%d\n",Q.Rear());
        printf("-->");
        Q.display();
        Q.pop();
    }
    Q.pop();
    Q.display();
    return 0;
}

