#include <stdio.h>
#include <stdlib.h>

typedef struct node //for list
{
    int data;
    struct node *next;
}Node;
Node *head = NULL; // list top

typedef struct stackNode //for stack
{
    Node* data;
    struct stackNode* next;
} StackNode;
StackNode *top = NULL; // stack top

//For stack function
void Push(Node *ptr)
{
    StackNode *temp = malloc(sizeof(Node));
    temp->data = ptr;
    temp->next = top;
    top = temp;
}

void Pop()
{
    StackNode *temp = top;
    if(top == NULL)
    {
        return;
    }
    top = top->next;
    free(temp);
}

Node *Top()
{
    return top->data;
}

int IsEmpty()
{
    return top == NULL;
}

//Reverse and Print
void Reverse()
{
    if(head == NULL) return;

    Node* temp = head;
    while(temp != NULL)
    {
        Push(temp);
        temp = temp->next;
    }
    temp = Top();
    head = temp;

    while(!IsEmpty())
    {
        temp->next = Top();
        Pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

void Print()
{
    Node* temp = head;
    printf("Linked List: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    // create linked list
    for(int i = 4; i >= 1; i--)
    {
        Node* temp = malloc(sizeof(Node));

        temp->data = i;
        temp->next = head;

        head = temp;
    }
    Print();

    Reverse();
    printf("Reverse ");
    Print();
    
    return 0;
}