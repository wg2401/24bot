#pragma once

struct Expression {
    int ind1;
    char opCode;
    int ind2;
};


Expression* process(double* nums, int* used, Expression* operationsSoFar, int curStep);