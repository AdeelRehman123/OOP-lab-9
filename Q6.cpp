#include <iostream>
using namespace std;

class Car {
protected:
    string model;
    float price;
public:
    Car(string m) : model(m), price(0.0f) {}
    virtual void setPrice(float p) = 0;
    string getModel() const { return model; }
    float getPrice() const { return price; }
};

class Color : public Car {
private:
    string color;
public:
    Color(string m, string c) : Car(m), color(c) {}
    void setPrice(float p) override {
        price = p + 1000; // Additional cost for color
    }
    void display() {
        cout << "Model: " << model << ", Color: " << color << ", Price: $" << price << endl;
    }
};

class Company : public Car {
private:
    string company;
public:
    Company(string m, string comp) : Car(m), company(comp) {}
    void setPrice(float p) override {
        price = p + 2000; // Additional cost for brand value
    }
    void display() {
        cout << "Model: " << model << ", Company: " << company << ", Price: $" << price << endl;
    }
};

int main() {
    Color c1("Model X", "Red");
    c1.setPrice(30000);
    c1.display();

    Company c2("Model Y", "Toyota");
    c2.setPrice(25000);
    c2.display();

    return 0;
}
