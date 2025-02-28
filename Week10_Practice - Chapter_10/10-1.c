#include <stdio.h>
int graph[101][101] = {0, };
int q[10001][2] = {0, };


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n = 0, m = 0;

int bfs() {
    int front = 0, rear = 0;
    q[front][0] = 1;
    q[front][1] = 1;
    rear++;
    
    // 큐가 빌 때 까지
    while(front < rear) {
        int x = q[front][0];
        int y = q[front][1];
        front++; 
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || ny < 1 || nx > n || ny > m) {
                continue;
            }

            if(graph[nx][ny] != 1) {
                continue;
            }
            graph[nx][ny] = graph[x][y] + 1;

            q[rear][0] = nx;
            q[rear][1] = ny;
            rear++;
        }
    }
    return graph[n][m];
}

int main()
{
    scanf("%d %d", &n, &m);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }
   
    int ans = bfs();
    printf("%d", ans);
    
    return 0;
}
