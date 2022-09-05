#pragma once
class BaseAccount
{
public:
	BaseAccount();
	void withdraw(float amount);
	void deposit(float amount);
	float getbalance() { return balance; }
	void setbalance(float amount);
protected:
	float balance = 0;
	int withdraws = 0;
};

