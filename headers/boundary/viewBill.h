#ifndef VIEW_BILL_H
#define VIEW_BILL_H

#include<iostream>
#include "control/generateBill.h"
#include "entity/schedule.h"

class viewBill{

public:
    static void displayBillInformation(std::vector<Schedule>);
};

#endif // VIEW_BILL_H