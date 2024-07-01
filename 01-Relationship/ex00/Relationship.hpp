#pragma once

#include <iostream>
#include <vector>

#define RED		"\33[31m"
#define GREEN	"\33[32m"
#define YELLOW	"\33[33m"
#define BLUE	"\33[34m"
#define ENDL	"\33[00m" << endl

using namespace std;

class Tool;

// Composition

struct Position{
	int	x;
	int	y;
	int	z;
};

struct Statistic{
	int	level;
	int	exp;
};

class Worker{
private:
	Position	_coordonnee;
	Statistic	_stat;
	Tool*		_tool;
public:
	Worker(void);
	~Worker();

	Position	getCoordonnee(void) const{return (_coordonnee);}
	Statistic	getStat(void) const{return (_stat);}
	void		takeTool(Tool* tool);
	void		giveTool(void);
	void		work(void);

    template<typename ToolType>
    ToolType* GetTool() const {
        if (_tool && dynamic_cast<ToolType*>(_tool)) {
            return dynamic_cast<ToolType*>(_tool);
        }
        return (NULL);
    }
};

// Aggregation & Inherence

class Tool{
protected:
	unsigned int	_numberOfUses;
	Worker*			_worker;
public:
	Tool(void);
	virtual ~Tool();

	virtual void		use(void) = 0;
	virtual const char*	getType(void) const = 0;
	void				setWorker(Worker* worker){_worker = worker;}
};

class Shovel: public Tool{
public:
	Shovel(void);
	~Shovel();

	void		use(void);
	const char*	getType(void) const{return ("Shovel");}
};

class Hammer: public Tool{
public:
	Hammer(void);
	~Hammer();

	void		use(void);
	const char*	getType(void) const{return ("Hammer");}
};

// Association

class Workshop{
private:
	vector<Worker*>	_Workers;
public:
	Workshop(void);
	~Workshop();

	void	workshopRegister(Worker* worker);
	void	workshopRelease(Worker* worker);
	void	executeWorkDay(void);
};
