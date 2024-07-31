#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct node {
	int data;
	struct node* next;
}queue;

queue* rear = NULL;
queue* front = NULL;

int queue_empty() {
	if (front == NULL && rear == NULL)
		return 1;
	return 0;
}

int enqueue(int x) {
	queue* new_node = (queue*)malloc(sizeof(queue));

	new_node->data = x;
	new_node->next = NULL;

	if (front == NULL && rear == NULL) {
		rear = new_node;
		front = new_node;
	}
	else {
		rear->next = new_node;
		rear = new_node;
	}

}

int dequeue() {
	int value;
	queue* node = (queue*)malloc(sizeof(queue));

	node = front;
	value = front->data;
	front = front->next;
	free(node);

	if (front == NULL)
		rear = NULL;

	return value;

}

int print_queue() {
	queue* temp = front;
	printf("queue : ");
	while (temp != NULL) {
		if (temp == rear)
			printf("%d", temp->data);
		else
			printf("%d ", temp->data);

		temp = temp->next;
	}
	printf("\n");
}

int run_enqueue(int num[], int x) {
	for (int i = 0; i < x; i++) {
		enqueue(num[i]);
		printf("enqueue %d\n", num[i]);
		print_queue();
	}
}

int run_dequeue(int x) {
	int value;
	for (int i = 0; i < x; i++) {
		if (!queue_empty()) {
			printf("run dequeue\n");
			value = dequeue();
		}
		else
			printf("queue empty");

		print_queue();
	}
}

int main() {
	int numbers[] = { 5, 61, 12, 37, 88, 24, 9, 40, 15, 27 };

	run_enqueue(numbers, 5);
	printf("\n");
	run_dequeue(3);
}
