#pragma once
#include "BaseAccount.h"
class CreditAccount :
    public BaseAccount
{
private:
    int spent;
public:
    CreditAccount();
    void withdraw(float amount);
};

