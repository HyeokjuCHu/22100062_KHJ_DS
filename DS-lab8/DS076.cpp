#include <iostream>
#include "sort.h"

using namespace std;

void displayMenu() {
    cout << "Choose a sorting algorithm:" << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Bubble Sort (Ascending)" << endl;
    cout << "4. Bubble Sort (Descending)" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "6. Merge Sort" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int x;
    cout << "Enter the number of elements: ";
    cin >> x;
    int arr[x];

    cout << "Enter the elements: ";
    for (int i = 0; i < x; i++) {
        cin >> arr[i];
    }

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        if (choice == 7) {
            break; // Exit the loop
        }

        // Create a copy of the array to sort
        int arrCopy[x];
        for (int i = 0; i < x; i++) {
            arrCopy[i] = arr[i];
        }

        switch (choice) {
            case 1:
                selectionSort(arrCopy, x);
                break;
            case 2:
                insertionSort(arrCopy, x);
                break;
            case 3:
                bubbleSortAsc(arrCopy, x);
                break;
            case 4:
                bubbleSortDesc(arrCopy, x);
                break;
            case 5:
                quickSort(arrCopy, 0, x - 1);
                break;
            case 6:
                mergeSort(arrCopy, 0, x - 1, x);
                break;
            default:
                cout << "Invalid choice" << endl;
                continue;
        }

        cout << "Sorted array: ";
        printArray(arrCopy, x);
    }

    cout << "Exiting the program." << endl;

    return 0;
}
