#include <stdio.h>
#include <stdlib.h>

// Function to perform topological sorting
int main() {
    int n, m; // n: Number of nodes, m: Number of edges
    scanf("%d %d", &n, &m);

    int cnt = 0; // Counter for visited nodes
    int *indeg = (int *)calloc(n, sizeof(int)); // Array to store indegree of nodes
    int **adj = (int **)malloc(n * sizeof(int *)); // Adjacency list representation
    for (int i = 0; i < n; i++) {
        adj[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            adj[i][j] = 0; // Initialize adjacency list to 0
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // u --> v (directed edge)
        indeg[v]++;    // Increment indegree of node v
    }

    // Initialize a queue for nodes with indegree 0
    int *queue = (int *)malloc(n * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            queue[rear++] = i; // Push nodes with indegree 0 into the queue
        }
    }

    // Process nodes in topological order
    while (front < rear) {
        cnt++; // Increment the counter for visited nodes

        int x = queue[front++]; // Dequeue a node
        printf("%d ", x);       // Print the node

        for (int i = 0; i < n; i++) {
            if (adj[x][i] == 1) { // Check adjacency list for outgoing edges
                indeg[i]--; // Reduce indegree of adjacent nodes
                if (indeg[i] == 0) {
                    queue[rear++] = i; // Push nodes with indegree 0 into the queue
                }
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(indeg);
    free(queue);

    return 0;
}
