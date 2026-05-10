//Linled List//
//Insert a node at end + Delete a node at n-th position//

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

void Delete(int n)
{
    Node* temp1 = head;
    
    if(n==1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    
    for(int i = 0;i < n-2;i++)
    {
        temp1 = temp1->next; //n-1 node
    }
    
    Node* temp2 = temp1->next;//n node
    temp1->next = temp2->next;
    free(temp2);
    
}

int main()
{
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(5);
    Insert(8); //2, 4, 5, 8
    Print();
    
    int n;
    printf("Enter n-th position:");
    scanf("%d", &n);
    Delete(n);
    Print();
    
    return 0;
}
