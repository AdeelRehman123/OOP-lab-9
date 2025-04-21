#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int id;
public:
    virtual void getData() {
        cout << "Enter name: "; cin >> name;
        cout << "Enter ID: "; cin >> id;
    }
    virtual void displayData() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
    virtual void bonus() = 0; // pure virtual
};

class Admin : virtual public Person {
protected:
    float salary;
public:
    void getData() override {
        Person::getData();
        cout << "Enter admin salary: "; cin >> salary;
    }
    void displayData() override {
        Person::displayData();
        cout << "Admin Salary: " << salary << endl;
    }
    void bonus() override {
        cout << "Admin Bonus: " << salary * 0.10 << endl;
    }
};

class Account : virtual public Person {
protected:
    float salary;
public:
    void getData() override {
        Person::getData();
        cout << "Enter account salary: "; cin >> salary;
    }
    void displayData() override {
        Person::displayData();
        cout << "Account Salary: " << salary << endl;
    }
    void bonus() override {
        cout << "Account Bonus: " << salary * 0.08 << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        Admin::getData(); // call one to avoid ambiguity
    }
    void displayData() override {
        Admin::displayData();
    }
    void bonus() override {
        float avgSalary = (Admin::salary + Account::salary) / 2;
        cout << "Master Bonus: " << avgSalary * 0.12 << endl;
    }
};

int main() {
    Person* p;

    Master m;
    p = &m;

    p->getData();
    p->displayData();
    p->bonus();

    return 0;
}
