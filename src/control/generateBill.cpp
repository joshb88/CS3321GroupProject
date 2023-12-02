 # include "control/generateBill.h"


float generateBill::calculateTotal(std::vector<float> cost_vec)
{
    float total_1; 
    for(int i = 0; i < cost_vec.size(); i++)
    {
        total_1 += cost_vec[i];
    }
    return total_1;
}