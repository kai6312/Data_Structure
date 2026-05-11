#include <stdio.h>
#define Max_Size 101

int A[Max_Size];
int top = -1;

void Push(int x)
{
    if(top == Max_Size -1 )
    {
        printf("Error: Stack Overflow\n");
        return;
    }
    top ++;
    A[top] = x; //same as A[++Top] = x
}

void Pop()
{
    if(top == -1 )
    {
        printf("Error: No element to pop\n");
        return;
    }
    top --;
}

int Top()
{
    return A[top];
}

void Print()
{
    int i;
    printf("Stack: ");
    for(i = 0;i <= top;i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    Push(2); Print();
    Push(5); Print();
    Push(10); Print();
    Pop(); Print();
    Push(2); Print();

    return 0;
}