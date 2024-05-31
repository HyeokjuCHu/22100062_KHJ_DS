#include <iostream>
using namespace std;

void swapValues(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void displayArray(int *array, int length) {
    for(int i = 0; i < length; i++)
        cout << "[" << array[i] << "] ";
    cout << endl;
}

void mergeArrays(int *array, int start, int middle, int end, int totalSize) {
    #ifdef _DEBUG
        displayArray(array, totalSize);
    #endif
    
    int leftPartSize = middle - start + 1;
    int rightPartSize = end - middle;
    int leftArray[leftPartSize];
    int rightArray[rightPartSize];

    for(int i = 0; i < leftPartSize; i++) {
        leftArray[i] = array[start + i];
    }
    for(int i = 0; i < rightPartSize; i++) {
        rightArray[i] = array[middle + i + 1];
    }
    
    int i = 0, j = 0, k = start;

    while (i < leftPartSize && j < rightPartSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++];
        } else {
            array[k++] = rightArray[j++];
        }
    }
    while (i < leftPartSize) {
        array[k++] = leftArray[i++];
    }
    while (j < rightPartSize) {
        array[k++] = rightArray[j++];
    }
}

void mergeSort(int *array, int start, int end, int totalSize) {
    if(start >= end) return;
    int middle = start + (end - start) / 2;
    mergeSort(array, start, middle, totalSize);
    mergeSort(array, middle + 1, end, totalSize);
    mergeArrays(array, start, middle, end, totalSize);
}

int main() {
    int length = 0;
    cin >> length;
    int array[length];
    
    for(int i = 0; i < length; i++) {
        cin >> array[i];
    }
    mergeSort(array, 0, length - 1, length);
    displayArray(array, length);

    return 0;
}
