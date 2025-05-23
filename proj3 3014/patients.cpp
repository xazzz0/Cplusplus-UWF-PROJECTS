#include "patients.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

Patients::Patients() : capacity(0), count(0) {
    patients = nullptr;
}

Patients::Patients(Patient *initialList, int count) : count(count) {
    capacity = count * 2;
    patients = new Patient[capacity];
    for (int i = 0; i < count; ++i) {
        patients[i] = initialList[i];
    }
}

Patients::~Patients() {
    delete[] patients;
}

void Patients::addPatient(string name, int age, string gender) {
    if (count == capacity) {
        reallocate();
    }
  
    patients[count] = Patient(name, age, gender); //adds a new patient
    count++;
}

void Patients::removePatient(int index) {
    //validates in text menu app
    patients[index].~Patient();
    for (int i = index; i < count - 1; ++i) {
        patients[i] = patients[i + 1]; // shifts the patients after removal, towards the beginning of the array
    }                       
    --count;
}

void Patients::reallocate() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    Patient *newPatients = new Patient[capacity];
    for (int i = 0; i < count; ++i) {
        newPatients[i] = patients[i];
    }
    delete[] patients;
    patients = newPatients;
}

int Patients::searchByName(const string &name) const {
    for (int i = 0; i < count; ++i) {
        if (patients[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

int Patients::getCount() const {
    return count;
}

void Patients::print() const {
    for (int i = 0; i < count; ++i) {
        cout << "Patient " << i << ": " << endl;
        patients[i].printInfo();
    }

} 

void Patients::printAllNames() const {
    for (int i = 0; i < count; ++i) {
        cout << "Patient " << i << ": " << patients[i].getName() << endl;
    }
    
}
