#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Employee{
protected:
	int	_hourlyValue;
	int	_totalHoursWorked;
public:
	Employee(int hourlyValue): _hourlyValue(hourlyValue), _totalHoursWorked(0){}
	~Employee(){};

	void	executeWorkday(void){
		_totalHoursWorked += 7;
	}

	int		getTotalHoursWorked(void) const{
		return (_totalHoursWorked);
	}
	int		getHourlyValue(void) const{
		return (_hourlyValue);
	}
};

class TempWorker: public Employee{
public:
	TempWorker(int hourlyValue): Employee(hourlyValue){}

	void	mobilize(int hours){
		_totalHoursWorked += hours;
	}
};

class ContractEmployee: public Employee{
private:
	int	_totalVacationHours;
public:
	ContractEmployee(int hourlyValue): Employee(hourlyValue), _totalVacationHours(0){}

	void	logVacation(int hours){
		_totalVacationHours += hours;
	}

	int		getTotalVacationHours(void) const{
		return (_totalVacationHours);
	}
};

class Apprentice: public ContractEmployee{
private:
	int	_totalSchoolHours;
public:
	Apprentice(int hourlyValue): ContractEmployee(hourlyValue), _totalSchoolHours(0){}

	void	logSchoolHours(int hours){
		_totalSchoolHours += hours;
	}

	int		getTotalSchoolHours(void) const{
		return (_totalSchoolHours);
	}
};
