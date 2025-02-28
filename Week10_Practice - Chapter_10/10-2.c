#include <stdio.h>
#define MAX_VERTICES 1001
int DFS_V[MAX_VERTICES] = { 0, }; // DFS 방문 확인 배열
int BFS_V[MAX_VERTICES] = { 0, }; // BFS 방문 확인 배열
int graph[MAX_VERTICES][MAX_VERTICES] = { 0, }; // 그래프 인접 행렬
int queue[MAX_VERTICES]; // BFS를 위한 큐
void dfs(int v, int vertices);
void bfs(int v, int vertices);
void print_array(int arr[], int count);

int main() {
    int vertices, edges, vertex, i, j;
    scanf("%d %d %d", &vertices, &edges, &vertex);

    while (edges--) {
        scanf("%d %d", &i, &j);
        graph[i][j] = 1;
        graph[j][i] = 1;
    }

    dfs(vertex, vertices);
    printf("\n");
    bfs(vertex, vertices);

    return 0;
}

void dfs(int v, int vertices) {
    static int path[MAX_VERTICES], count = 0;
    DFS_V[v] = 1;
    path[count++] = v;
    for (int w = 1; w <= vertices; w++) {
        if (graph[v][w] == 1 && !DFS_V[w]) {
            dfs(w, vertices);
        }
    }
    if (v == path[0]) { // DFS의 시작점에서 출력을 진행합니다.
        print_array(path, count);
        count = 0; // 다음 호출을 위해 count 초기화
    }
}

void bfs(int v, int vertices) {
    int front = 0, rear = 0, pop, w;
    int path[MAX_VERTICES], count = 0;
    BFS_V[v] = 1;
    queue[rear++] = v;

    while (front < rear) {
        pop = queue[front++];
        path[count++] = pop;
        for (w = 1; w <= vertices; w++) {
            if (graph[pop][w] == 1 && !BFS_V[w]) {
                queue[rear++] = w;
                BFS_V[w] = 1;
            }
        }
    }
    print_array(path, count);
}

void print_array(int arr[], int count) {
    for (int i = 0; i < count; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
}
