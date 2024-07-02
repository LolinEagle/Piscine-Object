#include <Workshop.hpp>

Workshop::Workshop(void){
	cout << BLUE << "Workshop: Constructor called" << ENDL;
}

Workshop::Workshop(const string& toolType){
	cout << BLUE << "Workshop: Constructor called" << ENDL;
	if (toolType == "Shovel" || toolType == "Shovel")
		_toolType = toolType;
}

Workshop::~Workshop(){
	cout << RED << "Workshop: Destructor called" << ENDL;
}

void	Workshop::workshopRegister(Worker* worker){
	for (vector<Worker*>::iterator it = _Workers.begin(); it != _Workers.end(); it++){
		if (*it == worker){
			cout << YELLOW << "This worker is already registered" << ENDL;
			return ;
		}
	}
	if ((_toolType == "Shovel" && worker->getTool<Shovel>()) ||
		(_toolType == "Hammer" && worker->getTool<Hammer>()) || _toolType.empty()
	){
		_Workers.push_back(worker);
		worker->setWorkshop(this);
		cout << GREEN << "Worker is now registered" << ENDL;
		return ;
	}
	cout << YELLOW << "This worker can't be registered" << ENDL;
}

void	Workshop::workshopRelease(Worker* worker){
	for (vector<Worker*>::iterator it = _Workers.begin(); it != _Workers.end(); it++){
		if (*it == worker){
			_Workers.erase(it);
			cout << GREEN << "Worker is now released" << ENDL;
			return ;
		}
	}
	cout << YELLOW << "This worker is not registered in this workshop" << ENDL;
}

void	Workshop::executeWorkDay(void){
	for (vector<Worker*>::iterator it = _Workers.begin(); it != _Workers.end(); it++)
		(*it)->work();
}
