// #include "control/GenerateScheduleReport.h"

// std::string GenerateScheduleReport::generateScheduleReport(const std::vector<Schedule> &scheduleVector)
// {
//     std::string formattedReport = "************************\n";
//     for(int i=0;i<scheduleVector.size();i++)
//     {
//         Schedule s= scheduleVector[i];
//         //getting and formatting time
//         //TimePoint time = std::chrono::system_clock::now();
//         //Time_Point -> time_T
//         std::time_t timeT = std::chrono::system_clock::to_time_t(s.getTime());
//         //time_T -> local tim
//         std::tm localTime = *std::localtime(&timeT);
//         //this part is from cplusplus I don't get it
//         char buffer[80];
//         std::strftime(buffer,sizeof(buffer), "%m-%d-%Y %H:%M:%S", &localTime);
//         formattedReport+="Date & Time: ";
//         formattedReport+=buffer + '\n';
//         formattedReport+="Patient: " +s.getPatient().getLastName()+", "+s.getPatient().getFirstName()+'\n';
//         formattedReport+="Staff: " + s.getStaffer().getLastName()+", "+s.getStaffer().getFirstName()+'\n';
//         formattedReport+="Room: " + s.getRoom().getRoomNumber()+'\n';
//         formattedReport+="Procedure: " + s.getProcedure().getProcedureName()+'\n';
//         formattedReport+="************************\n";
//     }
//     return formattedReport;
// }