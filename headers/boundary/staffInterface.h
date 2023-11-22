#ifndef STAFF_INTERFACE_H
#define STAFF_INTERFACE_H

#include "userinterface.h"

class StaffInterface : public UserInterface {
public:
    void displayMainMenu() override; // Implementation specific to staff
    void addSchedule();
    void removeSchedule();
    void viewSchedule();
};

#endif // STAFF_INTERFACE_H
