/*
  This program solves the 0/1 Knapsack problem using dynamic programming 
  and a static 2D array.
 
  1. The knapsack function fills a dp table where dp[i][w] represents the maximum value possible with i items and weight w.
  2. If an item's weight is within the current capacity, the function decides whether to include or exclude it for the optimal value.
  3. The program first takes user input for n (number of items) and W (maximum capacity), then inputs the weights and values for each item.
  4. The main function checks if user input exceeds predefined limits (MAX_ITEMS, MAX_CAPACITY) to prevent memory issues.
  5. The computed maximum possible value for the given items and capacity is obtained from dp[n][W] and displayed.
  6. This implementation ensures an efficient O(n  W) time complexity and avoids dynamic memory allocation for simplicity.
*/

#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

// 0/1 Knapsack function using dynamic programming with static arrays
int knapsack(int value[], int wt[], int n, int W) {
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1]; // Static 2D array for DP table

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case: No items or no capacity
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w]; // Skip the item
            }
        }
    }

    return dp[n][W]; // Maximum value that can be achieved
}

int main() {
    int n, W;

    // Taking user input for number of items and capacity
    printf("Enter number of items (max %d) and max weight capacity (max %d): ", MAX_ITEMS, MAX_CAPACITY);
    scanf("%d %d", &n, &W);

    if (n > MAX_ITEMS || W > MAX_CAPACITY) {
        printf("Error: Exceeds allowed limits!\n");
        return 1;
    }

    int wt[MAX_ITEMS], value[MAX_ITEMS];

    // Taking user input for weights and values
    printf("Enter weights of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter values of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    // Compute and display the maximum value that can be achieved
    int max_value = knapsack(value, wt, n, W);
    printf("\nMaximum value: %d\n", max_value);

    return 0;
}