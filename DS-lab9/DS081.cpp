#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    Node* root;

public:
    BinaryTree() : root(nullptr) {}
    void insertLevelOrder(int arr[], int n);
    void inorderTraversal(Node* node);
    void printInOrder();
    Node* getRoot() { return root; }
};

void BinaryTree::insertLevelOrder(int arr[], int n) {
    if (n == 0) return;

    root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    for (int i = 1; i < n;) {
        Node* current = q.front();
        q.pop();

        if (arr[i] != 0) {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < n && arr[i] != 0) {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }
}

void BinaryTree::inorderTraversal(Node* node) {
    if (!node) return;

    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

void BinaryTree::printInOrder() {
    inorderTraversal(root);
    cout << endl;
}

int main() {
    BinaryTree tree;

    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    tree.insertLevelOrder(arr, n);
    tree.printInOrder();

    delete[] arr;
    return 0;
}
