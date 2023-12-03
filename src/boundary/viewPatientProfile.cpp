#include "boundary/viewPatientProfile.h"

std::string section_end = "|_______________________________________________________________________________\n";
std::string section_begin = "________________________________________________________________________________\n";
std::string section_divider = "|===============================================================================\n" ;

void viewPatientProfile::displayPatientProfile(std::vector<Schedule> schedule)
{
    generatePatientProfile myProfile;
    
    for(int i = 0; i < schedule.size(); i++)
    {
        if (i < 1)
        {
            myProfile.setPatientInfo(schedule[i]);
        }
        myProfile.setProcedureInfo(schedule[i]);
        myProfile.setPatientRoomInfo(schedule[i]);
        myProfile.setStaffList(schedule[i]);

    }

    std::cout << section_begin;
    std::cout << std::setw(42) << std::left << "| Patient Information";
    std::cout << "| Patient Health Insurence\n";

    std::cout << std::setw(42) << std::left << "|" << "|\n";

    std::cout << std::setw(15) << std::left << "| Patient Name : " << std::setw(25) <<
    (myProfile.getPatientInfo().getFirstName() + " " + myProfile.getPatientInfo().getLastName());
    std::cout << "| " << myProfile.getPatientInfo().getInsuranceProvider() << "\n";

    std::cout << std::setw(17) << std::left << "| Patient DOB : " << std::setw(25) <<
    myProfile.getPatientInfo().getDateOfBirth();
    std::cout << "|\n";

    std::cout << std::setw(15) << std::left << "| Gender : " << std::setw(27) << 
    myProfile.getPatientInfo().getGender();
    std::cout << "|\n";

    std::cout << std::setw(42) << std::left << "|" << "|\n";
    std::cout << section_divider;
    std::cout << "|\n";

    std::cout << std::setw(25) << std::left << "| Procedure" <<
    std::setw(15) << "Floor" << std::setw(20) << "Room Number" 
    << "Assigned Staff\n";
    std::cout << "|\n";

    for(int i = 0; i < myProfile.getPatientProcedureList().size(); i++)
    {
        std::cout << std::setw(25) << std::left << "| " + myProfile.getPatientProcedureList()[i];
        std::cout << std::setw(15) << myProfile.getPatientFloorList()[i] << std::setw(20) <<
        myProfile.getPatientRoomList()[i] << myProfile.getPatientStaffList()[i] << std::endl;
    }

    std::cout << "|\n" << section_end;


}
