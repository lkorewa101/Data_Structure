#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, K;
char ans[1000][11]; // 최대 K+N-1개의 문자열을 저장할 수 있어야 합니다.
char str[11];

// 비교 함수
int cmp(const void *a, const void *b) {
    char first[22], second[22]; // 두 문자열을 연결할 임시 문자열
    strcpy(first, *(const char**)a);
    strcat(first, *(const char**)b);
    strcpy(second, *(const char**)b);
    strcat(second, *(const char**)a);
    return strcmp(first, second) > 0 ? -1 : 1;
}

int main() {
    scanf("%d %d", &K, &N);
    str[0] = '\0'; // str을 빈 문자열로 초기화

    for (int i = 0; i < K; i++) {
        scanf("%s", ans[i]);
        if (strlen(str) < strlen(ans[i]) || (strlen(str) == strlen(ans[i]) && strcmp(str, ans[i]) < 0)) {
            strcpy(str, ans[i]); // str에 가장 큰 문자열 저장
        }
    }

    for (int i = K; i < N; i++) {
        strcpy(ans[i], str); // 가장 큰 문자열로 나머지를 채움
    }

    // ans 포인터 배열 생성
    char* pointers[1000];
    for (int i = 0; i < N; i++) {
        pointers[i] = ans[i];
    }

    // 정렬
    qsort(pointers, N, sizeof(char*), cmp);

    // 출력
    for (int i = 0; i < N; i++) {
        printf("%s", pointers[i]);
    }

    return 0;
}
