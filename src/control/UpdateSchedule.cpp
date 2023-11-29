#include "control/UpdateSchedule.h"

void UpdateSchedule::addEvent(std::vector<Schedule>&scheduleVector, const Schedule::TimePoint &timePoint, const Staff &staff, const Patient &patient, const Room &room, const Procedure &procedure)
{
    Schedule scheduleObject(timePoint, staff, patient, room, procedure);
    scheduleVector.push_back(scheduleObject);
}