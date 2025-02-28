#include <stdio.h>
#include <string.h>
#define MAX_SIZE 30

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1; // 스택이 비었는지 확인
}

void push(Stack *s, char data) {
    if (s->top < MAX_SIZE - 1) { // 스택이 가득 차지 않았는지 확인
        s->top++;
        s->arr[s->top] = data;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) { // 스택이 비어있지 않은지 확인
        char data = s->arr[s->top];
        s->top--;
        return data;
    }
    return -1; // 스택이 비어있으면 -1 반환
}

int main() {
    char input[MAX_SIZE], reversed[MAX_SIZE];
    Stack s;
    initialize(&s);

    scanf("%s", input); // 사용자로부터 문자열 입력 받기

    int length = strlen(input); // 입력된 문자열의 길이 계산
    for (int i = 0; i < length; i++) {
        push(&s, input[i]); // 스택에 문자 Push
    }

    for (int i = 0; i < length; i++) {
        reversed[i] = pop(&s); // 스택에서 문자 Pop하여 reversed 배열에 저장
    }
    reversed[length] = '\0'; // 문자열 마지막에 널 문자 추가

    printf("%s", reversed); // 반전된 문자열 출력

    return 0;
}