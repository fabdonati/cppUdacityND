// weak pointer do not increase the count number
#include <iostream>
#include <string>
#include <memory>

using namespace std;
int main() {
    shared_ptr<int> mySharedPtr(new int);
    cout << "shared pointer count = " << mySharedPtr.use_count() << endl;
    weak_ptr<int> myWeakPtr1(mySharedPtr);
    weak_ptr<int> myWeakPtr2(myWeakPtr1);
    cout << "shared pointer count = " << mySharedPtr.use_count() << endl; 
    return 0;
}