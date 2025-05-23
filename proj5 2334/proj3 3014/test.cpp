#include "patient.hpp"
#include "patients.hpp"
#include <iostream>
#include <cassert>

using namespace std;

void testPatient();
void testPatients();

int main() {
  testPatient();
  testPatients();
  return 0;
}

void testPatient() {
  cout << "testing Patient class" << endl;
  Patient pat("John Smith", 24, "Male");
  assert(pat.getName() == "John Smith");
  cout << "All tests passed" << endl;
}

void testPatients() {
  Patient initPatients[] = {{"Alan Harry", 24, "Male"},
                            {"Ching Peppard", 32, "Male"},
                            {"Lorelei Saad", 18, "Female"}
  };
  int initPatientCount = 3;
  cout << "testing Patients class" << endl;
  Patients patients(initPatients, initPatientCount);
  assert(patients.getCount() == 3);
  assert(patients.searchByName("Alan Harry") == 0);
  assert(patients.searchByName("John Smith") == -1);
  patients.addPatient("John Smith", 24, "Male");
  assert(patients.getCount() == 4);
  assert(patients.searchByName("John Smith") == 3);
  patients.removePatient(1);
  assert(patients.getCount() == 3);
  assert(patients.searchByName("Ching Peppard") == -1);
  cout << "All tests passed" << endl;

}
