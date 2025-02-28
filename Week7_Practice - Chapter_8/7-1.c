#include <stdio.h>
#include <stdlib.h>

int N; // 노드의 개수
int **graph; // 그래프의 연결 상태를 저장할 이차원 동적 배열
int *parent; // 부모 노드 정보를 저장할 배열
int *visited; // 방문 여부를 체크할 배열

void dfs(int node) {
    visited[node] = 1; // 현재 노드를 방문 처리
    for(int i = 1; i <= N; i++) {
        if(graph[node][i] == 1 && visited[i] == 0) { // 현재 노드와 연결되어 있고 아직 방문하지 않은 노드라면
            parent[i] = node; // 부모 노드 정보 업데이트
            dfs(i); // 해당 노드를 시작으로 다시 DFS 수행
        }
    }
}

int main() {
    scanf("%d", &N); // 노드의 개수 입력 받기
    
    // 동적 메모리 할당
    graph = (int**)malloc((N+1) * sizeof(int*));
    for(int i = 0; i <= N; i++) {
        graph[i] = (int*)malloc((N+1) * sizeof(int));
    }
    parent = (int*)malloc((N+1) * sizeof(int));
    visited = (int*)malloc((N+1) * sizeof(int));
    
    // 초기화
    for(int i = 0; i <= N; i++) {
        visited[i] = 0;
        for(int j = 0; j <= N; j++) {
            graph[i][j] = 0;
        }
    }
    
    // 트리 상에서 연결된 두 정점 입력 받아 그래프 구성
    for(int i = 0; i < N-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    
    // DFS를 이용하여 각 노드의 부모 찾기
    dfs(1); // 1번 노드부터 시작
    
    // 결과 출력
    for(int i = 2; i <= N; i++) {
        printf("%d > %d\n", i, parent[i]);
    }
    
    // 동적 메모리 해제
    for(int i = 0; i <= N; i++) {
        free(graph[i]);
    }
    free(graph);
    free(parent);
    free(visited);
    
    return 0;
}