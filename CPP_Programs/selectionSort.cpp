#include <iostream>
using namespace std;
void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        // Find the minimum element in remaining unsorted array
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        cout<<"Array after "<<i<<"th traversal is: ";
        printArray(arr, n);
    }
}



int main() {
    int arr[] = {23, 6, 8, 11, 15, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array is: ";
    printArray(arr, n);
    return 0;
}
// //OUTPUT:
// Array after 0th traversal is: 6 23 8 11 15 40 
// Array after 1th traversal is: 6 8 23 11 15 40 
// Array after 2th traversal is: 6 8 11 23 15 40 
// Array after 3th traversal is: 6 8 11 15 23 40 
// Array after 4th traversal is: 6 8 11 15 23 40 
// Sorted array is: 6 8 11 15 23 40 
