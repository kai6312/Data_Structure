//Linled List//
//Reverse a linked list by recursiving//

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node* next;
}Node; 

Node* Insert(Node* head, int data)
{
    Node* temp1 = (Node*)malloc(sizeof(Node));
    Node* temp2 = head;
    temp1->data = data;
    temp1->next = NULL;
    
    if(head == NULL)
    {
        head = temp1;
    }
    else
    {
        while(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
    return head;
}

void Print(Node* p)
{
    if(p == NULL) return;
    printf("%d ", p->data);
    Print(p->next);
}

void Reverse_Print(Node* p)
{
    if(p == NULL) return;
    Reverse_Print(p->next);
    printf("%d ", p->data);
}

int main()
{
    Node* head = NULL;
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,5);
    head = Insert(head,8); //2, 4, 5, 8

    printf("Linked list is ");
    Print(head);

    printf("\nReverse linked list is ");
    Reverse_Print(head);
    
    return 0;
}
