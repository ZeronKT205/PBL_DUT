#pragma once
#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H
#include <iostream>
#include <string>
#include <fstream>
#include "Doctor.h"
#include "Patient.h"
#include "Appointment.h"
#include "Clinic_Room.h"
#include "Linked_List.cpp"
using namespace std;

class FileManagement {
public:
    // Constructor
    FileManagement() {}

    // Lưu danh sách bác sĩ vào file
    void saveDoctors(const string& filename, const LinkedList<Doctor>& doctors);

    // Đọc danh sách bác sĩ từ file
    LinkedList<Doctor> loadDoctors(const string& filename);

    // Lưu danh sách bệnh nhân vào file
    void savePatients(const string& filename, const LinkedList<Patient>& patients);

    // Đọc danh sách bệnh nhân từ file
    LinkedList<Patient> loadPatients(const string& filename);

    // Lưu danh sách cuộc hẹn vào file
    void saveAppointments(const string& filename, const LinkedList<Appointment>& appointments);

    // Đọc danh sách cuộc hẹn từ file
    LinkedList<Appointment> loadAppointments(const string& filename);

    // Lưu danh sách phòng khám vào file
    void saveClinicRooms(const string& filename, const LinkedList<Clinic_Room>& rooms);

    // Đọc danh sách phòng khám từ file
    LinkedList<Clinic_Room> loadClinicRooms(const string& filename);
}; 


#endif


