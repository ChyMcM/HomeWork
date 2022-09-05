#include "Student.h"
#include "Employee.h"
#include "Base.h"
#include <iostream>
#include <vector>
#include <iostream>
void AddRecord(std::vector<Base*>& v);

void DisplayRecords(std::vector<Base*>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i]->DisplayRecord();
	}
}
void DuplicateRecord(std::vector<Base*>& v)
{
	std::cout << "Which record index would you like to copy? Remember that indexes\nactually start at 0 so the first one you entered will be 0!\n";
	int index;
	std::cin >> index;
	if (dynamic_cast<Student*>(v[index]) != nullptr)
	{
		Student* stu = new Student();
		stu = dynamic_cast<Student*>(v[index]);
		v.push_back(stu);
	}
	else
	{
		Employee* stew = new Employee();
		stew = dynamic_cast<Employee*>(v[index]);
		v.push_back(stew);
	}
}
int main()
{
    std::vector<Base*> recs;
    int choice = 0;
    while (choice != 4)
    {
        std::cout << "What would you like to do?\n1. View Records\n2. Add Record\n3. Duplicate a Record?\n4. Exit\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
			system("cls");
			DisplayRecords(recs);
            break;
        case 2:
            AddRecord(recs);
            break;
        case 3:
			system("cls");
			DuplicateRecord(recs);
            break;
        }
    }
	for (int i = 0; i < recs.size(); i++)
	{
		delete[] recs[i];
	}
    exit(0);
}
void AddRecord(std::vector<Base*>& v)
{
	system("cls");
	std::cout << "What kind of record do you need to add?\n1. Student\n2. Employee\n";
	int whi;
	char* nam = new char[32];
	float grade;
	int money;
	int rec;
	std::cin >> rec;
	if (rec == 1)
	{
		std::cout << "What's the student's gpa?\n";
		std::cin >> grade;
		std::cout << "What's the student's name?\n";
		std::cin.ignore(INT32_MAX, '\n');
		std::cin.getline(nam, 32);
		v.push_back(new Student(nam, grade));
		std::cin.ignore(INT32_MAX, '\n');
	}
	else
	{
		std::cout << "What's the employee's monthly salary?\n";
		std::cin >> money;
		std::cout << "What's the employee's name?\n";
		std::cin.ignore(INT32_MAX, '\n');
		std::cin.getline(nam, 32);
		v.push_back(new Employee(nam, money));
		std::cin.ignore(INT32_MAX, '\n');
	}
}
