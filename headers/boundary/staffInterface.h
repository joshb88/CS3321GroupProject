#ifndef STAFF_INTERFACE_H
#define STAFF_INTERFACE_H

#include "boundary/userInterface.h"
#include "entity/staff.h"

class StaffInterface : public UserInterface {
public:
    void displayMainMenu(Staff& user); // Implementation specific to staff
    void addSchedule();
    void removeSchedule();
    void viewSchedule();
    void openInventory();
};

#endif // STAFF_INTERFACE_H
