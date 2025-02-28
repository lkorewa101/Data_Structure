#include <stdio.h>
#include <string.h>

#define QUEUE_SIZE 10

char queue[QUEUE_SIZE][50]; // 50자까지의 이름을 저장할 수 있는 크기 10의 문자열 배열
int front = 0;
int rear = 0;

// 큐가 비어있는지 확인하는 함수
int isEmpty() {
    return front == rear;
}

// 큐가 가득 찼는지 확인하는 함수
int isFull() {
    return (rear + 1) % QUEUE_SIZE == front;
}

// Enqueue 함수
void enqueue(char name[]) {
    if(isFull()) {
        printf("대기열이 가득 찼습니다.\n");
    } else {
        strcpy(queue[rear], name);
        rear = (rear + 1) % QUEUE_SIZE;
    }
}

// Dequeue 함수
void dequeue() {
    if(isEmpty()) {
        printf("대기열이 비어 있습니다.\n");
    } else {
        front = (front + 1) % QUEUE_SIZE;
        enqueue(queue[front - 1]); // 탑승한 사람을 다시 큐의 끝으로 이동
    }
}

// Display 함수
void display() {
    if(isEmpty()) {
        printf("대기열이 비어 있습니다.\n");
    } else {
        int i = front;
        while(i != rear) {
            printf("%s", queue[i]);
            if((i + 1) % QUEUE_SIZE != rear) {
                printf(", ");
            }
            i = (i + 1) % QUEUE_SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    char name[50];

    while(1) {
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                scanf("%s", name);
                enqueue(name);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0; 
        }
    }

    return 0;
}