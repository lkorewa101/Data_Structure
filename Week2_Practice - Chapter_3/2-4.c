#include <stdio.h>

#define MAX_LEVEL 50 // 출력될 최대 높이
#define MAX_WIDTH 40 // 출력될 최대 너비

char screen[MAX_LEVEL][MAX_WIDTH + 1]; // 널 문자를 위해 +1
int max_row = -1; // 출력할 내용이 있는 마지막 행

// screen 배열을 공백으로 초기화하는 함수
void initialize_screen() {
    for (int i = 0; i < MAX_LEVEL; ++i) {
        for (int j = 0; j < MAX_WIDTH; ++j) {
            screen[i][j] = ' '; // 공백으로 초기화
        }       
    }
}

// screen 배열에 패턴을 그리는 재귀 함수
void draw_tree(int row, int left, int right) {
    // 영역이 충분히 작으면 복귀
    if (right - left <= 3) {
        return;
    }
    if (row > max_row) {
        max_row = row; // 마지막으로 내용이 있는 행 업데이트
    }
    int mid = (left + right) / 2; // 중간 위치 계산

    for (int i = left; i < right; i++) { // 이전에 누락된 '-'를 추가하지 않음
        if (screen[row][i] != 'X') {
            screen[row][i] = '-';
        }
    }

    screen[row][mid] = 'X'; // 중간 위치에 'X' 표시

    // 현재 영역을 반으로 나누어 각각에 대해 draw_tree 함수를 순환 호출
    draw_tree(row + 1, left, mid); // 왼쪽 영역, mid 포함
    draw_tree(row + 1, mid, right); // 오른쪽 영역, mid+1부터가 아니라 mid부터 시작
}

// screen 배열을 화면에 출력하는 함수
void print_screen() {
    for (int i = 0; i <= max_row; ++i) { // 내용이 있는 마지막 행까지만 출력
        printf("%s\n", screen[i]);
    }
}

int main() {
    initialize_screen(); // screen 초기화
    draw_tree(0, 0, MAX_WIDTH); // 패턴 그리기, MAX_WIDTH를 정확히 지정
    print_screen(); // 결과 출력

    return 0;
}