#include <iostream>


using namespace std;

class Student {
private:
    string name;
    int lcScore;
    int rcScore;

public:
    // 기본 생성자
    Student() : name(""), lcScore(0), rcScore(0) {}

    // 입력받는 생성자
    Student(const string& name) : name(name), lcScore(0), rcScore(0) {}

    // 멤버변수 parameter가 있는 생성자
    Student(const string& name, int lcScore, int rcScore) : name(name) {
        setLCScore(lcScore);
        setRCScore(rcScore);
    }

    // LC, RC 점수 유효성 체크 함수
    bool isValidScore(int score) const {
        return (score >= 0 && score <= 495);
    }

    // 점수 입력 메소드
    int inputScore(const string& subject) const {
        int score;
        do { 
            cout <<subject << "> ";
            cin >> score;
        } while (!isValidScore(score));
        return score;
    }

    void setLCScore(int score) {
        lcScore = isValidScore(score) ? score : 0;
    }

    void setRCScore(int score) {
        rcScore = isValidScore(score) ? score : 0;
    }

    // Pass, Fail 출력 메소드
    string passOrFail(int score) const {
        return (score >= 350) ? "Pass" : "Fail";
    }

    // 결과 출력 메소드
    void displayResult() const {
        cout << "[" << name << "]" << endl;
        cout << "LC - " << lcScore << " " << passOrFail(lcScore) << endl;
        cout << "RC - " << rcScore << " " << passOrFail(rcScore) << endl;
        cout << "Total - " << (lcScore + rcScore) << endl;
    }
};

int main() {
    string name;
    int lcScore, rcScore;
    getline(cin, name);

    // 점수 입력
    Student student(name);
    lcScore = student.inputScore("LC");
    rcScore = student.inputScore("RC");

    // 학생 객체 설정
    student.setLCScore(lcScore);
    student.setRCScore(rcScore);

    // 결과 출력
    student.displayResult();

    return 0;
}
