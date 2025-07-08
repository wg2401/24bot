

#include <cmath>
#include <iostream>
#include "solver.h"

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
        if (std::fabs(check - 24.0) < 1e-6)
        {
            return operationsSoFar;
        }
        else
        {
            return nullptr;
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

            for (int j = 0; j < 4; j++)
            {
                //check for used (covers i = j case)
                if (used[j] == 0)
                {
                    tempJ = nums[j];


                    //prevent duplicate commutative ops
                    if (i<j)
                    {
                        //add and recurse
                        nums[j] = tempI + tempJ;
                        Expression add = {i+1,'q',j+1};
                        operationsSoFar[curStep] = add;
                        potAns = process(nums, used, operationsSoFar, curStep + 1);
                        if (potAns != nullptr)
                        {
                            return potAns;
                        }

                        //multiply and recurse
                        nums[j] = tempI * tempJ;
                        Expression mult = {i+1,'e',j+1};
                        operationsSoFar[curStep] = mult;
                        potAns = process(nums, used, operationsSoFar, curStep + 1);
                        if (potAns != nullptr)
                        {
                            return potAns;
                        }
                    }


                    //nums[i]/nums[j] and recurse
                    if (std::fabs(tempJ) > 1e-9)
                    {
                        nums[j] = tempI/tempJ;
                        Expression div = {i+1, 'r', j+1};
                        operationsSoFar[curStep] = div;
                        potAns = process(nums, used, operationsSoFar, curStep + 1);
                        if (potAns != nullptr)
                        {
                            return potAns;
                        }
                    }

                    nums[j] = tempI - tempJ;
                    Expression minus = {i+1, 'w', j+1};
                    operationsSoFar[curStep] = minus;
                    potAns = process(nums, used, operationsSoFar, curStep + 1);
                    if (potAns != nullptr)
                    {
                        return potAns;
                    }
                    
                    //backtrack
                    nums[j] = tempJ;
                }  
            }

            used[i] = 0;
        }
    }

    return nullptr;
        
}

void printExpressions(Expression* operations)
{
    for (int i = 0; i < 4; i++)
    {
        Expression exp = operations[i];
        std::cout << exp.ind1 << " " << exp.opCode << " " << exp.ind2 << std::endl;

    }
}


