#include <stdio.h>
#include <stdlib.h>

int main() {
    int N; // 과녁의 수
    scanf("%d", &N);

    int *targets = (int *)malloc(N * sizeof(int)); // 각 과녁의 점수를 저장할 배열
    if (targets == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    int *hit = (int *)calloc(N, sizeof(int)); // 과녁이 맞춰졌는지 여부를 저장할 배열, 초기값은 0(맞추지 않음)
    if (hit == NULL) {
        printf("메모리 할당 실패\n");
        free(targets);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &targets[i]);
    }

    int currentPosition = 0; // 현재 과녁의 위치
    int totalHits = 0; // 맞춘 과녁의 총 수
    while(totalHits < N) {
        if (hit[currentPosition] == 0) {
            printf("%d ", currentPosition + 1); // 현재 과녁의 번호 출력
            hit[currentPosition] = 1; // 현재 과녁을 맞춤으로 표시
            totalHits++;
        }

        if(totalHits >= N) break; // 모든 과녁을 맞췄을 경우 루프 종료

        int steps = targets[currentPosition]; // 이동해야 할 거리
        int moved = 0; // 실제로 이동한 거리
        while (moved < abs(steps)) {
            if (steps > 0) { // 오른쪽으로 이동
                currentPosition = (currentPosition + 1) % N;
            } else { // 왼쪽으로 이동
                currentPosition = (currentPosition - 1 + N) % N;
            }
            if (hit[currentPosition] == 0) { // 아직 맞추지 않은 과녁에만 도달했을 때 이동 거리 증가
                moved++;
            }
        }
    }

    free(targets); // 동적 할당된 메모리 해제
    free(hit);

    return 0;
}