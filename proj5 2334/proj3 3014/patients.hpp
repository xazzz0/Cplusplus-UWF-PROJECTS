#ifndef PATIENTS_HPP
#define PATIENTS_HPP

#include "patient.hpp"
#include <string>

using std::string;

class Patients {
    private:
    Patient *patients;
    int capacity;
    int count;
    void reallocate();
    public:
    Patients();
    Patients(Patient *initialList, int count);
    ~Patients();
    void addPatient(string name, int age, string gender);
    void removePatient(int index);
    int searchByName(const string &name) const;
    int getCount() const;
    void print() const;
    void printAllNames() const;
};


#endif // PATIENTS_HPP