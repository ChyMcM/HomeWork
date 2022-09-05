#include "Base.h"
#include <iostream>
Base::Base()
{

}
Base::~Base()
{

}
Base::Base(Base& other)
{
	SetName(other.name);
}
Base& Base:: operator=(Base& other)
{
	if (this != &other)
	{
		SetName(other.name);
	}
	return *this;
}
void Base::SetName(char* nam)
{
	name = nam;
}