#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Student {
public:
    virtual double getTuition(const string& status, int creditHours) const = 0;
    virtual ~Student() {} // virtual destructor
};

// Derived class
class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    // Setter and Getter for research topic
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    // Override getTuition()
    double getTuition(const string& status, int creditHours) const override {
        double rate = 0.0;
        if (status == "undergraduate") {
            rate = 200.0;
        } else if (status == "graduate") {
            rate = 300.0;
        } else if (status == "doctoral") {
            rate = 400.0;
        } else {
            cout << "Invalid status. Tuition set to $0.\n";
            return 0.0;
        }
        return creditHours * rate;
    }
};

int main() {
    GraduateStudent gs;

    // Set research topic
    gs.setResearchTopic("Artificial Intelligence in Healthcare");

    // Display info
    cout << "Research Topic: " << gs.getResearchTopic() << endl;

    // Tuition calculations
    string status;
    int creditHours;

    cout << "Enter student status (undergraduate / graduate / doctoral): ";
    cin >> status;
    cout << "Enter number of credit hours: ";
    cin >> creditHours;

    double tuition = gs.getTuition(status, creditHours);
    cout << "Total Tuition: $" << tuition << endl;

    return 0;
}
