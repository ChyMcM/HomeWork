#pragma once
class Base
{
private:
	char* name = nullptr;
public:
	Base();
	~Base();
	Base(Base& other);
	Base& operator=(Base& other);
	virtual void DisplayRecord() = 0;
	void SetName(char* nam);
	const char* GetName() { return name; }
};

