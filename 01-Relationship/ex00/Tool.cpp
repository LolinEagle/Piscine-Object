#include <Tool.hpp>

Tool::Tool(void): _numberOfUses(0){
	cout << BLUE << "Tool: Constructor called" << ENDL;
}

Tool::~Tool(){
	cout << RED << "Tool: Destructor called" << ENDL;
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
