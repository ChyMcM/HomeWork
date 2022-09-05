#pragma once
#include "BaseAccount.h"
class CheckingAccount :
    public BaseAccount
{
public:
    CheckingAccount();
    void withdraw(float amount);
};

