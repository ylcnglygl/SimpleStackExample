#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *top = NULL;

void push(int data2) {
	struct node* adding = (struct node*) malloc(sizeof(struct node));
	adding->data = data2;
	adding->next = NULL;
	if (top != NULL)
		adding->next = top;
	top = adding;
}

void pop() {
	if (top == NULL)
		printf("Wrong choice");
	else
	{
		struct node *temp;
		temp = top;
		top = top->next;
		free(temp);
	}
}



int peek() {
	return top->data;
}

void count() {
	int count = 0;
	struct node *q;
	q = top;
	while (q != NULL) {
		count++;
		q = q->next;
	}
	printf("Count of stack: %d", count);
	//printf(" NULL");
}

void print() {
	struct node *q;
	q = top;
	printf("\n");
	while (q != NULL) {
		printf(" %d", q->data);
		q = q->next;
	}
	//printf(" NULL");
}

int main() {
	int choice = -1, number;
	while (choice != 5) {
		printf("\n 1- Push");
		printf("\n 2- Pop");
		printf("\n 3- Peek");
		printf("\n 4- Count");
		printf("\n 5- Exit");
		printf("\n Choose: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("Add a value: ");
			scanf("%d", &number);
			push(number);
			print();
			break;
		case 2:
			pop();
			print();
			break;
		case 3:
			if (top == NULL) {
				printf("Wrong choice\n");
			}
			else {
				printf("Top value => %d ", peek());
				print();
			}
			break;
		case 4:
			count();
			break;
		}
	}

	return 0;
}
