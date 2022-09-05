#pragma once
#include "BaseAccount.h"
class SavingsAccount :
    public BaseAccount
{
public:
    SavingsAccount();
    void withdraw(float amount);
};

