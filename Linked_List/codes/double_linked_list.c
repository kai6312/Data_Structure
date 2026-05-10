#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Node;
Node *head;

Node *GetNewNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void InsertAtHead(int data)
{
    Node *newNode = GetNewNode(data);
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int data)
{
    Node *newNode = GetNewNode(data);
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

void Print()
{
    Node* temp = head;
    printf("Forward: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint()
{
    Node* temp = head;
    if(temp == NULL) return;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Reverse: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    printf("InsertAtHead\n");
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtHead(7); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(8); Print(); ReversePrint();//8, 4, 7, 2
    
    printf("\nInsertAtTail\n");
    InsertAtTail(1); Print(); ReversePrint();
    InsertAtTail(3); Print(); ReversePrint();
    InsertAtTail(5); Print(); ReversePrint();
    InsertAtTail(7); Print(); ReversePrint();//8, 4, 7, 2, 1, 3, 5, 7, 
    return 0;
}