#include <iostream>

using namespace std;

struct st_score{
    int kor,eng,math;
    int total;
    double average;  
};

int main(){
    st_score student;
    cin>>student.kor>>student.eng>>student.math;
    student.total=student.kor+student.eng+student.math;
    student.average=double(student.total)/3;
    cout.precision(1);

    cout<<student.total<<" "<<fixed<<student.average<<endl;

    if(student.kor>=70){
        cout<<"Korean - Pass"<<endl;
    }else{
        cout<<"Korean - Fail"<<endl;
        }

    if(student.eng>=70){
        cout<<"English - Pass"<<endl;
    }else{
        cout<<"English - Fail"<<endl;
        }

    if(student.math>=70){
        cout<<"Math - Pass"<<endl;
    }else{
        cout<<"Math - Fail"<<endl;
        }

    return 0;
}