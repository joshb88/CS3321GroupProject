 # include "control/generateBill.h"


float generateBill::calculateTotal(std::vector<float> cost_vec)
{
    for(int i = 0; i < cost_vec.size(); i++)
    {
        total += cost_vec[i];
    }
    return total;
}