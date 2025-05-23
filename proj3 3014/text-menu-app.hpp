#ifndef TEXT_MENU_APP_HPP
#define TEXT_MENU_APP_HPP

#include "patients.hpp"  

class TextMenuApp {
    private:
        Patients& patients_;  
    public:
        explicit TextMenuApp(Patients& patients) : patients_(patients) {} 
        void run();
};

#endif