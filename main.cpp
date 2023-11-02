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
    Room testroom1(101, 5, true);
    Room testroom2(303, 2, true);
    Patient testPatient;

    //std::cout << testPatient.getRoom()->getRoomNumber();
    testPatient.setRoom(&testroom1);
    std::cout << testPatient.getRoom()->getRoomNumber();
    testPatient.setRoom(&testroom2);
    std::cout << testPatient.getRoom()->getRoomNumber();
    return 0;
};