#pragma once
#include <iostream>
#include "Schedule.h"
using namespace std;


//constructor
Schedule::Schedule(){}

//Quan ly benh nhan
void Schedule::addPatient(const Patient& patient) {
    patients.addLast(patient);
}
void Schedule::removePatient(int patientID) {
    bool check = false;
    for (int i = 0; i < patients.length(); i++) {
        Patient patient = patients.get(i);
        if (patient.getID() == patientID) {
            patients.removeAtIndex(i);
            check = true;
        }
    }
    if (!check) {
        cout << "Patient with ID: " << patientID << " not found!" << endl;
    }
}

Patient* Schedule::findPatient(const string& patientName, const int& patient_ID) {
    for (int i = 0; i < patients.length(); i++) {
        Patient& patient = patients.get(i);
        if (patient.getName() == patientName && patient.getID() == patient_ID) {
            return &patient;
        }
    }
    cout << "Patient " << patientName << " with ID " << patient_ID << " not found." << endl;
    return nullptr;
}

LinkedList<Patient> Schedule::getAllPatients() const {
    return patients;
}




//Quan ly Bac Si
void Schedule::addDoctor(const Doctor& doctor) {
	doctors.addLast(doctor);
}
void Schedule::removeDoctor(int doctorID) {
    bool check = false;
    for (int i = 0; i < doctors.length(); i++) {
        Doctor doctor = doctors.get(i);
        if (doctor.getID() == doctorID) {
            doctors.removeAtIndex(i);
            check = true;
        }
    }
    if (!check) {
        cout << "Doctor with ID: " << doctorID << " not found!" << endl;
    }
}
Doctor* Schedule::findDoctor(const string& doctorName, const int& doctor_ID) {
    for (int i = 0; i < doctors.length(); i++) {
        Doctor &doctor = doctors.get(i);
        if (doctor.getName() == doctorName && doctor.getID() == doctor_ID) {
            return &doctor;
        }
    }
    cout << "Doctor " << doctorName << " with ID " << doctor_ID << " not found." << endl;
    return nullptr;
}
LinkedList<Doctor> Schedule::getAllDoctors() const {
    return doctors;
}



//Quan ly phong kham
void Schedule::addClinicRoom(const Clinic_Room& room) {
    rooms.addLast(room);
}
void Schedule::removeClinicRoom(int roomID) {
    bool check = false;
    for (int i = 0; i < rooms.length(); i++) {
        Clinic_Room room = rooms.get(i);
        if (room.getRoomID() == roomID) {
            rooms.removeAtIndex(i);
            check = true;
        }
    }
    if (!check) {
        cout << "Room with ID: " << roomID << " not found!" << endl;
    }
}

Clinic_Room* Schedule::findClinicRoom(const int& roomID) {
    for (int i = 0; i < rooms.length(); i++) {
        Clinic_Room& room = rooms.get(i);
        if (room.getRoomID() == roomID) {
            return &room;
        }
    }
    cout << "Room " << roomID << " not found." << endl;
    return nullptr;
}

LinkedList<Clinic_Room> Schedule::getAllClinicRooms() const {
    return rooms;
}



//QUAN LY LICH HEN
bool Schedule::scheduleAppointment(const Appointment& appointment) {
    //kiem tra xem phong con trong khong
    Clinic_Room* room = findClinicRoom(appointment.getClinic_Room_ID());
    if (room == nullptr || !room->checkAvailability(appointment.getDate(), appointment.getTime())) {
        cout << "Cannot schedule appointment: Room not available." << endl;
        return false;
    }

    //kiem tra bac si và time lam viec
    Doctor* doctor = findDoctor(appointment.getDoctorName(), appointment.getDoctor_ID());
    if (doctor == nullptr) {
        cout << "Cannot schedule appointment: Doctor not found." << endl;
        return false;
    }
    if(!doctor->isDoctorAvailable(appointment.getDate(),appointment.getTime())){
        return false;
    }
    Patient* patient = findPatient(appointment.getPatientName(), appointment.getPatient_ID());
    //Them cuoc hen vao danh sach 
    room->addAppointment(appointment);
    doctor->addAppointment(appointment);
    patient->addAppointment(appointment);
    appointments.addLast(appointment);
    
    cout << "Appointment scheduled successfully." << endl;
    return true;
}

//huy cuoc hen

