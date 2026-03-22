#include <stdio.h>

int adj[10][10], visited[10], n;

// DFS
void dfs(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for(i = 0; i < n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
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

    dfs(start);

    return 0;
}