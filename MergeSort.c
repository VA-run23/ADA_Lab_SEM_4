//Done
//NOTE: The merging process in merge sort happens through recurring comparisons.
//TC : O(nlogn)

// Dividing the array takes O(log n) time since the array is repeatedly split in half.
// Merging these sorted subarrays takes O(n) time.
// Since merging two halves takes linear time O(n), and there are log n levels, the total merging time is O(n log n).

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Function to merge two sorted subarrays
void merge(int arr[], int l, int mid, int r) {
    // The merging process in merge sort happens through recurring comparisons.
    int n1 = mid - l + 1; // Size of the first subarray
    int n2 = r - mid;     // Size of the second subarray

    // Create temporary arrays
    int a[n1], b[n2];

    // Copy data to temporary arrays a[] and b[]
    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    // Merge the temporary arrays back into arr[l..r]
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of a[], if any
    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }

    // Copy the remaining elements of b[], if any
    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int l, int r) { // arr: array to be sorted, l: start index, r: end index
    if (l < r) {
        int mid = (l + r) / 2; // Find the middle point
        mergeSort(arr, l, mid); // Sort the first half
        mergeSort(arr, mid + 1, r); // Sort the second half
        merge(arr, l, mid, r); // Merge the sorted halves, this is not recursive
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    struct timeval start, end;
    gettimeofday(&start, NULL); // Start time
    mergeSort(arr, 0, n - 1); // Sort the array
    gettimeofday(&end, NULL); // End time

    // Calculate the time in microseconds
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds * 1000.0 + microseconds / 1000.0;

    // Print the sorted array
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    printf("\nExecution Time: %.3f ms\n", elapsed);

    return 0;
}
