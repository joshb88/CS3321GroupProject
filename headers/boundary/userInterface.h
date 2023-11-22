#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

class UserInterface {
public:
    virtual void displayMainMenu() = 0; // Pure virtual function
    virtual ~UserInterface() {} // Virtual destructor for proper cleanup
};

#endif // USER_INTERFACE_H
