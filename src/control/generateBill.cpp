# include "control/generateBill.h"

float generateBill::calculateTotal(std::vector<float> cost_vec)
{
    float total_1; 
    for(int i = 0; i < cost_vec.size(); i++)
    {
        total_1 += cost_vec[i];
    }
    return total_1;
}

void generateBill::setPatientInfo(Schedule sche)
{
    patient_info = sche.getPatient();
}

Patient generateBill::getBillPatient()
{
    return patient_info;
}
std::vector<std::string> generateBill::getBillProcedureList()
{
    return procedure_list;
}

std::vector<float> generateBill::getBillCostList()
{
    return procedure_cost;
}

void generateBill::setProcedureInfo(Schedule sche)
{
    Procedure pro;
    pro = sche.getProcedure();
    procedure_list.push_back(pro.getProcedureName());
    procedure_cost.push_back(pro.getCost());
}