#include <iostream>
#include <iomanip>
#include <string>
#include "entity/schedule.h"
#include "boundary/MainMenu.h"
#include "control/MainMenuLogic.h"
#include "boundary/patientInterface.h"
#include "boundary/staffInterface.h"
#include "boundary/inventoryUI.h"
#include "control/GenerateRoomAvailabilityReport.h"
#include "control/ModifyRoomAvailability.h"
#include "control/modifyProcedure.h"
#include "control/TESTMODINV.h"

int main()
{

    MainMenu::StartMenu();
    return 0;
};