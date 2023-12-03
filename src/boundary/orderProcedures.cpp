#include "boundary/orderProcedures.h"
#include <iostream>

OrderProcedures::OrderProcedures() {
    // Constructor implementation can initialize any necessary members.
}

void OrderProcedures::addProcedureToQueue(const Procedure& procedure) {
    procedureQueue.push(procedure);
    std::cout << "Procedure " << procedure.getProcedureName() << " has been added to the queue." << std::endl;
}

Procedure OrderProcedures::getNextProcedure() {
    if (!procedureQueue.empty()) {
        Procedure nextProcedure = procedureQueue.front();
        return nextProcedure;
    } else {
        throw std::runtime_error("The procedure queue is empty.");
    }
}

void OrderProcedures::completeProcedure() {
    if (!procedureQueue.empty()) {
        std::cout << "Procedure " << procedureQueue.front().getProcedureName() << " is completed." << std::endl;
        procedureQueue.pop();
    } else {
        std::cout << "There are no procedures to complete." << std::endl;
    }
}

void OrderProcedures::displayProcedureQueue() {
    std::queue<Procedure> tmpQueue = procedureQueue;
    std::cout << "Procedures in Queue:\n";
    while (!tmpQueue.empty()) {
        std::cout << tmpQueue.front().getProcedureName() << std::endl;
        tmpQueue.pop();
    }
}
