#include <Workshop.hpp>

Workshop::Workshop(void){
	cout << BLUE << "Workshop: Constructor called" << ENDL;
}

Workshop::Workshop(const string& toolType){
	cout << BLUE << "Workshop: Constructor called" << ENDL;
	if (toolType == "Shovel" || toolType == "Hammer")
		_toolType = toolType;
	else
		cout << RED << "Bad tool type" << ENDL;
}

Workshop::~Workshop(){
	cout << RED << "Workshop: Destructor called" << ENDL;
	for (vector<Worker*>::iterator it = _workers.begin(); it != _workers.end(); it++)
		(*it)->workerRelease(this);
}

const string&	Workshop::getToolType(void) const {
	return (_toolType);
}

void	Workshop::workshopRegister(Worker* worker){
	if (find(_workers.begin(), _workers.end(), worker) != _workers.end()){
		cout << YELLOW << "This worker is already registered" << ENDL;
		return ;
	}
	if ((_toolType == "Shovel" && worker->getTool<Shovel>()) ||
		(_toolType == "Hammer" && worker->getTool<Hammer>()) || _toolType.empty()
	){
		_workers.push_back(worker);		// Add worker to workshop
		worker->workerRegister(this);	// Add workshop to worker
		cout << GREEN << "Worker is now registered" << ENDL;
		return ;
	}
	cout << YELLOW << "This worker can't be registered" << ENDL;
}

void	Workshop::workshopRelease(Worker* worker){
	for (vector<Worker*>::iterator it = _workers.begin(); it != _workers.end(); it++){
		if (*it == worker){
			(*it)->workerRelease(this);	// Remove workshop from worker
			_workers.erase(it);			// Remove worker from workshop
			cout << GREEN << "Worker is now released" << ENDL;
			return ;
		}
	}
	cout << YELLOW << "This worker is not registered in this workshop" << ENDL;
}

void	Workshop::executeWorkDay(void){
	for (vector<Worker*>::iterator it = _workers.begin(); it != _workers.end(); it++)
		(*it)->work();
}
