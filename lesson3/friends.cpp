#include <iostream>
#include <string>
#include <cmath>

using namespace std;
class Square {
    public:
        Square(float side) : side_(side) {};
        friend class Rectangle;
        int Area() const;
        void Print() {
            cout << "Dim: " << side_ << ", Area: " << Area() << endl; 
        }
    private:
        float side_ = 0.0;
};

class Rectangle {
    public:
        Rectangle(const Square& square);
        Rectangle(const float& width, const float& height) : width_(width), height_(height) {};
        int Area() const;
        void Print() {
            cout << "Dim1: " << width_ << ", Dim2: " << height_ << ", Area: " << Area() << endl; 
        }
    private:
        float width_ = 0.0;
        float height_ = 0.0;
};

int Square::Area() const {
    return pow(side_, 2.0);
}
Rectangle::Rectangle(const Square& square) : width_(square.side_), height_(square.side_) {}
int Rectangle::Area() const {
    return width_ * height_;
}
int main() {
    Square geo1(10.0);
    Rectangle geo2(10,20);
    geo1.Print();
    geo2.Print();   
    return 0;
}