void Schedule::cancelAppointment(const string& patientName, const int& patient_ID, const string& date, const string& time) {
    for (int i = 0; i < appointments.length(); i++) {
        Appointment& appt = appointments.get(i);
        if (appt.getPatientName() == patientName && appt.getPatient_ID() == patient_ID && appt.getDate() == date && appt.getTime() == time) {
            Clinic_Room* room = findClinicRoom(appt.getClinic_Room_ID());
            Doctor* doctor = findDoctor(appt.getDoctorName(), appt.getDoctor_ID());
            Patient* patient = findPatient(patientName, patient_ID);
            if (room != nullptr && doctor != nullptr && patient != nullptr) {
                room->removeAppointment(date, time);
                doctor->removeAppointment(patientName, date, time, appt.getAppointment_ID());
                patient->cancelAppointment(date, appt.getAppointment_ID());
            }
            appointments.removeAtIndex(i);  // Xóa cuộc hẹn khỏi danh sách
            cout << "Appointment cancelled successfully." << endl;
            return;
        }
    }
    cout << "No appointment found for " << patientName << " on " << date << " at " << time << endl;
}

void Schedule::viewAppointments() const {
    if (appointments.empty()) {
        cout << "No appointments scheduled." << endl;
        return;
    }
    for (int i = 0; i < appointments.length(); i++) {
        const Appointment& appt = appointments.get(i); 
        cout << "Appointment with " << appt.getPatientName()<< " on " << appt.getDate()<< " at " << appt.getTime()<< " in room " << appt.getClinicRoom() << " with Doctor " << appt.getDoctorName() << endl;
    }   
}
Appointment* Schedule::findAppointmentByID(int appointmentID) {
    for (int i = 0; i < appointments.length(); i++) {
        Appointment& appt = appointments.get(i);
        if (appt.getAppointment_ID() == appointmentID) {
            return &appt;
        }
    }
    cout << "Appointment with ID: " << appointmentID << " not found!" << endl;
    return nullptr;
}
LinkedList<Appointment> Schedule::getAllAppointments() const {
    return appointments;
}





//int main() {
//    // Tạo đối tượng Schedule để quản lý hệ thống
//    Schedule schedule;
//
//    // Thêm bác sĩ vào hệ thống
//    Doctor doctor1("Michael Johnson", "1980-05-10", "Male", "123 Central St", "555-1212", "mjdoctor", "secure123", 201, "Dermatology");
//    Doctor doctor2("Sarah Connor", "1979-02-15", "Female", "456 West Ave", "555-2323", "scdoctor", "strong456", 202, "Cardiology");
//    schedule.addDoctor(doctor1);
//    schedule.addDoctor(doctor2);
//
//
//    // Thêm phòng khám vào hệ thống
//    Clinic_Room room1(301, "General Room", "Available");
//    Clinic_Room room2(302, "Surgery Room", "Available");
//    Clinic_Room room3(303, "Pediatrics Room", "Available");
//    schedule.addClinicRoom(room1);
//    schedule.addClinicRoom(room2);
//    schedule.addClinicRoom(room3);
//
//    // Tạo cuộc hẹn và thêm vào hệ thống
//    Appointment appt1(1, 2001, 201, 301, "2024-11-10", "09:00", "Michael Johnson", "Alice Brown", "General Room", "Scheduled");
//    Appointment appt2(2, 2002, 202, 302, "2024-11-11", "11:00", "Sarah Connor", "Bob White", "Surgery Room", "Scheduled");
//
//    // Đặt lịch hẹn
//    if (schedule.scheduleAppointment(appt1)) {
//        cout << "Appointment 1 scheduled successfully!" << endl;
//    }
//
//    if (schedule.scheduleAppointment(appt2)) {
//        cout << "Appointment 2 scheduled successfully!" << endl;
//    }
//
//    // Tạo thêm một cuộc hẹn khác
//    Appointment appt3(3, 2003, 201, 303, "2024-11-12", "13:00", "Michael Johnson", "Cathy Green", "Pediatrics Room", "Scheduled");
//
//    if (schedule.scheduleAppointment(appt3)) {
//        cout << "Appointment 3 scheduled successfully!" << endl;
//    }
//
//    // Hiển thị danh sách các cuộc hẹn
//    cout << "\n--- View All Appointments ---" << endl;
//    schedule.viewAppointments();
//
//    // Hủy cuộc hẹn thứ hai
//    cout << "\n--- Cancel Appointment ---" << endl;
//    schedule.cancelAppointment("Bob White", 2002, "2024-11-11", "11:00");
//
//    // Hiển thị lại danh sách cuộc hẹn sau khi hủy
//    cout << "\n--- View Appointments After Cancellation ---" << endl;
//    schedule.viewAppointments();
//
//    return 0;
//}