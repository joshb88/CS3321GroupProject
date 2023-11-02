#include <iostream>
#include <iomanip>
#include "./headers/entity/schedule.h"

/* 
There is a chain of includes that are all satisfied by calling "schedule.h".
These include the contents of the header folder, <string>, <vector>, and
<chrono>.
*/

int main()
{   
    User newcomer;
    Room testroom(101, 5, true);
    Patient testPatient;
    std::cout << testPatient.getRoom().getRoomFloorNumber() << std::endl;
    testPatient.getRoom().setRoomFloorNumber(3);
    std::cout << testPatient.getRoom().getRoomNumber() << std::endl;
    std::cout << testPatient.getRoom().getRoomFloorNumber() << std::endl;
    testPatient.setRoom(testroom);
    std::cout << testPatient.getRoom().getRoomNumber() << std::endl;
    std::cout << testPatient.getRoom().getRoomFloorNumber();
    
    return 0;
};