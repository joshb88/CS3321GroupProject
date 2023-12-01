#ifndef VIEW_BILL_H
#define VIEW_BILL_H

#include<iostream>
#include "control/generateBill.h"
#include "entity/schedule.h"

class viewBill{
private:
    std::vector<std::string> procedure_list;
    Patient patient_info;
    std::vector<float> procedure_cost;

public:
    void displayBillInformation();
    void getProcedureInfo(Schedule);
    void getPatientInfo(Schedule);
};

#endif // VIEW_BILL_H