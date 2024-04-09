#include <iostream>

using namespace std;

int main(){
    int a;
    cin>>a;
    int *x=new int[a];
    int sum=0;
    int iMax=0;
    for(int i=0;i<a;i++){
        int n;
        cin>>n;
        x[i]=n;
        sum+=n;
        if(n>iMax)iMax=n;
    }

    cout<<sum<<" "<<iMax<<endl;
    return 0;
}