#include <iostream>

using namespace std;

int main(){

    int height, weight;
    double bmi;

    cin>>height>>weight;
    bmi=weight/((double(height)/100)*(double(height)/100));
    
        cout<<(bmi>=25?"Yes":"No")<<endl;

    return 0;
}