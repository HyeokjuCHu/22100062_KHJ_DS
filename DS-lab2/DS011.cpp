#include <iostream>

using namespace std;

int add(int size, int *x){
    int sum=0;
    for(int i=0;i<size;i++){
        int n;
        cin>>n;
        x[i]=n;
        sum+=n;
    }
    return sum;
}

int Max(int size, int *x){
    int iMax=0;
    for(int i=0;i<size;i++){
        if(x[i]>iMax){
            iMax=x[i];
        }

    }
    return iMax;
}

int main(){
    int a;
    cin>>a;
    int *x=new int[a];
    cout<<add(a,x)<<" "<<Max(a,x)<<endl;
    return 0;
}

//for(int one:arr)
//g++ -std=c++11 DS011.cpp