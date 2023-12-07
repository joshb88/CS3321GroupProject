// #include <string>
// #include <sstream>
// #include <fstream>
// #include <iostream>
// #include "entity/schedule.h"
// #include <iomanip>
// #include <ctime>
// #include <chrono>
// #include "control/ModifySchedule.h"
// #include "boundary/MainMenu.h"
// #include "control/modifyProcedure.h"
// #include "control/TESTMODINV.h"

// void ModifySchedule::writeScheduleToDatabase(Schedule& schedule)
// {
//     std::ofstream schedule_file;
//     schedule_file.open("./database/schedules.txt", std::ios::app | std::ios::out);

//     if (schedule_file.is_open())
//     {
//         schedule_file << 
//         // std::cout <<

//         // Get the time
//         schedule.getTime() <<

//         '|' << // Store  Staff  info
//         schedule.getStaffer() <<

//         '|' << // Store Patient Info
//         schedule.getPatient() <<

//         '|' << // Store Room for Event
//         schedule.getRoom() <<
        
//         '|' << // Store Procedure
//         schedule.getProcedure().getProcedureName() << '-' <<
//         schedule.getProcedure().getCost() << '-' <<
//         ModifyProcedure::itemsUsedVectorToString(schedule.getProcedure().getItemsUsed()) <<
//         std::endl;
//     }
//     else {std::cout << "file not open";};
//     schedule_file.close();
// }
// Schedule ModifySchedule::readScheduleFromDatabase(const std::string& schedule_date)
// {
//     std::ifstream schedule_file("./database/schedules.txt");
//     std::string line;
//     std::getline(schedule_file, line, '\n');
//     std::istringstream iss(line);
//     Schedule schedule;

//     if (schedule_file.is_open())
//     {
//         std::string token;
//         iss >> token;
//         if (token == schedule_date)
//         {
//             // Assuming each line in the file represents a Schedule entry
//             while (std::getline(schedule_file, line))
//             {
//                 std::istringstream iss(line);
//                 std::string time, staffer, patient, room, procedureInfo;

//                 // Read each field from the line using getline or >>
//                 std::getline(iss, time, '|');
//                 while(std::getline(iss, staffer, '|'))
//                 {
//                     std::getline(iss,schedule.getPatient().setUserLogin(), '-');
//                     std::getline(iss,schedule.getPatient().setUserPassword(), '-');
//                     std::getline(iss,schedule.getPatient().setLastName(), '-');
//                     std::getline(iss,schedule.getPatient().setFirstName(), '-');
//                     std::getline(iss,schedule.getPatient().setDateOfBirth(), '-');
//                     std::getline(iss,schedule.getPatient().setFirstName(), '-');
//                     std::getline(iss,schedule.getPatient().setFirstName(), '-');
//                     std::getline(iss,schedule.getPatient().setFirstName(), '-');
//                 }
//                 std::getline(iss, patient, '|');
//                 std::getline(iss, room, '|');
//                 std::getline(iss, procedureInfo);

//                 // Process procedureInfo, assuming it is formatted as "ProcedureName-Cost-ItemsUsed"
//                 std::istringstream procedureStream(procedureInfo);
//                 std::string procedureName, cost, itemsUsedString;
//                 std::getline(procedureStream, procedureName, '-');
//                 std::getline(procedureStream, cost, '-');
//                 std::getline(procedureStream, itemsUsedString);

//                 // Convert strings to appropriate types and set the fields in the Schedule object
//                 schedule.setTime(time);
//                 schedule.setStaffer(staffer);
//                 schedule.setPatient(patient);
//                 schedule.setRoom(room);
//                 schedule.setProcedure(Procedure(procedureName, std::stof(cost), ModifyProcedure::itemsUserStringToVector(itemsUsedString)));

//                 // You might want to add the Schedule object to a container (vector, list, etc.) if needed
//                 // Example: schedules.push_back(schedule);
//             }
       
//         }       
//         else
//         {
//             std::cout << "Error: Unable to open the file.\n";
//         }
//     }
//     return schedule;
// }