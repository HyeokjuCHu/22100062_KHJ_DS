#include <iostream>
#include <vector>
#include <algorithm>
#include "sort.h"

using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int *arrA = A.data();
    quickSort(arrA, 0, N - 1);
    A.assign(arrA, arrA + N);

    cout<<A[K-1]<<endl;

    return 0;
}