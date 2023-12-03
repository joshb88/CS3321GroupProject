#include "control/generatePatientProfile.h"

void generatePatientProfile::setProcedureInfo(Schedule sche)
{
    procedure_list.push_back(sche.getProcedure().getProcedureName());
}

void generatePatientProfile::setPatientInfo(Schedule sche)
{
    patient_info = sche.getPatient();
}

void generatePatientProfile::setPatientRoomInfo(Schedule sche)
{
    roomnum_list.push_back(sche.getRoom().getRoomNumber());
    floornum_list.push_back(sche.getRoom().getRoomFloorNumber());
}

void generatePatientProfile::setStaffList(Schedule sche)
{
    staff_list.push_back(sche.getStaffer().getLastName());
}

Patient generatePatientProfile::getPatientInfo()
{
    return patient_info;
}

std::vector<std::string> generatePatientProfile::getPatientProcedureList()
{
    return procedure_list;
}

std::vector<std::string> generatePatientProfile::getPatientStaffList()
{
    return staff_list;
}

std::vector<int> generatePatientProfile::getPatientRoomList()
{
    return roomnum_list;
}

std::vector<short> generatePatientProfile::getPatientFloorList()
{
    return floornum_list;
}
