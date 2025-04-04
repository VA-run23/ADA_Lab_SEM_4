
//THis program use Dynamic programming and thus it can handle for large values of n(number of items)
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

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
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = (value[i - 1] + dp[i - 1][w - wt[i - 1]] > dp[i - 1][w])
                               ? value[i - 1] + dp[i - 1][w - wt[i - 1]]
                               : dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
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
    int n ;
    int W ;
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

    // Calculate the time taken by the knapsack function
    clock_t st, et;
    st = clock();

    int max_value = knapsack(value, wt, n, W);

    et = clock();

    // Calculate total execution time in milliseconds
    double total_time = (double)(et - st) * 1000.0 / CLOCKS_PER_SEC;

    // Display results
    printf("\nMaximum value: %d\n", max_value);
    printf("Time taken: %.3f ms\n", total_time);

    return 0;
}
