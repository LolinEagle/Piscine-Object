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

	Worker*			getWorker(void) const;
	void			setWorker(Worker* worker);

	virtual void	use(void) = 0;
};

class Shovel: public Tool{
public:
	Shovel(void);
	~Shovel();

	void		use(void);
};

class Hammer: public Tool{
public:
	Hammer(void);
	~Hammer();

	void		use(void);
};
