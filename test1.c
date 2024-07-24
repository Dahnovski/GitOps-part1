#include <stdio.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    // Bubble Sort
    int bubbleArr[n];
    for (int i = 0; i < n; i++) bubbleArr[i] = arr1[i];
    bubbleSort(bubbleArr, n);
    printf("Bubble Sorted array: \n");
    printArray(bubbleArr, n);

    // Insertion Sort
    int insertionArr[n];
    for (int i = 0; i < n; i++) insertionArr[i] = arr1[i];
    insertionSort(insertionArr, n);
    printf("Insertion Sorted array: \n");
    printArray(insertionArr, n);

    // Quick Sort
    int quickArr[n];
    for (int i = 0; i < n; i++) quickArr[i] = arr1[i];
    quickSort(quickArr, 0, n - 1);
    printf("Quick Sorted array: \n");
    printArray(quickArr, n);

    return 0;
}

