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

	Position	_coordonnee;
	Statistic	_stat;

	Tool*		_tool;
	Workshop*	_workshop;
public:
	Worker(void);
	~Worker();

	Position	getCoordonnee(void) const {return (_coordonnee);}
	Statistic	getStat(void) const {return (_stat);}
	Tool*		getTool(void) const {return (_tool);}
	void		setTool(Tool* tool){_tool = tool;}
	void		setWorkshop(Workshop* workshop){_workshop = workshop;}

	void		takeTool(Tool* tool);
	void		giveBackTool(void);
	void		work(void);

	template<typename ToolType>
	ToolType*	getTool(void) const {
		if (_tool && dynamic_cast<ToolType*>(_tool))
			return (dynamic_cast<ToolType*>(_tool));
		return (NULL);
	}
};
