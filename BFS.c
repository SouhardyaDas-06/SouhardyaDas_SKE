#include <stdio.h>

int adj[10][10], visited[10], queue[10];
int n, front = 0, rear = 0;

// BFS
void bfs(int start) {
    int i;

    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++) {
            if(adj[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}