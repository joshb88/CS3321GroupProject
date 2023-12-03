#include <iostream>
#include <iomanip>
#include "entity/schedule.h"


class generateBill
{
    private:
    static float total;
    std::vector<std::string> procedure_list;
    Patient patient_info;
    std::vector<float> procedure_cost;

    public:
     static float calculateTotal(std::vector<float>);
     void setProcedureInfo(Schedule);
     void setPatientInfo(Schedule);
     Patient getBillPatient();
     std::vector<std::string> getBillProcedureList();
     std::vector<float> getBillCostList();


};