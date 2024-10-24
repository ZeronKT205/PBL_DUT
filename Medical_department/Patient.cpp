#pragma once
#include "Patient.h"
using namespace std;
// Constructor
Patient::Patient(const string& name, const string& dateOfBirth, const string& gender, const string& address, const string& phoneNumber,const string& username, const string& password, int id) : Person(name,dateOfBirth,gender,address,phoneNumber),User(username, password, id) {}


//Them cuoc hen moi
void Patient::addAppointment(const Appointment& appointment) {
    appointments.addLast(appointment);
}

//Huy cuoc hen dua tren ngay hen

void Patient::cancelAppointment(const string& date,const int& appointment_ID) {
    if (appointments.empty()) {
        cout << "No appointment found on " << endl;
        return;
    }
    bool found = false;
    for (int i = 0; i < appointments.length(); i++) {
        if (appointments.get(i).getDate() == date&& appointments.get(i).getAppointment_ID() == appointment_ID) {
            appointments.removeAtIndex(i);
            cout << "Appointment on " << date << " has been cancelled." << endl;
        }
    }
}

//Hien thi danh sách cuộc hẹn 
void Patient::viewAppointments() {
    if (appointments.empty()) {
        cout << "No appointment found on " << endl;
        return;
    }
    for (int i = 0; i < appointments.length(); i++) {
        cout << "Appointment on " << appointments.get(i).getDate() << " at " << appointments.get(i).getTime() << " with Dr. " << appointments.get(i).getDoctorName() << " in room " << appointments.get(i).getClinicRoom() << endl;
    }
}

// Thêm lịch sử y tế mới
void Patient::addMedicalRecord(const string& record) {
    medicalHistory.addLast(record);
}


// Hiển thị lịch sử y tế
void Patient::viewMedicalHistory() {
    if (medicalHistory.empty()) {
        cout << "No medical history available." << endl;
        return;
    }
    cout<< "Medical history:" << endl;
    for (int i = 0; i < medicalHistory.length(); i++) {
        cout << "- " << medicalHistory.get(i) << endl;
    }
}
