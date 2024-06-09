#include "sort.h"
#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(arr[i], arr[maxIdx]);
        }
#ifdef _DEBUG
        printArray(arr, n);
#endif
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
#ifdef _DEBUG
        printArray(arr, n);
#endif
    }
}

void bubbleSortAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
#ifdef _DEBUG
        printArray(arr, n);
#endif
    }
}

void bubbleSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
#ifdef _DEBUG
        printArray(arr, n);
#endif
    }
}

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] >= pivot) {  // Change to >= for descending order
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);

#ifdef _DEBUG
    printArray(arr, right + 1);
#endif

    quickSort(arr, left, i);
    quickSort(arr, i + 2, right);
}

void mergeArrays(int arr[], int start, int middle, int end, int totalSize) {
    int leftPartSize = middle - start + 1;
    int rightPartSize = end - middle;
    int leftArray[leftPartSize];
    int rightArray[rightPartSize];

    for (int i = 0; i < leftPartSize; i++) {
        leftArray[i] = arr[start + i];
    }
    for (int i = 0; i < rightPartSize; i++) {
        rightArray[i] = arr[middle + i + 1];
    }
    
    int i = 0, j = 0, k = start;

    while (i < leftPartSize && j < rightPartSize) {
        if (leftArray[i] >= rightArray[j]) {  // Change to >= for descending order
            arr[k++] = leftArray[i++];
        } else {
            arr[k++] = rightArray[j++];
        }
    }
    while (i < leftPartSize) {
        arr[k++] = leftArray[i++];
    }
    while (j < rightPartSize) {
        arr[k++] = rightArray[j++];
    }

#ifdef _DEBUG
    printArray(arr, totalSize);
#endif
}

void mergeSort(int arr[], int start, int end, int totalSize) {
    if (start >= end) return;
    int middle = start + (end - start) / 2;
    mergeSort(arr, start, middle, totalSize);
    mergeSort(arr, middle + 1, end, totalSize);
    mergeArrays(arr, start, middle, end, totalSize);
}
