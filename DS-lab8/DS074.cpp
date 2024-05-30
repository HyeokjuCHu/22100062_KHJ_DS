#include <iostream>
using namespace std;

void print_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[" << a[i] << "] ";
    }
    cout << endl;
}

void quick_sort(int a[], int left, int right)
{
    if (left >= right)
        return;

    int pivot = a[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[right]);
#ifdef _DEBUG
    print_array(a, right + 1);
#endif

    quick_sort(a, left, i);
    quick_sort(a, i + 2, right);
}

int main()
{
    int x;
    cin >> x;
    int y[x];

    for (int i = 0; i < x; i++)
    {
        cin >> y[i];
    }

    print_array(y, x);

    quick_sort(y, 0, x - 1);
#ifndef _DEBUG
    print_array(y, x);
#endif

    return 0;
}
