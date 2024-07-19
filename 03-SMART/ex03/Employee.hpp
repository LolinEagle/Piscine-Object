#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Employee{
protected:
	int		_hourlyValue;
	float	_totalHoursWorked;
public:
	Employee(int hourlyValue): _hourlyValue(hourlyValue), _totalHoursWorked(0){}
	~Employee(){};

	virtual void	executeWorkday(void) = 0;
	int				getHourlyValue(void) const{return (_hourlyValue);}
	float			getTotalHoursWorked(void) const{return (_totalHoursWorked);}
};

class TempWorker: public Employee{
private:
	int	_totalMobilizeHours;
public:
	TempWorker(int hourlyValue): Employee(hourlyValue), _totalMobilizeHours(0){}

	void	executeWorkday(void){
		if (_totalMobilizeHours >= 7){
			_totalHoursWorked += 7;
			_totalMobilizeHours -= 7;
		} else if (_totalMobilizeHours){
			_totalHoursWorked += _totalMobilizeHours;
			_totalMobilizeHours = 0;
		}
	}
	void	mobilize(int hours){_totalMobilizeHours += hours;}
};

class ContractEmployee: public Employee{
protected:
	int	_totalVacationHours;
public:
	ContractEmployee(int hourlyValue): Employee(hourlyValue), _totalVacationHours(0){}

	void	executeWorkday(void){
		if (_totalVacationHours >= 7){
			_totalVacationHours -= 7;
		} else if (_totalVacationHours){
			_totalHoursWorked += 7 - _totalVacationHours;
			_totalVacationHours = 0;
		} else {
			_totalHoursWorked += 7;
		}
	}
	void	logVacation(int hours){_totalVacationHours += hours;}
};

class Apprentice: public ContractEmployee{
private:
	float	_totalSchoolHours;
public:
	Apprentice(int hourlyValue): ContractEmployee(hourlyValue), _totalSchoolHours(0){}

	void	executeWorkday(void){
		if (_totalVacationHours >= 7){
			_totalVacationHours -= 7;
		} else if (_totalSchoolHours >= 7){
			_totalHoursWorked += 3.5f;
			_totalSchoolHours -= 7;
		} else if (_totalSchoolHours){
			_totalHoursWorked += 7 - (_totalSchoolHours / 2);
			_totalSchoolHours = 0;
		} else {
			_totalHoursWorked += 7;
		}
	}
	void	logSchoolHours(int hours){_totalSchoolHours += hours;}
};
