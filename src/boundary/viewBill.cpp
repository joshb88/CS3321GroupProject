#include "boundary/viewBill.h"

std::string section_break = "|_______________________________________________________________________________\n";
std::string section_break_begining = "________________________________________________________________________________\n";
std::string section_break_end = "|===============================================================================\n";

void viewBill::displayBillInformation(std::vector<Schedule> schedule){

    generateBill myBill;

    for(int i = 0; i < schedule.size(); i++)
    {
        if (i < 1)
        {
            myBill.setPatientInfo(schedule[i]);
        }
        myBill.setProcedureInfo(schedule[i]);
    }

    // Display patient information
    std::cout << section_break_begining;
    std::cout << std::setw(40) << std::left << "| Patient Information";
    std::cout << "| Patient Health Insurence\n";

    std::cout << std::setw(40) << std::left << "|" << "|\n";

    std::cout << std::setw(40) << std::left << 
    ("| " + myBill.getBillPatient().getFirstName() + " " + myBill.getBillPatient().getLastName());
    std::cout << "| " << myBill.getBillPatient().getInsuranceProvider() << "\n| ";

    std::cout << std::setw(38) << std::left <<  
    myBill.getBillPatient().getDateOfBirth() << "|\n";

    std::cout << std::setw(40) << std::left << "|" << "|\n";
    std::cout << section_break_end;

    std::cout << std::setw(35) << std::left << "| Procedure" << "| Amount\n";
    std::cout << std::setw(35) << std::left << "|" << "|\n";

    // Displaying patient procedures, cost, and total
    for (int i  = 0; i < myBill.getBillProcedureList().size(); i++)
    {
        std::cout << "| " << std::setw(33) << std::left << myBill.getBillProcedureList()[i]
        << "| " << std::setprecision(2) << std::fixed << myBill.getBillCostList()[i] << std::endl;
    }

    float sum = generateBill::calculateTotal(myBill.getBillCostList());

    std::cout << std::setw(35) << std::left << "|" << "|\n";
    std::cout << section_break_end;
    std::cout << "|  Total Balance : $" << std::setprecision(2) << std::fixed << sum << std::endl;
    std::cout << section_break;
    
}

