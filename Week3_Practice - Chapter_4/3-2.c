#include <stdio.h>
#include <stdbool.h> // bool, true, false가 정의된 헤더 파일
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char data) {
    if (s->top < MAX_SIZE - 1) {
        s->top++;
        s->arr[s->top] = data;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        char data = s->arr[s->top];
        s->top--;
        return data;
    }
    return -1;
}

bool isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')') return true;
    else if (character1 == '{' && character2 == '}') return true;
    else if (character1 == '[' && character2 == ']') return true;
    else return false;
}

bool isBalanced(char *expression) {
    Stack s;
    initialize(&s);
    int i = 0;
    while (expression[i]) {
        if (expression[i] == '{' || expression[i] == '(' || expression[i] == '[') {
            push(&s, expression[i]);
        }

        // 닫는 괄호일 경우
        if (expression[i] == '}' || expression[i] == ')' || expression[i] == ']') {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), expression[i])) {
                return false;
            }
        }
        i++;
    }
    
    return isEmpty(&s);
}

int main() {
    char expression[MAX_SIZE];
    scanf("%s", expression);

    if (isBalanced(expression))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}