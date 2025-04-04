// Done
// TC : O(nlogn) for average case,
// TC : O(n^2) for worst case

// We are placing the pivot in its correct position
#include <stdio.h>
#include<time.h>
#include<stdlib.h>


// Function to swap two elements in the array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to partition the array
int partition(int arr[], int l, int r) {
    int pivot = arr[l]; // Pivot element is now the first element
    int i = l + 1; // Start from the second element
    int j = r;     // Start from the last element

    while (i <= j) {
        // Move `i` forward while elements are less than or equal to the pivot
        while (i <= r && arr[i] <= pivot) {
            i++;
        }
        // Move `j` backward while elements are greater than the pivot
        while (arr[j] > pivot) {
            j--;
        }
        // Swap elements at i and j if i is still less than j
        if (i < j) {
            swap(arr, i, j);
        }
    }

    // Swap the pivot element with the element at j
    swap(arr, l, j); // Place the pivot in its correct position
    return j; // Return the new pivot index
}

// QuickSort function
void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r); // Partition the array
        quickSort(arr, l, pi - 1); // Recursively sort the left half
        quickSort(arr, pi + 1, r); // Recursively sort the right half
    }
}

// Main function to test QuickSort
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i<n; i++){
        arr[i] = rand();
    }

    clock_t st, et;
    double ts;
    st = clock();
    quickSort(arr, 0, n-1); // Passing the value of r as n-1 (last index of the array)

    et = clock();

    ts = (double)(et - st) * 1000.0 / CLOCKS_PER_SEC;
    
    // Print the sorted array
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    printf("Time taken: %f", ts);
    printf("\n");
    return 0;
}
