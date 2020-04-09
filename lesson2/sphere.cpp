#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

class Sphere {
    public:
        Sphere(float radius) : radius_(radius), volume_(GetVolume()) {};
        void CalculateVolume();
        void IsValidSphereDimension();
        void SetRadius(float radius) { radius_ = radius; volume_ = GetVolume();}
        float GetRadius() {return radius_;}
        float GetVolume() {CalculateVolume(); return volume_;}
        void Print();
    private:
        float radius_;
        float volume_;
};

void Sphere::IsValidSphereDimension() {
    if (radius_ <= 0.0) {
        throw invalid_argument("invalid radius");
    } 
}
void Sphere::CalculateVolume() {
    try {
        IsValidSphereDimension();
        volume_ = M_PI*4.0/3.0*pow(radius_, 3.0);
    } catch (invalid_argument &ia) {
        cout << ia.what() << endl;
    }
}
void Sphere::Print() {
    cout << "Radius is: " << radius_ << ", Volume is: " << volume_ << endl;
}

int main() {
    Sphere sph1(30.5);
    sph1.Print();
    Sphere sph2(0.0);
    sph2.Print();
    sph2.SetRadius(10.0);
    sph2.Print();
    return 0;
}