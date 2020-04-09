#include <iostream>
#include <cassert>
#include <string>
#include <stdexcept>

using namespace std;

class Student {
    public:
        Student(string name, int grade, float gpa) : name_(name), grade_(grade), gpa_(gpa) {
            Validate();
        }
        void SetName(string name) {name_ = name;};
        void SetGrade(int grade);
        void SetGPA(float gpa);
        string GetName() const {return name_;}
        int GetGrade() const {return grade_;}
        float GetGPA() const {return gpa_;}
        bool isValidGrade(int grade) { return (grade >= 0 && grade <= 12) ? true : false;}
        bool isValidGPA(float gpa) { return (gpa >= 0.0 && gpa <= 4.0) ? true : false;}
    private:
        string name_;
        int grade_;
        float gpa_;
        void Validate() {
            if (!IsValidGrade() || !IsValidGPA()) {
                throw invalid_argument("argument out of bounds");
            }
        }
        bool IsValidGrade() { return (GetGrade() < 0 || GetGrade() > 12) ? false : true; }
        bool IsValidGPA() { return (GetGPA() < 0.0 || GetGPA() > 4.0) ? false : true;}
};

void Student::SetGrade(int grade) {
    if (Student::isValidGrade(grade)) {
        Student::grade_ = grade;
    } else {
        throw invalid_argument("grade out of bounds");
    }
}
void Student::SetGPA(float gpa) {
    if (Student::isValidGPA(gpa)) {
        Student::gpa_ = gpa;
    } else {
        throw invalid_argument("gpa out of bounds");
    }
}
int main() {
    Student st1("Sara", 12, 3.0);
    cout << st1.GetName() << ", " << st1.GetGrade() << ", " << st1.GetGPA() << endl; 
    try { 
        st1.SetGrade(10);
        st1.SetGPA(4.4);
            cout << st1.GetName() << ", " << st1.GetGrade() << ", " << st1.GetGPA() << endl; 
    } catch (const invalid_argument &ia) {
        cout << "This is the exception: " << ia.what() << endl;
    }

    return 0;
}