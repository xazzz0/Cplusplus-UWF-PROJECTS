#include "patient.hpp"

#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

Patient::Patient() : age(0) {}

Patient::Patient(const string &name, int age, const string gender) :
name(name), age(age), gender(gender) {}

Patient::Patient(const string &data) { 
    std::istringstream iss(data);
    getline(iss, name, ',');
    iss >> age;
    iss.ignore(2); //ignore ,
    getline(iss, gender);
}

const string Patient::getName() const {
    return name;
}

int Patient::getAge() const {
    return age;
}

const string Patient::getGender() const { 
    return gender;
}

string Patient::info() const { 
    return "Name: " + name + " | Age: " + std::to_string(age) + " | Gender: " + gender;
}

void Patient::printInfo() const {
    cout << "Patient name: " << name << endl;
    cout << "Patient age: " << age << endl;
    cout << "Patient gender:" << gender << endl;
}