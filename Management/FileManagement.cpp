#include "FileManagement.h"
#include <sstream>
#include <iostream>
using namespace std;

//Lưu danh sách bác sĩ vào file
void FileManagement::saveDoctors(const string& filename, const LinkedList<Doctor>& doctors) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < doctors.length(); i++) {
            const Doctor& doctor = doctors.get(i);
            outFile << doctor.getID() << "|"<< doctor.getName() << "|"<< doctor.getDateOfBirth() << "|"<< doctor.getGender() << "|"<< doctor.getAddress() << "|"<< doctor.getPhoneNumber() << "|"<< doctor.getUsername() << "|"<< doctor.getPassword() << "|"<< doctor.getSpecialty() << endl;
        }
        outFile.close();
    }
    else {
        cerr << "Could not open file for saving doctors: " << filename << endl;
    }
}

LinkedList<Doctor> FileManagement::loadDoctors(const std::string& filename) {
    LinkedList<Doctor> doctors;
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string id, name, dob, gender, address, phone, username, password, specialty;

            getline(ss, id, '|');        
            getline(ss, name, '|');    
            getline(ss, dob, '|');       
            getline(ss, gender, '|');    
            getline(ss, address, '|');   
            getline(ss, phone, '|');     
            getline(ss, username, '|');  
            getline(ss, password, '|'); 
            getline(ss, specialty, '|'); 

            Doctor doctor(name, dob, gender, address, phone, username, password, stoi(id), specialty);
            doctors.addLast(doctor);
        }
        inFile.close();
    }
    else {
        cerr << "Could not open file for loading doctors: " << filename << endl;
    }
    return doctors;
}

void FileManagement::savePatients(const string& filename, const LinkedList<Patient>& patients) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < patients.length(); i++) {
            const Patient& patient = patients.get(i);
            outFile << patient.getID() << "|" << patient.getName() << "|" << patient.getDateOfBirth() << "|" << patient.getGender() << "|" << patient.getAddress() << "|" << patient.getPhoneNumber() << "|" << patient.getUsername() << "|" << patient.getPassword() << "|" << endl;
        }
        outFile.close();
    }
    else {
        cerr << "Could not open file for loading Patients: " << filename << endl;
    }
}
LinkedList<Patient> FileManagement::loadPatients(const string& filename) {
    LinkedList<Patient> patients;
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string id, name, dob, gender, address, phone, username, password;

            getline(ss, id,'|');
            getline(ss, name, '|');
            getline(ss, dob, '|');
            getline(ss, gender, '|');
            getline(ss, address, '|');
            getline(ss, phone, '|');
            getline(ss, username, '|');
            getline(ss, password, '|');

            Patient newPatient(name, dob, gender, address, phone, username, password,stoi(id));
            patients.addLast(newPatient);
        }
        inFile.close();
    }
    else {
        cerr << "Could not open file for loading Patients: " << filename << endl;
    }
    return patients;
}

void FileManagement::saveAppointments(const string& filename, const LinkedList<Appointment>& appointments) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < appointments.length(); i++) {
            Appointment appt = appointments.get(i);
            outFile << appt.getAppointment_ID() << "|"        
                << appt.getPatient_ID() << "|"            
                << appt.getDoctor_ID() << "|"              
                << appt.getClinic_Room_ID() << "|"         
                << appt.getDate() << "|"                    
                << appt.getTime() << "|"                    
                << appt.getDoctorName() << "|"            
                << appt.getPatientName() << "|"          
                << appt.getClinicRoom() << "|"              
                << appt.getStatus() << endl;          
        }
        outFile.close();
    }
    else {
        cerr<<"Could not open file for loading Appointments : " << filename << endl;
    }
}

LinkedList<Appointment> FileManagement::loadAppointments(const string& filename) {
    LinkedList<Appointment> appointments;
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string appointmentID, patientID, doctorID, clinicRoomID, date, time, doctorName, patientName, clinicRoom, status;
            
            getline(ss, appointmentID, '|');
            getline(ss, patientID, '|');
            getline(ss, doctorID, '|');
            getline(ss, clinicRoomID, '|');
            getline(ss, date, '|');
            getline(ss, time, '|');
            getline(ss, doctorName, '|');
            getline(ss, patientName, '|');
            getline(ss, clinicRoom, '|');
            getline(ss, status, '|');
            
            Appointment newAppointment(stoi(appointmentID), stoi(patientID), stoi(doctorID), stoi(clinicRoomID), date, time, doctorName, patientName, clinicRoom, status);
            appointments.addLast(newAppointment);
        }
        inFile.close();
    }
    else {
        cerr << "Could not open file for loading Appointments: " << filename << endl;
    }
    return appointments;
}


void FileManagement::saveClinicRooms(const string& filename, const LinkedList<Clinic_Room>& rooms) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < rooms.length();i++) {
            Clinic_Room room = rooms.get(i);
            outFile << room.getRoomID() << "|" << room.getRoomType() << "|" << room.getStatus() << endl;
        }
        outFile.close();
    }
    else {
        cerr << "Could not open file for loading Clinics : " << filename << endl;
    }
}
LinkedList<Clinic_Room> FileManagement::loadClinicRooms(const string& filename) {
    LinkedList<Clinic_Room> rooms;
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string roomID, roomType, status;

            getline(ss, roomID, '|');
            getline(ss, roomType, '|');
            getline(ss, status, '|');

            Clinic_Room newRoom(stoi(roomID), roomType,status);
            rooms.addLast(newRoom);
        }
        inFile.close();
    }
    else {
        cerr << "Could not open file for loading Clinics: " << filename << endl;
    }
    return rooms;
}