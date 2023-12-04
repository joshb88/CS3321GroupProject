#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "entity/user.h"

class UserInterface {
public:
    void displayMainMenu(User& user) {} // Pure virtual function
    virtual ~UserInterface() {} // Virtual destructor for proper cleanup
};

#endif // USER_INTERFACE_H
