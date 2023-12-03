#ifndef VIEW_SCHEDULE_H
#define VIEW_SCHEDULE_H

#include <iostream>
#include <string>
#include <vector>
#include "control/GenerateScheduleReport.h"

class viewSchedule{
private:
    GenerateScheduleReport scheduleReporter;
public:
    void displayScheduleReport(const std::vector<Schedule>& scheduleVector);
};

#endif // VIEW_SCHEDULE_H