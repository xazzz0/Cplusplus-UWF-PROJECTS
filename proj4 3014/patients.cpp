#include "patients.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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
        patients[i] = patients[i + 1]; //shifts the patients after removal towards the beginning of the array
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
        cout << i << ": Name: " << patients[i].getName()
             << " | Age: " << patients[i].getAge()
             << " | Gender: " << patients[i].getGender() << endl;
    }
}

bool Patients::loadFromFile(const string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: File '" << filename << "' cannot be opened!" << endl;
        return false;
    }

    count = 0;
    string line;

    //skip first line (number of patients)
    if (!getline(file, line)) {
        cout << "Error: File is empty or invalid!" << endl;
        return false;
    }

    //parse following lines
    while (getline(file, line)) {
        std::istringstream iss(line);
        string name, gender;
        int age;

        //parse
        getline(iss, name, ',');
        iss >> age;
        iss.ignore(2); //ignore ,
        getline(iss, gender);

        //trim whitespace
        name.erase(name.find_last_not_of(" \t\n\r") + 1);
        gender.erase(gender.find_last_not_of(" \t\n\r") + 1);

        addPatient(name, age, gender);
    }

    file.close();
    return true;
}

bool Patients::saveToFile(const string &filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: File cannot be opened!" << endl;
        return false;
    }

    //write number of patients
    file << count << "\n";

    for (int i = 0; i < count; ++i) {
        file << patients[i].getName() << ", " 
             << patients[i].getAge() << ", " 
             << patients[i].getGender() << "\n";
    }

    file.close();
    return true;
}

bool Patients::updatePatient(int index, const string &name, int age, const string &gender) {
    if (index < 0 || index >= count) {
        cout << "Error: Invalid index!" << endl;
        return false;
    }
    if (gender != "Male" && gender != "Female") {
        cout << "Error: Invalid gender! Must be 'Male' or 'Female'." << endl;
        return false;
    }
    patients[index] = Patient(name, age, gender);
    return true;
}

string Patients::getPatientInfo(int index) const {
    if (index < 0 || index >= count) {
        return "Error: Invalid index!";
    }
    return patients[index].info();
}

bool Patients::load(const string &filename) {
    return loadFromFile(filename);
}

bool Patients::save(const string &filename) const {
    return saveToFile(filename);
}
