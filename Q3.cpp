#include <iostream>
#include <string>

class Doctor;
class Billing;

class PatientRecord {
private:
    std::string name;
    std::string patientID;
    std::string dateOfBirth;
    std::string medicalHistory;
    std::string currentTreatment;
    std::string billingDetails;

public:
    PatientRecord(std::string name, std::string id, std::string dob)
        : name(name), patientID(id), dateOfBirth(dob) {}

    std::string getPublicData() const {
        return "Name: " + name + ", ID: " + patientID + ", DOB: " + dateOfBirth;
    }

private:
    // Only Doctor can access/update medical data
    std::string getMedicalData() const {
        return "Medical History: " + medicalHistory + ", Treatment: " + currentTreatment;
    }

    void updateMedicalHistory(const std::string& history) {
        medicalHistory = history;
    }

    void updateTreatment(const std::string& treatment) {
        currentTreatment = treatment;
    }

    // Only Billing can access/update billing
    void addBillingDetails(const std::string& billing) {
        billingDetails = billing;
    }

    std::string getBillingInfo() const {
        return "Billing: " + billingDetails;
    }

    friend class Doctor;
    friend class Billing;
};

// Doctor class
class Doctor {
public:
    void updatePatientRecord(PatientRecord& record, const std::string& history, const std::string& treatment) {
        record.updateMedicalHistory(history);
        record.updateTreatment(treatment);
        std::cout << "Doctor updated medical record.\n";
    }

    void viewMedicalRecord(const PatientRecord& record) {
        std::cout << "[Doctor View] " << record.getMedicalData() << "\n";
    }
};

// Billing class
class Billing {
public:
    void addBillingInfo(PatientRecord& record, const std::string& billing) {
        record.addBillingDetails(billing);
        std::cout << "Billing staff added billing info.\n";
    }

    void viewBillingInfo(const PatientRecord& record) {
        std::cout << "[Billing View] " << record.getBillingInfo() << "\n";
    }
};

// Unauthorized role
class Receptionist {
public:
    void viewPatientInfo(const PatientRecord& record) {
        std::cout << "[Receptionist View] " << record.getPublicData() << "\n";
    }

    // Receptionist has no access to medical or billing methods
};

int main() {
    PatientRecord patient("Ali Khan", "P123", "1995-08-15");

    Doctor doctor;
    doctor.updatePatientRecord(patient, "Diabetes Type 2", "Insulin Therapy");
    doctor.viewMedicalRecord(patient);

    Billing billing;
    billing.addBillingInfo(patient, "Rs. 15,000 - Due");
    billing.viewBillingInfo(patient);

    Receptionist receptionist;
    receptionist.viewPatientInfo(patient);

    // Unauthorized access examples:
    // receptionist.viewMedicalRecord(patient);  // ❌ Not allowed (no such method)
    // patient.updateMedicalHistory("...");      // ❌ Private member
    // patient.addBillingDetails("...");         // ❌ Private member

    return 0;
}
