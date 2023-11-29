#include <iostream>
#include <iomanip>
#include "entity/schedule.h"
#include "control/storedata.h"
#include "boundary/userinterface.h"
#include "control/LoginVerification.h"
//#include "control/GenerateRoomAvailabilityReport.h"
//#include "control/ModifyRoomAvailability.h"

/* 
There is a chain of includes that are all satisfied by calling "schedule.h".
These include the contents of the header/entity/ folder, <string>, <vector>, and
<chrono>.
*/

int main()
{
    MainMenu::StartMenu();
    // Room testroom1(101, 5, true);
    // Room testroom2(303, 2, true);
    // User testPatient1("test_login1","test_password1","test_last1","test_first1",19880814,'M');
    // User testPatient2("test_login2","test_password2","test_last2","test_first2",19880815,'F');
    // User testPatient3("test_login3","test_password3","test_last3","test_first3",19880816,'X');
    // User testPatient4("test_login4","test_password4","test_last4","test_first4",19880817,'X');
    // Patient test_patient1("patient_test1","patient_pw1", "patient_last", "patient_first",20231031,'F',false,"n/a",&testroom2);
    // Patient test_patient2;
    //test_patient1.setRoom(testroom2);

    // StoreData::storeUser(testPatient1);
    // StoreData::storeUser(testPatient2);
    // StoreData::storeUser(testPatient3);
    // StoreData::storeUser(testPatient4);
    // StoreData::storeUser(test_patient1);
    // StoreData::storeUser(test_patient2);

    //LoginVerification::userInDatabase(testPatient1);

    //std::cout << testPatient.getRoom()->getRoomNumber();
    // testPatient.setRoom(&testroom1); 
    // std::cout << testPatient.getRoom()->getRoomNumber() << std::endl;
    // testPatient.setRoom(&testroom2);
    // std::cout << testPatient.getRoom()->getRoomNumber();

    return 0;
};