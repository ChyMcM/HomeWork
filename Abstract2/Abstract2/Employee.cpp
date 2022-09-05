#include "Employee.h"
#include "Base.h"
#include <iostream>
Employee::Employee()
{

}
Employee::Employee(char* nam, int mon)
{
	SetName(nam);
	sal = mon;
}
void Employee::SetSal(int incentive)
{
	sal = incentive;
}
void Employee::DisplayRecord()
{
	std::cout << "\nEmployee:\n\tName:\t" << GetName() << "\n\tSalary:\t" << GetSal()<<"\n";
}