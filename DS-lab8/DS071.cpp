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

    for (int i = 0; i < x; i++)
    {
        cout << "[" << y[i] << "] ";
    }
    cout << endl;

    for (int i = 0; i < x - 1; i++)
    {
        int min = y[i];
        int minI;
        int temp;
        for (int j = i + 1; j < x; j++)
        {
            if (y[j] < min)
            {
                min = y[j];
                minI = j;
            }
        }
        temp = y[i];
        y[i] = min;
        y[minI] = temp;
#ifdef _DEBUG
        for (int z = 0; z < x; z++)
        {

            cout << "[" << y[z] << "] ";
        }
        cout << endl;
#endif
    }

    for (int i = 0; i < x; i++)
    {
        cout << "[" << y[i] << "] ";
    }

    return 0;
}