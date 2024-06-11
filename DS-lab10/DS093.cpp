#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int N;
    cin >> N;
    vector<string> wlist;

    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        wlist.push_back(word);
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {

            if (wlist[i].length() > wlist[j].length())
            {
                string temp;
                temp = wlist[i];
                wlist[i] = wlist[j];
                wlist[j] = temp;
            }
            else if (wlist[i].length() == wlist[j].length())
            {
                if (wlist[i] > wlist[j])
                {
                    string temp;
                    temp = wlist[i];
                    wlist[i] = wlist[j];
                    wlist[j] = temp;
                }
            }
        }
    }

    wlist.erase(unique(wlist.begin(),wlist.end()),wlist.end());
    for(int i=0;i<N;i++){
        cout<<wlist[i]<<endl;
    }

    return 0;
}