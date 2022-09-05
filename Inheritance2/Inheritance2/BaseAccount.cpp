#include "BaseAccount.h"
#pragma
BaseAccount::BaseAccount()
{

}
void BaseAccount::setbalance(float amount)
{
	balance = amount;
}
void BaseAccount::withdraw(float amount)
{
	balance -= amount;
}
void BaseAccount::deposit(float amount)
{
	balance += amount;
}