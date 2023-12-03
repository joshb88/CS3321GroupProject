#ifndef ORDER_PROCEDURES_H
#define ORDER_PROCEDURES_H

#include <queue>
#include "entity/procedure.h"

class OrderProcedures {
private:
    std::queue<Procedure> procedureQueue;

public:
    OrderProcedures();
    void addProcedureToQueue(const Procedure& procedure);
    Procedure getNextProcedure();
    void completeProcedure();
    void displayProcedureQueue();
};

#endif 
