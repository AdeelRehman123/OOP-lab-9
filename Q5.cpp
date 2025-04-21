#include <iostream>
using namespace std;

class Shape {
public:
    virtual float getArea() = 0; // Pure virtual function
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}
    float getArea() override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    float base, height;
public:
    Triangle(float b, float h) : base(b), height(h) {}
    float getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    Shape* s1 = new Rectangle(5, 3);
    Shape* s2 = new Triangle(4, 6);

    cout << "Area of Rectangle: " << s1->getArea() << endl;
    cout << "Area of Triangle: " << s2->getArea() << endl;

    delete s1;
    delete s2;
    return 0;
}
