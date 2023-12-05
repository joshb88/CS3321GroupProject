#include "entity/procedure.h"
#include "entity/inventory.h"
#include <string>

class ModifyProcedure
{
    public:
        static bool procedureInDatabase(Procedure& procedure);
        static bool procedureInDatabase(std::string& procedure_name);
        static void writeProcedureToDatabase(Procedure& procedure);
        static Procedure readProcedureFromDatabase(const std::string& procedure_name);
        static std::string serializeItemsUsed(const std::vector<Inventory>& itemsUsed);
        static std::vector<Inventory> deserializeItemsUsed(const std::string& serializedList);
        //static void changeProcedure(Procedure& procedure);
};