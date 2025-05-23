#ifndef PATIENT_HPP
#define PATIENT_HPP
using namespace std;

#include <iostream>
#include <string>
using std::string;

class Patient {
private:
    string name;
    int age;
    string gender;
public:
    Patient();
    Patient(const string &name , int age, const string gender);
    const string getName() const;
    void printInfo() const;
};



#endif