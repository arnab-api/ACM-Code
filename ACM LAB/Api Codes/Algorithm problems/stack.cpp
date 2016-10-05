#include<bits/stdc++.h>
using namespace std;
#define oo INT_MAX

struct Stack{
    int ara[1000],sizee=0;
    int top();
    void push(int x);
    void pop();
    int Size();
    void display();
};

int Stack :: top()
{
    if(sizee) return ara[sizee-1];
    else{
        printf("Stack is epmpty\n");
        return -oo;
    }
}

void Stack :: push(int x)
{
    sizee++;
    ara[sizee-1]=x;
}

void Stack :: pop()
{
    if(sizee) sizee--;
    else{
        printf("Stack is already epmpty\n");
        return;
    }
}

int Stack :: Size()
{
    return sizee;
}

void Stack :: display()
{
    for(int i=0;i<sizee;i++) printf("%d ",ara[i]);
    printf("\n");
}

int main()
{
    Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.display();
    while(stk.Size()!=0){
        printf("%d\n",stk.top());
        stk.pop();
    }
    return 0;
}


