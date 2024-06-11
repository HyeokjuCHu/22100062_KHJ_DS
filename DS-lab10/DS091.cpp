#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int arr[5]={1,5,4,3,6};
    priority_queue<int> x;

    cout<<"Init: ";
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=4;i>=0;i--){
        x.push(arr[i]);
    }

    cout<<"Priority Queue: ";
    while(!x.empty()){
        cout<<x.top()<<' ';
        x.pop();
    }
    for(int i=0;i<5;i++){
        cout<<endl;
    }
}