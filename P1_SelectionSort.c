#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void selectionSort(int array[], int size) {
    int i, j, minIdx;
    for(i = 0; i<size-1; i++) {
        minIdx = i; // get index of minimum data
        for(j = i+1; j<size; j++)
            if(array[j] < array[minIdx])
                minIdx = j;
        
        // Swap elements
        int temp = array[i];
        array[i] = array[minIdx];
        array[minIdx] = temp;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 100; // Random values between 0-99
    
    printf("Array before Sorting: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    struct timeval start, end;
    gettimeofday(&start, NULL); // Start time

    selectionSort(arr, n);

    gettimeofday(&end, NULL); // End time

    printf("Array after Sorting: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Calculate execution time in microseconds
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds*1e-6;

    printf("Execution Time: %f seconds\n", elapsed);

    return 0;
}



///SAMPLE OUTPUT: 1
// Enter the number of elements: 10
// Array before Sorting: 41 67 34 0 69 24 78 58 62 64 
// Array after Sorting: 0 24 34 41 58 62 64 67 69 78
// Execution Time: 0.000000 seconds


///SAMPLE OUTPUT: 2
// Enter the number of elements: 5000
// Execution Time: 0.014005 seconds
