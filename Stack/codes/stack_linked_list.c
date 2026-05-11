#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *top;

void Push(int x)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void Pop()
{
    Node *temp = top;
    if(top == NULL)
    {
        return;
    }
    top = top->next;
    free(temp);
}

void Top()
{
    printf("Top: %d", top->data);
}

void Print()
{
    Node* temp = top;
    printf("Stack: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    top = NULL;
    Push(2); Print();
    Push(5); Print();
    Push(10); Print();
    Pop(); Print();
    Push(2); Print();
    Top();
    
    return 0;
}