//THis program does not use Dynamic programming and thus it can't handle for large values of n(number of items)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Helper function to calculate the maximum of two numbers
int Max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive knapsack function
int knapsack(int value[], int wt[], int n, int W) {
    if (n == 0 || W == 0) { // Base case
        return 0;
    }
    if (wt[n - 1] > W) { // Skip item if it exceeds capacity
        return knapsack(value, wt, n - 1, W);
    }
    return Max(knapsack(value, wt, n - 1, W), // Exclude item
               value[n - 1] + knapsack(value, wt, n - 1, W - wt[n - 1])); // Include item
}

int main() {
    int n, W;
    scanf("%d %d", &n, &W);

    // Validate input
    if (n <= 0 || W < 0) {
        printf("Invalid input: n should be > 0 and W should be >= 0.\n");
        return 1;
    }

    // Dynamically allocate arrays
    int *wt = (int *)malloc(n * sizeof(int));
    int *value = (int *)malloc(n * sizeof(int));

    srand(time(NULL)); // Seed the random number generator

    // Generate random weights and values
    for (int i = 0; i < n; i++) {
        wt[i] = rand() % 20 + 1;     // Random weight between 1 and 20
        value[i] = rand() % 100 + 1; // Random value between 1 and 100
    }

    // Display generated weights and values
    // printf("Generated weights: ");
    // for (int i = 0; i < n; i++) printf("%d ", wt[i]);
    // printf("\n");

    // printf("Generated values: ");
    // for (int i = 0; i < n; i++) printf("%d ", value[i]);
    // printf("\n");

    // Measure execution time
    clock_t st, et;
    st = clock();

    int max_value = knapsack(value, wt, n, W);

    et = clock();

    // Calculate total execution time in milliseconds
    double total_time = (double)(et - st) * 1000.0 / CLOCKS_PER_SEC;

    // Display results
    printf("\nMaximum value: %d\n", max_value);
    printf("Time taken: %.3f ms\n", total_time);

    // Free allocated memory
    free(wt);
    free(value);

    return 0;
}
