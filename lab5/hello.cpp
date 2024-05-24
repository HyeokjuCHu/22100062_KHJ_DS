#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> hi;
    int temp;

    for(int i=0;i<5;i++){
        int x;
        cin>>x;
        hi.push_back(x);
    }

    for(int i=0;i<hi.size()-1;i++){
        for(int j=i;j<hi.size();j++){
            if(hi[i]>hi[j]){
                temp=hi[i];
                hi[i]=hi[j];
                hi[j]=temp;
            }
        }
    }
    
    for(int i=0;i<hi.size();i++){
        cout<<hi[i]<<endl;
    }

    return 0;
}
