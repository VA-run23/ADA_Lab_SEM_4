// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h> // Include time.h for clock()

// int main() {
//     int n, m; // n: Number of nodes, m: Number of edges
//     scanf("%d %d", &n, &m);

//     int cnt = 0; // Counter for visited nodes
//     int *indeg = (int *)calloc(n, sizeof(int)); // Array to store indegree of nodes
//     int **adj = (int **)malloc(n * sizeof(int *)); // Adjacency list representation
//     for (int i = 0; i < n; i++) {
//         adj[i] = (int *)malloc(n * sizeof(int));
//         for (int j = 0; j < n; j++)
//             adj[i][j] = 0; // Initialize adjacency list to 0
//     }

//     for (int i = 0; i < m; i++) {
//         int u, v;
//         u = rand() % n; // Random value between 0 and n-1
//         v = rand() % n; // Random value between 0 and n-1
//         adj[u][v] = 1; // u --> v (directed edge)
//         indeg[v]++;    // Increment indegree of node v
//     }

//     // Initialize a queue for nodes with indegree 0
//     int *queue = (int *)malloc(n * sizeof(int));
//     int front = 0, rear = 0;

//     for (int i = 0; i < n; i++) {
//         if (indeg[i] == 0) {
//             queue[rear++] = i; // Push nodes with indegree 0 into the queue
//         }
//     }

//     // Start the clock before the topological sorting begins
//     clock_t start_time = clock();

//     // Process nodes in topological order
//     while (front < rear) {
//         cnt++; // Increment the counter for visited nodes

//         int x = queue[front++]; // Dequeue a node
//         printf("%d ", x);       // Print the node

//         for (int i = 0; i < n; i++) {
//             if (adj[x][i] == 1) { // Check adjacency list for outgoing edges
//                 indeg[i]--; // Reduce indegree of adjacent nodes
//                 if (indeg[i] == 0) {
//                     queue[rear++] = i; // Push nodes with indegree 0 into the queue
//                 }
//             }
//         }
//     }

//     // End the clock after topological sorting completes
//     clock_t end_time = clock();

//     // Calculate total time in milliseconds
//     double total_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;

//     printf("\nTime taken for topological sorting: %.3f ms\n", total_time);

//     // Free allocated memory
//     for (int i = 0; i < n; i++) {
//         free(adj[i]);
//     }
//     free(adj);
//     free(indeg);
//     free(queue);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // Include sys/time.h for struct timeval and gettimeofday()

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
        u = rand() % n; // Random value between 0 and n-1
        v = rand() % n; // Random value between 0 and n-1
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

    // Start the timer using gettimeofday()
    struct timeval start, end;
    gettimeofday(&start, NULL);

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

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate the elapsed time in milliseconds
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds * 1000.0 + microseconds / 1000.0;

    printf("\nTime taken for topological sorting: %.3f ms\n", elapsed);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(indeg);
    free(queue);

    return 0;
}
