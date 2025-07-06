

#include <cmath>


struct Expression {
    int ind1;
    char opCode;
    int ind2;
};

Expression* process(double* nums, int* used, Expression* operationsSoFar, int curStep)
{
    //base case check
    if (curStep == 3)
    {
        double check = 0;
        for (int i = 0; i < 4; i++)
        {
            if (used[i] == 0)
            {
                check = nums[i];
                break;
            }
        }

        // check for approx val to account for floating pt precision error
        if (abs(check - 24.0) < 1e-6)
        {
            return operationsSoFar;
        }
        else
        {
            return 0;
        }
    }

    double tempI, tempJ;
    Expression* potAns;

    for (int i = 0; i < 4; i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            tempI = nums[i];

            
        }
    }
        
}


