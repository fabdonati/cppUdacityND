#include <iostream>
#include <cmath>

#define PI M_PI

using namespace std;

class LineSegment {
    public:
        double length;
};

class Circle {
    public:
        Circle(LineSegment& radius);
        double Area();
    private:
        LineSegment& radius_;
};

Circle::Circle(LineSegment& radius) : radius_(radius){};
double Circle::Area() {
    return pow(Circle::radius_.length, 2.0) * PI;
}

int main() {
    LineSegment radius{3};
    Circle circle(radius);
    cout << circle.Area() << endl;
    return 0;
}