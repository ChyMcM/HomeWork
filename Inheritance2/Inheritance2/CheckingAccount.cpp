#include "CheckingAccount.h"
CheckingAccount::CheckingAccount()
{

}
void CheckingAccount::withdraw(float amount)
{
	if (withdraws > 10)
	{
		balance -= amount + 5;
		withdraws++;
	}
	else
	{
		balance -= amount;
		withdraws++;
	}
}