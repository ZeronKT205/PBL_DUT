#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>
#include <string>
#include "Linked_List.cpp"
#include "Appointment.h"
#include "Clinic_Room.h"
#include "Patient.h"
#include "Doctor.h"

using namespace std;

class Schedule {
private:
    LinkedList<Appointment> appointments;   // Danh sách các cuộc hẹn
    LinkedList<Clinic_Room> rooms;          // Danh sách các phòng khám
    LinkedList<Patient> patients;
    LinkedList<Doctor> doctors;             // Danh sách các bác sĩ

public:
    // Constructor
    Schedule();

    //Quan ly benh nhan
    void addPatient(const Patient& patient);
    void removePatient(int patientID);
    Patient* findPatient(const string& patientName, const int& patient_ID);
    LinkedList<Patient> getAllPatients() const;

    // Quản lý bác sĩ
    void addDoctor(const Doctor& doctor);
    void removeDoctor(int doctorID);
    Doctor* findDoctor(const string& doctorName,const int& doctor_ID);
    LinkedList<Doctor> getAllDoctors() const;

    // Quản lý phòng khám
    void addClinicRoom(const Clinic_Room& room);
    void removeClinicRoom(int roomID);
    Clinic_Room* findClinicRoom(const int& roomID);
    LinkedList<Clinic_Room> getAllClinicRooms() const;

    // Quản lý lịch hẹn
    bool scheduleAppointment(const Appointment& appointment);
    void cancelAppointment(const string& patientName,const int& patient_ID, const string& date, const string& time);
    void viewAppointments() const;
    Appointment* findAppointmentByID(int appointmentID);
    LinkedList<Appointment> getAllAppointments() const;
};
#endif
