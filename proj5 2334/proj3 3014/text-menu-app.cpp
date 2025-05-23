#include "text-menu-app.hpp"
#include "patients.hpp"

#include <iostream>
#include <string>
#include <limits>

using std::cout;
using std::endl;
using std::string;
using std::cin;

void TextMenuApp::run() {
    int choice = 0;
    while(true) {
        if (choice == 4) {
            cout << "Thank you for using the app!" << endl;
            break; 
        }
        cout << "1. Print all patients;\n2. Add a new patient;\n3. Remove a patient;\n4. Exit.\n";
        cout << "Please input an option(1-4): ";
        cin >> choice;
        if(choice == 1) {
            int initPatientCount = patients_.getCount();
            if(initPatientCount == 0) {
                cout << "No patients found." << endl;
            }
            patients_.printAllNames();
        }
        else if(choice == 2) {
            string name;
            int age;
            string gender;
            cout << "Please input patient's name: " << endl;
            
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, name);  //getline to read the full line including spaces
            
            while (patients_.searchByName(name) != -1) {
                cout << "Existing patient, please input another name!" << endl;
                getline(cin, name);  //getline here too for the same reason
            }
            
            cout << "Please input patient's age: " << endl;
            cin >> age;
            
            cout << "Please input patient's gender: " << endl;
            cin >> gender;
            
	    while ((gender != "Male") && (gender != "Female")){
                cout << "Invalid input, Male, or Female only!" << endl;
                cin >> gender;
            }
            patients_.addPatient(name, age, gender);
            
	    cout << "Patient added!" << endl;
	}
        else if(choice == 3) {
            int index;
            patients_.printAllNames();
            cout << "Please input the index of the patient you want to remove: " << endl;
            cin >> index;
            while (index < 0 || index >= patients_.getCount()) {
                cout << "Invalid index, please input another index!" << endl;
                cin >> index;
            }
            patients_.removePatient(index);
            cout << "Patient removed!" << endl;
        }
        else if(choice == 4) {
            ;
        }
        else {
            cout << "Invalid option, please try again!" << endl;
        }
        cout << endl;
    }
}
