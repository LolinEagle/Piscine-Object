#pragma once

#include <header.hpp>
#include <Worker.hpp>

class Worker;

class Workshop{
private:
	vector<Worker*>	_workers;
	string			_toolType;
public:
	Workshop(void);
	Workshop(const string& toolType);
	~Workshop();

	const string&	getToolType(void) const;

	void	workshopRegister(Worker* worker);
	void	workshopRelease(Worker* worker);
	void	executeWorkDay(void);
};
