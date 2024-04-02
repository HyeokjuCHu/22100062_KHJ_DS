#include <iostream>
#include <string>

using namespace std;

int main(){

    string str1;

    cin>>str1;
    int sum=0;

    for(char ch:str1){
        if(ch=='I'){
            sum+=1;
        }else if(ch=='V'){
            sum+=5;
        }else if(ch=='X'){
            sum+=10;
        }else if(ch=='L'){
            sum+=50;
        }else if(ch=='C'){
            sum+=100;
        }else if(ch=='D'){
            sum+=500;
        }else if(ch=='M'){
            sum+=1000;
        }
    }

    cout<<sum<<endl;
    return 0;
}