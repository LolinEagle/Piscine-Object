#pragma once

#include <header.hpp>
#include <Tool.hpp>
#include <Workshop.hpp>

class Tool;
class Workshop;

class Worker{
private:
	struct Position{
		int	x, y, z;
	};

	struct Statistic{
		int	level, exp;
	};

	Position			_coordonnee;
	Statistic			_stat;
	vector<Tool*>		_tools;
	vector<Workshop*>	_workshops;
public:
	Worker(void);
	~Worker();

	int					getCoordonnee(int i) const;
	int					getStat(int i) const;
	vector<Tool*>		getTools(void) const;
	vector<Workshop*>	getWorkshops(void) const;

	void	takeTool(Tool* tool);
	void	giveBackTool(Tool* tool);
	void	workerRegister(Workshop* workshop);
	void	workerRelease(Workshop* workshop);
	void	work(void);

	template<typename ToolType>
	ToolType*	getTool(void) const {
		for (size_t i = 0; i < _tools.size(); i++){
			if (dynamic_cast<ToolType*>(_tools[i]))
				return (dynamic_cast<ToolType*>(_tools[i]));
		}
		return (NULL);
	}
};
