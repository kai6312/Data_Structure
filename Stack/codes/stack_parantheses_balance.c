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

int IsEmpty()
{
    return top == NULL;
}


int ArePair(char opening, char closing)
{
    if(opening == '(' && closing == ')')
        return 1;

    else if(opening == '{' && closing == '}')
        return 1;

    else if(opening == '[' && closing == ']')
        return 1;

    return 0;
}

int AreParanthesesBalanced(char* exp) //same as char exp[]
{
    for(int i = 0; i < strlen(exp); i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[' )
        {
            Push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']' )
        {
            if(IsEmpty() || !ArePair(Top(), exp[i]))
            {
                return 0;
            }
            Pop();
        }
    }
    return IsEmpty();
}

int main()
{
    top = NULL;

    printf("Enter an expression:  ");
    char s[101];
    scanf("%s", s);

	if(AreParanthesesBalanced(s))
		printf("Balanced\n");
	else
		printf("Not Balanced\n");

    return 0;
}