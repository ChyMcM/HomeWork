#include "Student.h"
#include "Employee.h"
#include "Base.h"
#include <iostream>
Student::Student()
{

}
Student::Student(char* nam, float grad)
{
	SetName(nam);
	gpa = grad;
}
void Student::SetGPA(float grade)
{
	gpa = grade;
}
void Student::DisplayRecord()
{
	std::cout << "\nStudent:\n\tName:\t" << GetName() << "\n\tGPA:\t" << GetGPA()<<"\n";
}