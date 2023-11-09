#include <iostream>
#include <iomanip>
#include "entity/schedule.h"
#include "control/storedata.h"
//#include "control/GenerateRoomAvailabilityReport.h"
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
    User testPatient1("test_login1","test_password1","test_last1","test_first1",19880814,'M');
    User testPatient2("test_login2","test_password2","test_last2","test_first2",19880815,'F');
    User testPatient3("test_login3","test_password3","test_last3","test_first3",19880816,'X');
    User testPatient4("test_login4","test_password4","test_last4","test_first4",19880817,'X');

    StoreData::storeUser(testPatient1);
    StoreData::storeUser(testPatient2);
    StoreData::storeUser(testPatient3);
    StoreData::storeUser(testPatient4);

    //std::cout << testPatient.getRoom()->getRoomNumber();
    // testPatient.setRoom(&testroom1);
    // std::cout << testPatient.getRoom()->getRoomNumber() << std::endl;
    // testPatient.setRoom(&testroom2);
    // std::cout << testPatient.getRoom()->getRoomNumber();

    return 0;
};