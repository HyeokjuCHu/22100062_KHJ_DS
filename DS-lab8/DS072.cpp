#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    int y[x];

    for (int i = 0; i < x; i++)
    {
        cin >> y[i];
    }
#ifndef _DEBUG
    for (int i = 0; i < x; i++)
    {
        cout << "[" << y[i] << "] ";
    }
    cout << endl;
#endif

    for (int i = 0; i < x; i++)
    {
        int temp;
        for (int j = 0; j < i + 1; j++)
        {
            if (y[i] < y[j])
            {
                temp = y[i];
                y[i] = y[j];
                y[j] = temp;
            }
        }
#ifdef _DEBUG
        for (int z = 0; z < x; z++)
        {

            cout << "[" << y[z] << "] ";
        }
        cout << endl;
#endif
    }

#ifndef _DEBUG
    for (int i = 0; i < x; i++)
    {
        cout << "[" << y[i] << "] ";
    }
#endif

    return 0;
}