#include <stdio.h>
#include <stdlib.h>

int N;
int count = 0;
int *column; // column[i]는 i번째 행에서 퀸이 위치한 열

// 현재 퀸의 위치가 유효한지 확인하는 함수
int isValid(int row) {
    for (int i = 0; i < row; i++) {
        if (column[i] == column[row] || abs(column[row] - column[i]) == row - i)
            return 0; // 같은 열이거나 대각선에 위치하는 경우
    }
    return 1;
}

// N-Queen 문제를 해결하는 함수
void nqueen(int row) {
    if (row == N) { // 모든 행에 퀸을 배치한 경우
        count++;
    } else {
        for (int i = 0; i < N; i++) {
            column[row] = i; // 퀸을 i열에 배치
            if (isValid(row)) { // 유효한 위치인지 확인
                nqueen(row + 1); // 다음 행에 퀸을 배치
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    column = (int *)malloc(sizeof(int) * N);
    
    nqueen(0); // 0번 행부터 시작
    
    printf("%d\n", count);
    
    free(column);
    return 0;
}