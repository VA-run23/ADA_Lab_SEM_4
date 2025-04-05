#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, minIdx;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIdx = v;
        }
    }
    return minIdx;
}

// Function to print the constructed MST and its total weight
void printMST(int parent[], int graph[][100], int V, int totalWt) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
    printf("\nTotal Weight of the MST: %d\n", totalWt);
}

// Function to perform Prim's algorithm
void primMST(int graph[][100], int V) {
    int parent[V];  // Array to store the MST
    int key[V];     // Key values used to pick minimum weight edge
    int mstSet[V];  // To represent vertices included in MST
    int totalWt = 0; // To store the total weight of the MST

    // Initialize all key values as infinite
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include the first vertex in the MST
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Calculate the total weight of the MST
    for (int i = 1; i < V; i++) {
        totalWt += graph[i][parent[i]];
    }

    // Print the constructed MST and its total weight
    printMST(parent, graph, V, totalWt);
}

int main() {
    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    int graph[100][100] = {0}; // Assuming a maximum size of 100 vertices
    printf("Enter edges (source destination weight): ");

    // Input edges and weights from the user
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);

        // Ensure no self-loops and overwrite existing edges
        if (src != dest) {
            graph[src - 1][dest - 1] = weight;
            graph[dest - 1][src - 1] = weight;
            
        }
    }

    printf("\nInput Graph (Adjacency Matrix):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum Spanning Tree using Prim's Algorithm:\n");
    primMST(graph, V);

    return 0;
}

// ////Sample output::
// Enter the number of vertices: 5
// Enter the number of edges: 5
// Enter edges (source destination weight): 1 2 3
// 2 3 4
// 1 4 3
// 3 5 2
// 4 5 6

// Input Graph (Adjacency Matrix):
// 0 3 0 3 0 
// 3 0 4 0 0 
// 0 4 0 0 2 
// 3 0 0 0 6 
// 0 0 2 6 0 

// Minimum Spanning Tree using Prim's Algorithm:
// Edge 	Weight
// 0 - 1 	3
// 1 - 2 	4
// 0 - 3 	3
// 2 - 4 	2

// Total Weight of the MST: 12