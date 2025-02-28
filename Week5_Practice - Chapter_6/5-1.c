#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int count;
    int *queue;
    int maxSize;
} CircularQueue;

void initQueue(CircularQueue *q, int maxSize) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    q->maxSize = maxSize;
    q->queue = (int *)malloc(maxSize * sizeof(int));
}

int isFull(CircularQueue *q) {
    return q->count == q->maxSize;
}

int isEmpty(CircularQueue *q) {
    return q->count == 0;
}

void enqueue(CircularQueue *q, int element) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    q->queue[q->rear] = element;
    q->rear = (q->rear + 1) % q->maxSize;
    q->count++;
    printf("%d\n", element);
}

void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n0\n");
        return;
    }
    printf("%d\n", q->queue[q->front]);
    q->front = (q->front + 1) % q->maxSize;
    q->count--;
}

void freeQueue(CircularQueue *q) {
    free(q->queue);
}

int main() {
    CircularQueue q;
    int maxQueueSize;
    scanf("%d", &maxQueueSize);
    initQueue(&q, maxQueueSize);

    // 요소 추가
    for (int i = 1; i <= maxQueueSize + 1; i++) {
        enqueue(&q, i);
    }

    // 요소 제거
    for (int i = 1; i <= maxQueueSize + 1; i++) {
        dequeue(&q);
    }

    freeQueue(&q);

    return 0;
}