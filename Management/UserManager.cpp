#include "UserManager.h"
using namespace std;
// Constructor
UserManager::UserManager() {}

// Thêm bác sĩ
void UserManager::addDoctor(const Doctor& doctor) {
    doctors.addLast(doctor);
    cout << "Doctor added successfully." << endl;
}

// Xóa bác sĩ
void UserManager::removeDoctor(const string& username, const int& ID) {
    for (int i = 0; i < doctors.length(); i++) {
        if (doctors.get(i).getUsername() == username && doctors.get(i).getID() == ID) {
            doctors.removeAtIndex(i);
            cout << "Doctor removed successfully." << std::endl;
            return;
        }
    }
    cout << "Doctor not found." << std::endl;
}

// Tìm bác sĩ theo ID
Doctor* UserManager::findDoctorByID(int doctorID) {
    for (int i = 0; i < doctors.length(); i++) {
        Doctor &doctor = doctors.get(i);
        if (doctor.getID() == doctorID) {
            return &doctor;
        }
    }
    cout << "Doctor with " << doctorID << " not found" << endl;
    return nullptr;
}

// Tìm bác sĩ theo tên người dùng
LinkedList<Doctor> UserManager::findDoctorByUsername(const string& username) {
    LinkedList<Doctor> matchingDoctors;
    for (int i = 0; i < doctors.length(); i++) {
        Doctor& doctor = doctors.get(i);
        if (doctor.getUsername() == username) {
            matchingDoctors.addLast(doctor);
        }
    }
    if (matchingDoctors.empty()) {
        cout << "No doctors found with username: " << username << endl;
    }
    return matchingDoctors; // Trả về linked list gồm danh sách các bác sĩ có tên username
}

// Hiển thị danh sách bác sĩ
void UserManager::displayDoctors() const {
    if (doctors.empty()) {
        cout << "No doctors available." << endl;
        return;
    }
    for (int i = 0; i < doctors.length(); i++) {
        const Doctor& doctor = doctors.get(i);
        cout << "Doctor ID: " << doctor.getID() << ", Name: " << doctor.getName() << endl;
    }
}

// Thêm bệnh nhân
void UserManager::addPatient(const Patient& patient) {
    patients.addLast(patient);
    cout << "Patient added successfully." << endl;
}

// Xóa bệnh nhân
void UserManager::removePatient(const string& username, const int& ID) {
    for (int i = 0; i < patients.length(); i++) {
        if (patients.get(i).getUsername() == username && patients.get(i).getID()) {
            patients.removeAtIndex(i);
            cout << "Patient removed successfully." << endl;
            return;
        }
    }
    cout << "Patient not found." << std::endl;
}

// Tìm bệnh nhân theo ID
Patient* UserManager::findPatientByID(int patientID) {
    for (int i = 0; i < patients.length(); i++) {
        if (patients.get(i).getID() == patientID) {
            Patient &patient = patients.get(i);
            return &patient;
        }
    }
    return nullptr;
}

// Tìm bệnh nhân theo tên người dùng
LinkedList<Patient> UserManager::findPatientByUsername(const std::string& username) {
    LinkedList <Patient> matchingPatients;
    for (int i = 0; i < patients.length(); i++) {
        if (patients.get(i).getUsername() == username) {
            matchingPatients.addLast(patients.get(i));
        }
    }
    if (matchingPatients.empty()) {
        cout << "No patients found with username: " << username << endl;
    }
    return matchingPatients;
}

// Hiển thị danh sách bệnh nhân
void UserManager::displayPatients() const {
    if (patients.empty()) {
        cout << "No patients available." << endl;
        return;
    }
    for (int i = 0; i < patients.length(); i++) {
        const Patient& patient = patients.get(i);
        cout << "Patient ID: " << patient.getID() << ", Name: " << patient.getName() << endl;
    }
}

// Cập nhật thông tin bác sĩ
void UserManager::updateDoctorInfo(int doctorID, const Doctor& newDoctorInfo) {
    Doctor* doctor = findDoctorByID(doctorID);
    if (doctor != nullptr) {
        *doctor = newDoctorInfo;
        cout << "Doctor information updated successfully." << endl;
    }
    else {
        cout << "Doctor not found." << endl;
    }
}

// Cập nhật thông tin bệnh nhân
void UserManager::updatePatientInfo(int patientID, const Patient& newPatientInfo) {
    Patient* patient = findPatientByID(patientID);
    if (patient != nullptr) {
        *patient = newPatientInfo;
        cout << "Patient information updated successfully." << endl;
    }
    else {
        cout << "Patient not found." << endl;
    }
}
