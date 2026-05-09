//Linled List//
//Insert a node at n-th position//

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;
Node* head;

void insert(int data, int n) {
	Node* temp1 = (Node*)malloc(sizeof(Node));
	temp1->data = data;
	temp1->next = NULL;
	if (n == 1) {
		temp1->next = head;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	for (int i = 0; i < n - 2; i++) {
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
		 
}

void print() {
	Node* temp = head;
	while (temp != 0) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	head = NULL;
	insert(3, 1);//3
	insert(1, 2);//3 1
	insert(6, 1);//6 3 1
	insert(4, 2);//6 4 3 1
	print();
}