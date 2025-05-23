#include "patient.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

Patient::Patient() : age(0) {}

Patient::Patient(const string &name, int age, const string gender) :
name(name), age(age), gender(gender) {}

const string Patient::getName() const {
    return name;
}

void Patient::printInfo() const {
    cout << "Patient name: " << name << endl;
    cout << "Patient age: " << age << endl;
    cout << "Patient gender:" << gender << endl;

}