#pragma once
#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <iostream>
#include <string>
#include "Linked_List.cpp"
#include "Doctor.h"
#include "Patient.h"
using namespace std;

class UserManager {
private:
    LinkedList<Doctor> doctors; 
    LinkedList<Patient> patients;

public:
    // Constructor
    UserManager();

    // Quản lý bác sĩ
    void addDoctor(const Doctor& doctor);                             // Thêm bác sĩ
    void removeDoctor(const string& username, const int& ID);         // Xóa bác sĩ 
    Doctor* findDoctorByID(int doctorID);                             // Tìm bác sĩ theo ID
    LinkedList<Doctor> findDoctorByUsername(const string& username); // Tìm bác sĩ theo tên người dùng
    void displayDoctors() const;                                     // Hiển thị danh sách bác sĩ

    // Quản lý bệnh nhân
    void addPatient(const Patient& patient);             // Thêm bệnh nhân
    void removePatient(const string& username,const int& ID);     // Xóa bệnh nhân theo tên người dùng
    Patient* findPatientByID(int patientID);             // Tìm bệnh nhân theo ID
    LinkedList <Patient> findPatientByUsername(const string& username); // Tìm bệnh nhân theo tên người dùng
    void displayPatients() const;                        // Hiển thị danh sách bệnh nhân

    // Cập nhật thông tin người dùng (bệnh nhân/bác sĩ)
    void updateDoctorInfo(int doctorID, const Doctor& newDoctorInfo);    // Cập nhật thông tin bác sĩ
    void updatePatientInfo(int patientID, const Patient& newPatientInfo); // Cập nhật thông tin bệnh nhân
};
#endif