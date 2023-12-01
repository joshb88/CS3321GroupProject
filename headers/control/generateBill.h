#include <iostream>
#include <iomanip>
#include "entity/procedure.h"
#include "entity/patient.h"


class generateBill
{
    private:
    float calculateTotal(std::vector<int>);
    float total = 0;
    public:
    static void displayPatientInfo(Patient);
    static void displayProcedures(std::vector<Procedure>);

};