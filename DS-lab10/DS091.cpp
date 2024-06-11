#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> a;
    
    int x;
    cin>>x;

    a.push_back(x);
    a.pop_back();
    cout<<a[0];
    }