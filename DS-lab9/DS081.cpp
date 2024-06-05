#include <iostream>
#include <queue>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryT {
    node *root;

public:
    BinaryT();
    void insertLevelOrder(int arr[], int n);
    void inorderTraversal(node *root);
    void printInOrder();
    node* getRoot();
};

BinaryT::BinaryT() {
    root = nullptr;
}

void BinaryT::insertLevelOrder(int arr[], int n) {
    if (n == 0) return;

    root = new node(arr[0]);
    queue<node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < n) {
        node* temp = q.front();
        q.pop();

        if (i < n && arr[i] != 0) {
            temp->left = new node(arr[i]);
            q.push(temp->left);
        }
        i++;

        if (i < n && arr[i] != 0) {
            temp->right = new node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
}

void BinaryT::inorderTraversal(node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void BinaryT::printInOrder() {
    inorderTraversal(root);
    cout << endl;
}

node* BinaryT::getRoot() {
    return root;
}

int main() {
    BinaryT tree;

    int x;
    cin >> x;
    int* arr = new int[x];
    for (int i = 0; i < x; i++) {
        cin >> arr[i];
    }
    tree.insertLevelOrder(arr, x);
    tree.printInOrder();

    delete[] arr;
    return 0;
}
