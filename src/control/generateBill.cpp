// # include "control/generateBill.h"

// std::string section_break = "|_______________________________________________________________________________\n";
// std::string section_break_begining = "________________________________________________________________________________\n";
// std::string section_break_end = "|===============================================================================\n";

// float generateBill::calculateTotal(std::vector<int>)
// {
//     return 0.0f;
// }

// void generateBill::displayPatientInfo(Patient patient)
// {   
    
//     std::cout << section_break_begining;
//     std::cout << std::setw(40) << std::left << "| Patient Information";
//     std::cout << "| Patient Health Insurence\n";

//     std::cout << std::setw(40) << std::left << "|" << "|\n";

//     std::cout << std::setw(40) << std::left << 
//     ("| " + patient.getFirstName() + " " + patient.getLastName());
//     std::cout << "| " << patient.getInsuranceProvider() << "\n| ";

//     std::cout << std::setw(38) << std::left <<  
//     patient.getDateOfBirth() << "|\n";

//     std::cout << std::setw(40) << std::left << "|" << "|\n";
//     std::cout << section_break_end;
// }

// void generateBill::displayProcedures(std::vector<Procedure> procedure)
// {
//     std::cout << std::setw(35) << std::left << "| Procedure" << "| Amount\n";
//     std::cout << std::setw(35) << std::left << "|" << "|\n";

//     for (int i  = 0; i < procedure.size(); i++)
//     {
//         std::cout << "| " << std::setw(33) << std::left << procedure[i].getProcedureName()
//         << "| " << std::setprecision(2) << std::fixed << procedure[i].getCost() << std::endl;
//         total += procedure[i].getCost();
//     }

//     std::cout << std::setw(35) << std::left << "|" << "|\n";
//     std::cout << section_break_end;
//     std::cout << "|  Total Balance : $" << std::setprecision(2) << std::fixed << total << std::endl;
//     std::cout << section_break;

// }
