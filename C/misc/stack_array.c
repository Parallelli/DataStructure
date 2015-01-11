#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stack
{
    int *ptr;
    int sz;
    int offset;
}stack;

void init(stack *stk)
{
    stk->ptr = (int*)malloc(sizeof(int));
    stk->sz = 1;
    stk->offset = 0;
}

void push(stack *stk, int item)
{
    if(stk->offset >= stk->sz)
    {
        int newSZ = stk->sz << 1;
        stk->ptr = (int*)realloc(stk->ptr, newSZ);
        stk->sz = newSZ;
    }
    *(stk->ptr + stk->offset) = item;
    stk->offset ++;
}

void pop(stack *stk)
{
    if(stk->offset > 0)
    {
        stk->offset--;
    }
}

int top(stack *stk)
{
    if(stk->offset >= 1)
    {
        return *(stk->ptr + stk->offset - 1);
    }
    return -1;//NA
}

int empty(stack *stk)
{
    if(stk->offset==0)
        return 1;
    return 0;
}

int main()
{
    stack s;
    printf("%lu\n", sizeof(s));
    init(&s);
    for(int i = 1; i <= 5; i++)
        push(&s,i);
    while(!empty(&s))
    {
        int t = top(&s);
        printf("%d ", t);
        pop(&s);
    }
    printf("\n");
    return 0;
}
