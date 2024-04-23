#include <iostream>

using namespace std;

class Student
{
private:
    double getAvg() const;

public:
    string name;
    string sid;
    int *score;
    void print() const;

};

double Student::getAvg() const
{
    int add = 0;

    for (int i = 0; i < 3; i++)
    {
        add += score[i];
    }

    return static_cast<double>(add) / 3.0;
}

void Student::print() const
{
    cout << "[" << sid << "] " << name << endl;
    cout.precision(1);
    cout << "The Average score is " << fixed << getAvg();
}

int main()
{
    Student st;
    st.score = new int[3];

    cin >> st.sid >> st.score[0] >> st.score[1] >> st.score[2];
    cin.ignore();

    getline(cin, st.name);

    st.print();
    delete[] st.score;
    return 0;
}
