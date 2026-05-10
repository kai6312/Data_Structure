//Linled List//
//Insert a node at beginning//

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;
Node* head;

void insert(int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data; //same as (*temp).data = ...
	temp->next = NULL;

	if(head != NULL)temp->next = head;
	head = temp;
}

void print() {
	Node* temp = head;
	printf("List is:");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	head = NULL;
	int n, x;
	printf("How many number? ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Enter the data：");
		scanf("%d", &x);
		insert(x);
		print();
	}
}