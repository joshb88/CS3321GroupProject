#include "boundary/viewBill.h"

std::string section_break = "|_______________________________________________________________________________\n";
std::string section_break_begining = "________________________________________________________________________________\n";
std::string section_break_end = "|===============================================================================\n";

void viewBill::displayBillInformation(){

    // Display patient information
    std::cout << section_break_begining;
    std::cout << std::setw(40) << std::left << "| Patient Information";
    std::cout << "| Patient Health Insurence\n";

    std::cout << std::setw(40) << std::left << "|" << "|\n";

    std::cout << std::setw(40) << std::left << 
    ("| " + patient_info.getFirstName() + " " + patient_info.getLastName());
    std::cout << "| " << patient_info.getInsuranceProvider() << "\n| ";

    std::cout << std::setw(38) << std::left <<  
    patient_info.getDateOfBirth() << "|\n";

    std::cout << std::setw(40) << std::left << "|" << "|\n";
    std::cout << section_break_end;

    std::cout << std::setw(35) << std::left << "| Procedure" << "| Amount\n";
    std::cout << std::setw(35) << std::left << "|" << "|\n";

    // Displaying patient procedures, cost, and total
    for (int i  = 0; i < procedure_list.size(); i++)
    {
        std::cout << "| " << std::setw(33) << std::left << procedure_list[i]
        << "| " << std::setprecision(2) << std::fixed << procedure_cost[i] << std::endl;
    }

    float sum = generateBill::calculateTotal(procedure_cost);

    std::cout << std::setw(35) << std::left << "|" << "|\n";
    std::cout << section_break_end;
    std::cout << "|  Total Balance : $" << std::setprecision(2) << std::fixed << sum << std::endl;
    std::cout << section_break;
    
}

void viewBill::getProcedureInfo(Schedule sche)
{
    Procedure pro;
    pro = sche.getProcedure();
    procedure_list.push_back(pro.getProcedureName());
    procedure_cost.push_back(pro.getCost());
}

void viewBill::getPatientInfo(Schedule sche)
{
    patient_info = sche.getPatient();
}
