#include <iostream>

using namespace std;

void asc_o(int *arr, int n)
{
    cout << "=== ascending order ===" << endl;
#ifdef _DEBUG
    for (int z = 0; z < n; z++)
    {
        cout << "[" << arr[z] << "] ";
    }
    cout << endl;
#endif

    for (int i = 0; i < n - 1; i++)
    {
        int temp;
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
#ifdef _DEBUG
        for (int z = 0; z < n; z++)
        {
            cout << "[" << arr[z] << "] ";
        }
        cout << endl;
#endif
    }
#ifndef _DEBUG
    for (int i = 0; i < n; i++)
    {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
#endif
}

void des_o(int *arr, int n)
{
    cout << "=== descending order ===" << endl;
#ifdef _DEBUG
    for (int z = 0; z < n; z++)
    {
        cout << "[" << arr[z] << "] ";
    }
    cout << endl;
#endif
    for (int i = 0; i < n - 1; i++)
    {
        int temp;
        for (int j = i; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
#ifdef _DEBUG
        for (int z = 0; z < n; z++)
        {
            cout << "[" << arr[z] << "] ";
        }
        cout << endl;
#endif
    }
#ifndef _DEBUG
    for (int i = 0; i < n; i++)
    {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
#endif
}

int main()
{
    int x;
    cin >> x;
    int arr[x];

    for (int i = 0; i < x; i++)
    {
        cin >> arr[i];
    }
#ifndef _DEBUG
    for (int i = 0; i < x; i++)
    {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
#endif

    asc_o(arr, x);
    des_o(arr, x);

    return 0;
}