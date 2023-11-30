#ifndef VIEW_BILL_H
#define VIEW_BILL_H

#include<iostream>
#include "control/generateBill.h"

class viewBill{
private:
    generateBill billGenerator;

public:
    void displayBillInformation();
};

#endif // VIEW_BILL_H