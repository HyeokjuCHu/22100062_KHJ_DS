#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct person{
    string subject;
    int credit;
    int marks;
    string grade;
};

double calculateGradePoint(string grade) {
    if (grade == "A+") return 4.5;
    else if (grade == "A") return 4.0;
    else if (grade == "B+") return 3.5;
    else if (grade == "B") return 3.0;
    else if (grade == "C+") return 2.5;
    else if (grade == "C") return 2.0;
    else if (grade == "D+") return 1.5;
    else if (grade == "D") return 1.0;
    else return 0.0;
}


int main(){
    person p1[3];
    
    for(int i=0;i<3;i++){
        cin>>p1[i].subject>>p1[i].credit>>p1[i].marks;
        if (p1[i].marks >= 95)
            p1[i].grade = "A+";
        else if (p1[i].marks >= 90)
            p1[i].grade = "A";
        else if (p1[i].marks >= 85)
            p1[i].grade = "B+";
        else if (p1[i].marks >= 80)
            p1[i].grade = "B";
        else if (p1[i].marks >= 75)
            p1[i].grade = "C+";
        else if (p1[i].marks >= 70)
            p1[i].grade = "C";
        else if (p1[i].marks >= 65)
            p1[i].grade = "D+";
        else if (p1[i].marks >= 60)
            p1[i].grade = "D";
        else
            p1[i].grade = "F";
    }

    int cSum=0;
    double gSum=0.0;
    for(int i=0;i<3;i++){
        cout<<p1[i].subject<<"("<<p1[i].credit<<")\t"<<p1[i].grade<<" "<<calculateGradePoint(p1[i].grade)<<endl;
        cSum+=p1[i].credit;
        gSum+=calculateGradePoint(p1[i].grade)*p1[i].credit;
    }
    cout.precision(2);
    cout<<"Total Credits "<<cSum<<", GPA "<<fixed<<gSum/double(cSum)<<endl;

    return 0;
}