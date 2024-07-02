#pragma once

#include <header.hpp>
#include <Worker.hpp>

class Worker;

class Tool{
protected:
	unsigned int	_numberOfUses;
	Worker*			_worker;
public:
	Tool(void);
	virtual ~Tool();

	virtual void		use(void) = 0;

	virtual const char*	getType(void) const = 0;
	Worker*				getWorker(void) const {return (_worker);}
	void				setWorker(Worker* worker){_worker = worker;}
};

class Shovel: public Tool{
public:
	Shovel(void);
	~Shovel();

	void		use(void);

	const char*	getType(void) const {return ("Shovel");}
};

class Hammer: public Tool{
public:
	Hammer(void);
	~Hammer();

	void		use(void);

	const char*	getType(void) const {return ("Hammer");}
};
