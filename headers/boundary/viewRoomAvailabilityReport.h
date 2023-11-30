#ifndef VIEW_ROOM_AVAILABILITY_REPORT_H
#define VIEW_ROOM_AVAILABILITY_REPORT_H

#include<iostream>
#include<map>
#include<string>
#include "control/GenerateRoomAvailabilityReport.h"

class viewRoomAvailabilityReport{
private:
    GenerateRoomAvailabilityReport roomAvailabilityReporter;
public:
    void displayRoomAvailabilityReport(const std::map<int, Room*>& rooms);
};

#endif // VIEW_ROOM_AVAILABILITY_REPORT_H