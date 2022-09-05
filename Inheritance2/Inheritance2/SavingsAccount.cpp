#include "SavingsAccount.h"
#include <iostream>
SavingsAccount::SavingsAccount()
{

}
void SavingsAccount::withdraw(float amount)
{
	if (withdraws == 3)
	{
		std::cout << "Your savings account only allows 3 withdraws.  You may not withdraw anymore at this time.";
	}
	else
	{
		balance -= amount;
		withdraws++;
	}
}