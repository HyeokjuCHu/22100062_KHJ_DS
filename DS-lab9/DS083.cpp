#include <iostream>

using namespace std;

const int MAX_SIZE = 20;  // Define the maximum size of the heap

int heap[MAX_SIZE];
int heapSize = 0;  // Initially, the heap is empty

void insertI(int value) {
    if (heapSize >= MAX_SIZE) {
        cout << "Heap overflow!" << endl;
        return;
    }
    // Insert the new value at the end of the heap
    int index = heapSize;
    heap[heapSize++] = value;

    // Bubble up to maintain the heap property
    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(heap[(index - 1) / 2], heap[index]);
        index = (index - 1) / 2;
    }
}

void maxheapify(int rootindex) {
    int largest = rootindex;
    int leftChild = 2 * rootindex + 1;
    int rightChild = 2 * rootindex + 2;

    // Check if left child is larger than root
    if (leftChild < heapSize && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    // Check if right child is larger than largest so far
    if (rightChild < heapSize && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != rootindex) {
        swap(heap[rootindex], heap[largest]);
        maxheapify(largest);
    }
}

void deleteI() {
    if (heapSize <= 0) {
        cout << "Heap underflow!" << endl;
        return;
    }
    // Replace the root of the heap with the last element
    cout<<"Delete "<<heap[0]<<endl;
    heap[0] = heap[--heapSize];
    // Heapify to maintain the heap property
    maxheapify(0);
}

void printHeap() {
    cout << "==> Heap: ";
    for (int i = 0; i < heapSize; ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    while (1) {
        cout << "1.insert 2.delete 3.print 4.quit > ";
        int x;
        cin >> x;
        if (x == 1) {
            cout << "new value? ";
            int y;
            cin >> y;
            insertI(y);
            printHeap();
        } else if (x == 2) {
            deleteI();
            printHeap();
        } else if (x == 3) {
            printHeap();
        } else {
            break;
        }
    }
    cout << "Bye!" << endl;
    return 0;
}
