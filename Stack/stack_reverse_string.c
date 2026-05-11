#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *next;
}Node;

Node *top;

void Push(char x)
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

char Top()
{
    if (top == NULL)
    {
        return '\0';
    }

    return top->data;
}

void Print()
{
    Node* temp = top;
    printf("Stack:\nabcde");
    while(temp != NULL)
    {
        printf("%c\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    top = NULL;

    printf("Input String: ");
    char s[101];
    scanf("%s", s);

    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        Push(s[i]);
    }
    Print();

    for(int i = 0; i < len; i++)
    {
        s[i] = Top();
        Pop();
    }
    printf("Reverse: %s", s);

    return 0;
}