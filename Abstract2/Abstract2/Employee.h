#pragma once
#include "Base.h"
class Employee :
    public Base
{
private:
    int sal = 0;
public:
    Employee();
    Employee(char* nam, int mon);
    void SetSal(int incentive);
    int GetSal() { return sal; }
    void DisplayRecord();
};

