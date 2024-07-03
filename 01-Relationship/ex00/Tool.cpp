#include <Tool.hpp>

Tool::Tool(void): _numberOfUses(0), _worker(NULL){
	cout << BLUE << "Tool: Constructor called; " << RESET;
}

Tool::~Tool(){
	cout << RED << "Tool: Destructor called" << ENDL;
}

Shovel::Shovel(void){
	cout << BLUE << "Shovel: Constructor called" << ENDL;
}

Shovel::~Shovel(){
	if (_worker) _worker->giveBackTool();
	cout << RED << "Shovel: Destructor called; " << RESET;
}

void	Shovel::use(void){
	_numberOfUses++;
	cout << "Shovel is use" << endl;
}

Hammer::Hammer(void){
	cout << BLUE << "Hammer: Constructor called" << ENDL;
}

Hammer::~Hammer(){
	if (_worker) _worker->giveBackTool();
	cout << RED << "Hammer: Destructor called; " << RESET;
}

void	Hammer::use(void){
	_numberOfUses++;
	cout << "Hammer is use" << endl;
}
