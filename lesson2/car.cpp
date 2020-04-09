#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Car {
    public:
        Car(string brand, int hp, int w) : horsepower_(hp), weight_(w) {SetBrand(brand);}
        void SetHorsePower(int horsepower){horsepower_ = horsepower;}
        void SetWeight(int weight){weight_ = weight;}
        void SetBrand(string brand);
        int GetHorsePower() const {return horsepower_;} 
        int GetWeight() const {return weight_;}
        char* GetBrand() const {return brand_;}

    private:
        int horsepower_{0};
        int weight_{0};
        char* brand_{nullptr};
};

void Car::SetBrand(string brand) {
    Car::brand_ = new char[brand.size() + 1];
    strcpy(brand_, brand.c_str());
}

int main() {
    Car fabrizioCar("mercedes", 143, 2000);
    cout << fabrizioCar.GetBrand() << ", " << fabrizioCar.GetHorsePower() << ", " << fabrizioCar.GetWeight() << endl;
    return 0;
}