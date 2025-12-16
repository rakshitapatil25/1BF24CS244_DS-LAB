#include <stdio.h>

#define MAX 10

int visited[MAX];
int adj[MAX][MAX];
int n;

// DFS function
void DFS(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {

    int connected = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Start DFS from vertex 0
    DFS(0);

    // Check if all vertices are visited
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("The graph is CONNECTED\n");
    else
        printf("The graph is NOT CONNECTED\n");

    return 0;
}
