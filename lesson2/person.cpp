#include <cassert>
#include <iostream>
using namespace std;

class Date {
    public:
        Date(int d, int m, int y) { day = d; month = m; year = y;}
        void Print() {
            cout << "Date (dd/mm/yyyy) is: " << day << "/" << month << "/" << year << endl;
        }
        int Day() { return day; }
        void Day(int d) { 
            if (d>=1 && d<=31) {
                day = d; }
            }
        int Month() { return month; }
        void Month(int m) {
            if (m>=1 && m<=12) {
                month = m; }
        }

    private:
        int day{1};
        int month{1};
        int year{0};
};


class Birthday {
    public:
        Birthday(int d, int m, int y);
        void Print() {
            cout << "Date (dd/mm/yyyy) is: " << day << "/" << month << "/" << year << endl;
        }
        int Day() { return day; }
        int Month() { return month; }
        int Year() { return year; }

    private:
        int const day; // only with initialized list
        int const month;
        int const year;
};

Birthday::Birthday(int d, int m, int y) : day(d), month(m), year(y) {}

class Person {
    public:
        // Person(string p) { Name(p);}
        Person(string p) : name(p){}
        string Name() { return name;}  
        //void Name(string n) { name = n;}
    private:
        const string name{0};

};

int main() {
    Date date(24,9,1985);
    date.Print();
    Person p1("Sara");
    cout << p1.Name() << endl;
    return 0;
}