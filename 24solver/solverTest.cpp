#include <iostream>

#include "solver.h"



int main(int argc, char* argv[])
{
    if (argc != 5)
    {
        std::cerr << "should be 4 nums";
        return 1;
    }
    
    double nums[4];
    for (int i = 1; i < 5; i++)
    {
        nums[i - 1] = atof(argv[i]);
    }

    int used[4] = {0,0,0,0};

    Expression operations[3];

    Expression* ans = process(nums, used, operations, 0);

    printExpressions(ans);
    
    return 0;
}