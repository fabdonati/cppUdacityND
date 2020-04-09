#include <iostream>
#include <string>

using namespace std;

class Pyramid {
    public:
        Pyramid(int length, int width, int height) : length_(length), width_(width), height_(height){
            CalculateVolume();
        };
        int GetLength() const {return length_;}
        int GetWidth() const {return width_;}
        int GetHeight() const {return height_;}
        float GetVolume() const {return volume_;}
        void CalculateVolume();
        void SetLength(int length) {}
        void SetWidth(int width) {}
        void SetHeight(int height) {}
    private:
        int length_;
        int width_;
        int height_;
        float volume_;
};

void Pyramid::CalculateVolume() {
    if (Pyramid::height_ == 0.0 ||
        Pyramid::width_  == 0.0 ||
        Pyramid::length_ == 0.0)
    {
        cout << "One of the dimensions is 0, pyramid not defined!" << endl;
    } else {
        Pyramid::volume_ = static_cast<float>(height_ * width_ * length_ / 3);
    }
}

int main() {
    Pyramid pyr1(1,3,5);
    Pyramid pyr2(1,3,0);

    cout << "pyr1 has volume: " << pyr1.GetVolume() << endl;
    cout << "pyr2 has volume: " << pyr2.GetVolume() << endl;

}