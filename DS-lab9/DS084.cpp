#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 30;  // Define the maximum size of the heap

class MinHeap {
private:
    int arr[MAX_SIZE];
    int length;

    void minHeapifyUp(int index) {
        if (index && arr[index] < arr[(index - 1) / 2]) {
            swap(arr[index], arr[(index - 1) / 2]);
            minHeapifyUp((index - 1) / 2);
        }
    }

    void minHeapifyDown(int index) {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < length && arr[leftChild] < arr[smallest])
            smallest = leftChild;

        if (rightChild < length && arr[rightChild] < arr[smallest])
            smallest = rightChild;

        if (smallest != index) {
            swap(arr[index], arr[smallest]);
            minHeapifyDown(smallest);
        }
    }

public:
    MinHeap() : length(0) {}

    ~MinHeap() {}

    void insert(int value) {
        if (length >= MAX_SIZE) {
            cout << "Heap overflow!" << endl;
            return;
        }
        arr[length] = value;
        minHeapifyUp(length);
        length++;
    }

    int deleteMin() {
        if (length == 0) {
            cout << "Heap underflow!" << endl;
            return -1;
        }
        int rootValue = arr[0];
        arr[0] = arr[--length];
        minHeapifyDown(0);
        return rootValue;
    }

    int peek() const {
        if (length == 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return arr[0];
    }

    int size() const {
        return length;
    }

    bool isEmpty() const {
        return length == 0;
    }

    void printHeap() const {
        cout << "==> Heap: ";
        for (int i = 0; i < length; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap;
    while (true) {
        cout << "1.insert 2.delete 3.print 4.peek 5.size 6.isEmpty 7.quit > ";
        int x;
        cin >> x;
        if (x == 1) {
            cout << "new value? ";
            int y;
            cin >> y;
            heap.insert(y);
            heap.printHeap();
        } else if (x == 2) {
            int deletedValue = heap.deleteMin();
            if (deletedValue != -1)
                cout << "Deleted " << deletedValue << endl;
            heap.printHeap();
        } else if (x == 3) {
            heap.printHeap();
        } else if (x == 4) {
            cout << "Peek value: " << heap.peek() << endl;
        } else if (x == 5) {
            cout << "Heap size: " << heap.size() << endl;
        } else if (x == 6) {
            cout << "Heap is " << (heap.isEmpty() ? "empty" : "not empty") << endl;
        } else {
            break;
        }
    }
    cout << "Bye!" << endl;
    return 0;
}
