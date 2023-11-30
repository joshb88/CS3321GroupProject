#include "boundary/viewSchedule.h"

void viewSchedule::displayScheduleReport(const std::vector<Schedule>& scheduleVector){

    //obtain report from GenerateScheduleReport class
    std::string report = scheduleReporter.generateScheduleReport(scheduleVector);

    //Display report
    std::cout << "Schedule Report:\n";
    std::cout << report << std::endl;
}