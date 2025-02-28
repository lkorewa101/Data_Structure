#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q) {
	q->front = q->rear = -1;
}

int is_empty(QueueType *q) {
	return q->front == q->rear;
}

int is_full(QueueType *q) {
	return q->front == (q->rear +1) % MAX_QUEUE_SIZE;
}

void enqueue(QueueType *q, int item) {
	if(is_full(q)) {
		printf("Overflow\n");
	} else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;

		q->data[q->rear] = item;
	}
}

int dequeue(QueueType *q) {
	if(is_empty(q)) {
		printf("Empty\n");
		return 0;
	} else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

void queue_print(QueueType *q) {
    for(int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if(i <= q->front || i > q->rear) {
			printf(",");
		} else {
			printf("%d,", q->data[i]);
		}
	} printf("\n");
}


int main() {
	int item = 0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	return 0;
}