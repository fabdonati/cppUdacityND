#include <iostream>
#include <string>

using namespace std;
class Animal {
    public: 
        string color{"brown"};
        string name{"ciccio"};
        int age{0};
};

class Tiger : public Animal {
    public: 
        float length{0.0};
        void MakeSound() { cout << "Roarrrr" << endl;}
};

class Cat : public Animal {
    public:
        float height{0.0};
        void MakeSound() { cout << "Meowww" << endl;}
};

int main() {
    Cat cat;
    cat.MakeSound();
    Tiger tig;
    tig.MakeSound();
    return 0;
}