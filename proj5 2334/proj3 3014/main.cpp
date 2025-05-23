
#include "patients.hpp"
#include "text-menu-app.hpp"

int main() {
  Patient initPatients[] = {{"Alan Harry", 24, "Male"},
                            {"Ching Peppard", 32, "Male"},
                            {"Lorelei Saad", 18, "Female"}
  };
  int initPatientCount = 3;
  Patients patients{initPatients, initPatientCount};
  TextMenuApp menu(patients);
  menu.run();
  return EXIT_SUCCESS;
}
