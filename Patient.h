#pragma once
#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
#include "Appointment.h"
#include "Linked_List.cpp"
#include "User.h"  // Giả sử Patient kế thừa từ lớp User

using namespace std;

class Patient : public User,public Person {
private:
    LinkedList<Appointment> appointments;   // Danh sách các cuộc hẹn của bệnh nhân
    LinkedList<string> medicalHistory;      // Lịch sử y tế của bệnh nhân

public:
    // Constructor
    Patient(const string& name, const string& dateOfBirth, const string& gender, const string& address, const string& phoneNumber,const string& username, const string& password, int id);

    // Quản lý cuộc hẹn
    void addAppointment(const Appointment& appointment);
    void cancelAppointment(const string& date,const int& appointment_ID);
    void viewAppointments();

    // Quản lý lịch sử y tế
    void addMedicalRecord(const string& record);
    void viewMedicalHistory();
};
#endif 

