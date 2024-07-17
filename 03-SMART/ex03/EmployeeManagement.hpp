#pragma once

#include <Employee.hpp>

class EmployeeManagement{
private:
	vector<Employee*>	_employees;
public:
	EmployeeManagement(void);
	~EmployeeManagement();

	void	addEmployee(Employee* employee);
	void	removeEmployee(Employee* employee);
	void	executeWorkday(void);
	void	calculatePayroll(void);
};

EmployeeManagement::EmployeeManagement(void){
}

EmployeeManagement::~EmployeeManagement(){
}

void	EmployeeManagement::addEmployee(Employee* employee){
	_employees.push_back(employee);
}

void	EmployeeManagement::removeEmployee(Employee* employee){
	vector<Employee*>::iterator it = find(_employees.begin(), _employees.end(), employee);
	if (it != _employees.end())
		_employees.erase(it);
}

void	EmployeeManagement::executeWorkday(void){
	for (vector<Employee*>::iterator it = _employees.begin(); it != _employees.end(); it++)
		(*it)->executeWorkday();
}

void	EmployeeManagement::calculatePayroll(void){
	for (vector<Employee*>::iterator it = _employees.begin(); it != _employees.end(); it++){
		int	totalHours = (*it)->getTotalHoursWorked();
		int	hourlyValue = (*it)->getHourlyValue();

		cout << "Employee monthly pay: " << totalHours * hourlyValue << endl;
	}
}
