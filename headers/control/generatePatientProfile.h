#include <iostream>
#include <iomanip>
#include "entity/schedule.h"

class generatePatientProfile
{
    private:
    Patient patient_info;
    std::vector<std::string> procedure_list;
    std::vector<int> roomnum_list;
    std::vector<short> floornum_list;
    std::vector<std::string> staff_list;

    public:
    void setProcedureInfo(Schedule);
    void setPatientInfo(Schedule);
    void setPatientRoomInfo (Schedule);
    void setStaffList (Schedule);
    Patient getPatientInfo();
    std::vector<std::string> getPatientProcedureList();
    std::vector<std::string> getPatientStaffList();
    std::vector<int> getPatientRoomList();
    std::vector<short> getPatientFloorList();



};