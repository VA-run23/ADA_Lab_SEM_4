#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include time.h for clock()

#define MAX_NODES 100 // Define max number of nodes

int main() {
    int n, m; // n: Number of nodes, m: Number of edges
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    if (n > MAX_NODES) {
        printf("Error: Maximum allowed nodes is %d\n", MAX_NODES);
        return 1;
    }

    int cnt = 0; // Counter for visited nodes
    int indeg[MAX_NODES] = {0}; // Array to store indegree of nodes
    int adj[MAX_NODES][MAX_NODES] = {0}; // Adjacency matrix representation

    printf("Enter %d directed edges (SOURCE DESTINATION):\n", m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u < n && v < n) {
            adj[u][v] = 1; // u --> v (directed edge)
            indeg[v]++;    // Increment indegree of node v
        } else {
            printf("Invalid edge! Nodes should be between 0 and %d.\n", n-1);
            i--; // Decrement i to retry input
        }
    }

    // Initialize a queue for nodes with indegree 0
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            queue[rear++] = i; // Push nodes with indegree 0 into the queue
        }
    }

    // Start the clock before the topological sorting begins
    clock_t start_time = clock();

    // Process nodes in topological order
    printf("\nTopological Order: ");
    while (front < rear) {
        cnt++; // Increment the counter for visited nodes

        int x = queue[front++]; // Dequeue a node
        printf("%d ", x);       // Print the node

        for (int i = 0; i < n; i++) {
            if (adj[x][i] == 1) { // Check adjacency matrix for outgoing edges
                indeg[i]--; // Reduce indegree of adjacent nodes
                if (indeg[i] == 0) {
                    queue[rear++] = i; // Push nodes with indegree 0 into the queue
                }
            }
        }
    }

    // End the clock after topological sorting completes
    clock_t end_time = clock();

    // Calculate total time in milliseconds
    double total_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;

    printf("\nTime taken for topological sorting: %.3f ms\n", total_time);

    return 0;
}


///SAMPLE OUTPUT:
// Enter number of nodes and edges: 10 10
// Enter 10 directed edges (SOURCE DESTINATION):
// 1 3
// 1 4
// 2 4
// 5 6
//  4 5
//  6 7
//  9 7
// 6 5
// 4 5
// 3 6

// Topological Order: 0 1 2 8 9 3 4 
// Time taken for topological sorting: 1.000 ms