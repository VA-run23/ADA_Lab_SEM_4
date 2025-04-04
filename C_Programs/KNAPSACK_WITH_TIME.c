

/*
1. Initialize a 2D DP array where dp[i][w] represents the maximum value that 
   can be achieved with the first i items and weight capacity w.
2. If no items (i == 0) or no weight capacity (w == 0), set dp[i][w] = 0.
3. If the current item's weight is less than or equal to w, decide whether 
   to include the item (maximize value) or exclude it.
4. Otherwise, skip the item by inheriting the value from the previous row.
5. Use nested loops to fill the DP table iteratively for all items and capacities.
6. Retrieve the maximum value from dp[n][W] after processing all items.
7. Free the dynamically allocated memory for efficient cleanup.
*/


// This program uses Dynamic programming and thus it can handle large values of n (number of items).
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // Include sys/time.h for accurate timing calculations

int max(int a, int b) {
    return (a > b) ? a : b;
}

// A sample knapsack function (example for a 0/1 knapsack problem)
int knapsack(int value[], int wt[], int n, int W) {
    int i, w;
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case: no items or no capacity
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w]; // Skip the item
            }
        }
    }
    int max_value = dp[n][W];

    for (i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return max_value;
}

int main() {
    // Randomly generate the weights and values
    int n;
    int W;
    scanf("%d %d", &n, &W);

    int wt[n], value[n];

    for (int i = 0; i < n; i++) {
        wt[i] = rand() % 20 + 1; // Random weight between 1 and 20
        value[i] = rand() % 100 + 1; // Random value between 1 and 100
    }

    // Print the generated weights and values
    // printf("Generated weights: ");
    // for (int i = 0; i < n; i++) printf("%d ", wt[i]);
    // printf("\n");

    // printf("Generated values: ");
    // for (int i = 0; i < n; i++) printf("%d ", value[i]);
    // printf("\n");

    // Measure time using timeval structure
    struct timeval start, end;
    
    // Record start time
    gettimeofday(&start, NULL);

    // Perform the computation
    int max_value = knapsack(value, wt, n, W);

    // Record end time
    gettimeofday(&end, NULL);

    // Calculate the execution time in seconds and milliseconds
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double total_time = seconds * 1000.0 + microseconds / 1000.0;

    // Display results
    printf("\nMaximum value: %d\n", max_value);
    printf("Time taken: %.3f ms\n", total_time);

    return 0;
}
