#include <iostream>
#include <iomanip>
#include "entity/schedule.h"
#include "control/storedata.h"
//#include "control/ModifyRoomAvailability.h"

/* 
There is a chain of includes that are all satisfied by calling "schedule.h".
These include the contents of the header/entity/ folder, <string>, <vector>, and
<chrono>.
*/

int main()
{ 
    Room testroom1(101, 5, true);
    Room testroom2(303, 2, true);
    User testPatient("test_login","test_password","test_last","test_first",19880814,'M');

    StoreData::storeUser(testPatient);

    //std::cout << testPatient.getRoom()->getRoomNumber();
    // testPatient.setRoom(&testroom1);
    // std::cout << testPatient.getRoom()->getRoomNumber() << std::endl;
    // testPatient.setRoom(&testroom2);
    // std::cout << testPatient.getRoom()->getRoomNumber();

    //testing storing room as a map. also testing ModifyRoomAvailability class.
    /*std::map<int, Room*> roomMap;
    roomMap[testroom1.getRoomNumber()]=&testroom1;
    roomMap[testroom2.getRoomNumber()]=&testroom2;
    ModifyRoomAvailability::bookRoom(testroom1.getRoomNumber(), roomMap);
    std::cout << testroom1.getRoomNumber() << " availability: " << testroom1.getRoomAvailability() << std::endl;*/
    return 0;
};