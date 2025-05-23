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
  assert(pat.info() == "Name: John Smith | Age: 24 | Gender: Male");
  Patient pat1("Luke Johnson, 21, Male");
  assert(pat1.info() == "Name: Luke Johnson | Age: 21 | Gender: Male");
  cout << "All tests passed" << endl;
}

void testPatients() {
  cout << "testing Patients class" << endl;
  Patients patients;
  assert(!patients.load("notexist.txt"));
  assert(patients.load("patients.txt"));
  assert(patients.getCount() == 3);
  assert(patients.getPatientInfo(0) == "Name: Alan Harry | Age: 24 | Gender: Male");
  assert(patients.getPatientInfo(1) == "Name: Ching Peppard | Age: 32 | Gender: Male");
  assert(patients.getPatientInfo(2) == "Name: Lorelei Saad | Age: 18 | Gender: Female");
  patients.updatePatient(0, "Mary Smith", 20, "Female");
  assert(patients.getPatientInfo(0) == "Name: Mary Smith | Age: 20 | Gender: Female");
  assert(patients.getPatientInfo(1) == "Name: Ching Peppard | Age: 32 | Gender: Male");
  assert(patients.getPatientInfo(2) == "Name: Lorelei Saad | Age: 18 | Gender: Female");
  patients.save("test-output.txt");
  Patients patients1;
  assert(patients1.load("test-output.txt"));
  assert(patients1.getCount() == 3);
  assert(patients1.getPatientInfo(0) == "Name: Mary Smith | Age: 20 | Gender: Female");
  assert(patients1.getPatientInfo(1) == "Name: Ching Peppard | Age: 32 | Gender: Male");
  assert(patients1.getPatientInfo(2) == "Name: Lorelei Saad | Age: 18 | Gender: Female");
  cout << "All tests passed" << endl;

}
