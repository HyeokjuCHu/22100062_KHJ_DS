#include <iostream>
#include <vector>
#include <algorithm>
#include "sort.h"

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    int *arrA = A.data();
    int *arrB = B.data();

    quickSort(arrA, 0, N - 1);
    quickSort(arrB, 0, N - 1);

    A.assign(arrA, arrA + N);
    B.assign(arrB, arrB + N);

    int i = 0;

    while (i < K)
    {
        int maxIndex = distance(B.begin(), max_element(B.begin(), B.end()));
        int minIndex = distance(A.begin(), min_element(A.begin(), A.end()));

        if (A[minIndex] < B[maxIndex])
        {
            int temp = B[maxIndex];
            B[maxIndex] = A[minIndex];
            A[minIndex] = temp;
            i++;
        }
        else
        {
            break;
        }
    }

    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
    }

    cout << i << " " << sum << endl;

    return 0;
}
