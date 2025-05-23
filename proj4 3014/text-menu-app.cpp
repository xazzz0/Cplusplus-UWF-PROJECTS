#include "text-menu-app.hpp"
#include "patients.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

void TextMenuApp::run() {
    string filename;
    bool loaded = false;

    //prompt user to load initial data
    while (!loaded) {
        cout << "Input the file name to load initial data from: ";
        cin >> filename;
        if (!patients_.loadFromFile(filename)) {
            cout << "File cannot be opened! Input again!" << endl;
        } else {
            cout << "File loaded!" << endl;
            loaded = true;
        }
    }

    int choice = 0;
    while (true) {
        cout << "\n1. Print all patients;\n"
             << "2. Update information of a patient;\n"
             << "3. Save file;\n"
             << "4. Exit.\n";
        cout << "Please choose an option(1-4): ";
        cin >> choice;

        if (choice == 1) {
            //print all patients
            patients_.printAllNames();
            cout << patients_.getCount() << " patients in total." << endl;
        } else if (choice == 2) {
            //update patient's information
            int index;
            string name, gender;
            int age;

            while (true) {
                cout << "Please input patient's id as shown in the list: ";
                cin >> index;
                if (index < 0 || index >= patients_.getCount()) {
                    cout << "Invalid index, please input again!" << endl;
                } else {
                    break;
                }
            }

            cout << "The existing info:\n";
            cout << patients_.getPatientInfo(index) << endl;

            cout << "Please input patient's new name: ";
            cin.ignore(); 
            getline(cin, name);

            cout << "Please input patient's new age: ";
            cin >> age;

            while (true) {
                cout << "Please input patient's new gender(Male/Female): ";
                cin >> gender;
                if (gender != "Male" && gender != "Female") {
                    cout << "Invalid input, Male, or Female only!" << endl;
                } else {
                    break;
                }
            }

            if (patients_.updatePatient(index, name, age, gender)) {
                cout << "Patient updated!" << endl;
            }
        } else if (choice == 3) {
            //save data to a file
            cout << "Input the file name to save the data to: ";
            cin >> filename;
            if (patients_.saveToFile(filename)) {
                cout << "File saved!" << endl;
            } else {
                cout << "Error: Failed to save file!" << endl;
            }
        } else if (choice == 4) {
            //exit the program
            cout << "Thank you for using the app!" << endl;
            break;
        } else {
            cout << "Invalid option, please try again!" << endl;
        }
    }
}
