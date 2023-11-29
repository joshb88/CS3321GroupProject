#include "boundary/viewBill.h"

void viewBill::displayBillInformation(){
    //obtain info from generateBill class and display
    billGenerator.displayPatientInfo(patient);
    billGenerator.displayProcedures(procedures);

}