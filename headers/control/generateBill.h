#include <iostream>
#include "entity/procedure.h"
#include "entity/patient.h"
#include <iomanip>


class generateBill
{
    private:
    float calculateTotal(std::vector<int>);
    float total = 0;
    public:
    void displayPatientInfo(Patient);
    void displayProcedures(std::vector<Procedure>);

};