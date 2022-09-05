#pragma once
#include "Base.h"
class Student :
    public Base
{
private:
    float gpa = 0;
public:
    Student();
    Student(char* nam, float grad);
    void SetGPA(float grade);
    float GetGPA() { return gpa; }
    void DisplayRecord();
};

