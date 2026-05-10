//Linled List//
//Reverse a linked list by recursiving//

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;
Node* head; 

void Insert(int data)
{
    Node* temp1 = (Node*)malloc(sizeof(Node));
    Node* temp2 = head;
    temp1->data = data;
    temp1->next = NULL;
    
    if(temp2 == NULL)
    {
        head = temp1;
        return;
    }
    
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

void Print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Reverse(Node *p)
{
    if(p->next == NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    p->next->next = p;
    p->next = NULL;
}

int main()
{
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(5);
    Insert(8); //2, 4, 5, 8
    printf("Linked list is ");
    Print();
    
    Reverse(head);
    printf("Reverse linked list is ");
    Print();
    
    return 0;
}
