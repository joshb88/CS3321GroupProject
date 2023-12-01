#include "boundary/viewBill.h"

void viewBill::displayBillInformation(){
    //obtain info from generateBill class and display
    billGenerator.displayPatientInfo(Patient patient);
    billGenerator.displayProcedures(Procedure procedures);

}