#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    priority_queue<int> maxHeap;
    int x, K;
    cin >> x >> K;

    for (int i = 0; i < x; i++)
    {
        int y;
        cin >> y;
        maxHeap.push(y);
    }

    int z;
    for (int i = 0; i < K; i++)
    {
        z = maxHeap.top();
        maxHeap.pop();
    }

    cout << z << endl;

    return 0;
}
