#include <iostream>
#include <stdlib.h>

class MyInt {
    int *_p;
public: 
    MyInt(int *p = NULL) {_p = p;}
    ~MyInt() {
        std::cout << "Resource " << *_p << " deallocated" << std::endl;
        delete _p;
    }
    int &operator*() {return *_p;}
};

int main() {
    double den[] = {1.0, 2.0, 3.0, 4.0};
    for (size_t i = 0; i < 4; ++i) {
        //double *en = new double(i);
        MyInt en(new int(i));
        std::cout << *en << "/" << den[i] << " = " << *en/den[i] << std::endl;

        //delete en;
    }
    return 0;
}