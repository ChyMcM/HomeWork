#include "CreditAccount.h"
CreditAccount::CreditAccount()
{

}
void CreditAccount::withdraw(float amount)
{
	spent += amount;
	if (amount >= 40)
	{
		balance -= amount + 5000;
	}
	else if (spent >= 40)
	{
		balance -= amount + 5000;
	}
	else
	{
		balance -= amount;
	}
}