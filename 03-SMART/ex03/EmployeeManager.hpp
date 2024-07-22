#pragma once

#include <Employee.hpp>

class EmployeeManager{
private:
	vector<Employee*>	_employees;
public:
	EmployeeManager(void);
	~EmployeeManager();

	void	addEmployee(Employee* employee);
	void	removeEmployee(Employee* employee);
	void	executeWorkday(void);
	void	calculatePayroll(void);
};

EmployeeManager::EmployeeManager(void){
}

EmployeeManager::~EmployeeManager(){
}

void	EmployeeManager::addEmployee(Employee* employee){
	_employees.push_back(employee);
}

void	EmployeeManager::removeEmployee(Employee* employee){
	vector<Employee*>::iterator it = find(_employees.begin(), _employees.end(), employee);
	if (it != _employees.end())
		_employees.erase(it);
}

void	EmployeeManager::executeWorkday(void){
	for (vector<Employee*>::iterator it = _employees.begin(); it != _employees.end(); it++)
		(*it)->executeWorkday();
}

void	EmployeeManager::calculatePayroll(void){
	for (vector<Employee*>::iterator it = _employees.begin(); it != _employees.end(); it++){
		float	totalHours = (*it)->getTotalHoursWorked();
		int		hourlyValue = (*it)->getHourlyValue();

		cout << "Employee pay: " << totalHours * hourlyValue << endl;
	}
}
