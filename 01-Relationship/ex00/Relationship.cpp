#include <Relationship.hpp>

// Composition

Worker::Worker(void): _tool(NULL){
	cout << BLUE << "Worker: Constructor called" << ENDL;
}

Worker::~Worker(){
	cout << RED << "Worker: Destructor called" << ENDL;
}

void	Worker::takeTool(Tool* tool){
	if (_tool == NULL){
		tool->setWorker(this);
		_tool = tool;
		cout << "Worker take a tool" << endl;
	}
}

void	Worker::giveTool(void){
	if (_tool != NULL){
		_tool->setWorker(NULL);
		_tool = NULL;
		cout << "Worker give back a tool" << endl;
	}
}

void	Worker::work(void){
	cout << "Working" << endl;
}

// Aggregation & Inherence

Tool::Tool(void): _numberOfUses(0){
	cout << BLUE << "Tool: Constructor called" << ENDL;
}

Tool::~Tool(){
	cout << RED << "Tool: Destructor called" << ENDL;
}

void	Tool::use(void){
}

Shovel::Shovel(void){
	cout << BLUE << "Shovel: Constructor called" << ENDL;
}

Shovel::~Shovel(){
	cout << RED << "Shovel: Destructor called" << ENDL;
}

void	Shovel::use(void){
	_numberOfUses++;
	cout << "Shovel is use" << endl;
}

Hammer::Hammer(void){
	cout << BLUE << "Hammer: Constructor called" << ENDL;
}

Hammer::~Hammer(){
	cout << RED << "Hammer: Destructor called" << ENDL;
}

void	Hammer::use(void){
	_numberOfUses++;
	cout << "Hammer is use" << endl;
}

// Association

Workshop::Workshop(void){
	cout << BLUE << "Workshop: Constructor called" << ENDL;
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
	_Workers.push_back(worker);
	cout << GREEN << "Worker is now registered" << ENDL;
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
