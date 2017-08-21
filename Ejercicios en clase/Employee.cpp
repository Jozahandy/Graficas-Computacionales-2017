#include"Employee.h"
#include <string>

Employee::Employee(int id, std::string firstName, std::string lastName, int salary)
{
	_id = id;
	_firstName = firstName;
	_lastName = lastName;
	_salary = salary;
}

int Employee::GetID()
{
	return _id;
}

std::string Employee::GetFirstName()
{
	return _firstName;
}

std::string Employee::GetLastName()
{
	return _lastName;
}

std::string Employee::GetName()
{
	return (_firstName+ "" + _lastName);
}

int Employee::GetSalary(int salaru)
{
	return _salary;
}

void Employee::SetSalary(int salary)
{
	_salary = salary;
}

int Employee::GetAnnualSalary(int percent)
{
	return _salary * 12;
}

int Employee::RaiseSalary(int percent)
{
	return ((_salary*percent) / 100) + _salary;
}

std::string Employee::Print()
{
	std::string _name;
	_name = _firstName + _lastName;
	return "\n\nID: " + std::to_string(_id) + "\nName: " + _name + "\nSalary: " + std::to_string(_salary);
}
