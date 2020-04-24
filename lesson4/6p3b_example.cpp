#include <iostream>
#include <memory>
#include <string>

using namespace std;

class MyClass {
    string _text;
public:
    MyClass(){};
    MyClass(string text) {_text = text;}
    ~MyClass() {cout << _text << " destroyed" << endl;}
    void SetText(string text) {_text = text;}
};

int main() {
    unique_ptr<MyClass> MyClass1(new MyClass());
    unique_ptr<MyClass> MyClass2(new MyClass("String 2"));

    MyClass1->SetText("String 1");
    //*MyClass1 = *MyClass2;

    cout << "Objects have stack addresses " << MyClass1.get() << " and " << MyClass2.get() << endl;
    return 0;
}