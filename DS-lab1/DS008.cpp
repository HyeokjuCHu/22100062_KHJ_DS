#include <iostream>
#include <string>

using namespace std;

int main(){

    string str1;

    cin>>str1;
    int sum=0;
    char prev = '\0'; // Initialize prev with null character

    for(char ch:str1){
        if(ch=='I'){
            sum+=1;
        }else if(ch=='V'){
            if (prev == 'I')
                sum += 3;
            else
                sum+=5;
        }else if(ch=='X'){
            if (prev == 'I')
                sum += 8;
            else if (prev == 'V')
                sum += 30;
            else
                sum+=10;
        }else if(ch=='L'){
            if (prev == 'X')
                sum += 30;
            else
                sum+=50;
        }else if(ch=='C'){
            if (prev == 'X')
                sum += 80;
            else if (prev == 'L')
                sum += 300;
            else
                sum+=100;
        }else if(ch=='D'){
            if (prev == 'C')
                sum += 300;
            else
                sum+=500;
        }else if(ch=='M'){
            if (prev == 'C')
                sum += 800;
            else
                sum+=1000;
        }
        prev = ch;
    }

    cout<<sum<<endl;
    return 0;
}
