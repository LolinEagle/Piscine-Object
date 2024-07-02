#include <Worker.hpp>

Worker::Worker(void): _tool(NULL), _workshop(NULL){
	cout << BLUE << "Worker: Constructor called" << ENDL;
}

Worker::~Worker(){
	cout << RED << "Worker: Destructor called" << ENDL;
}

void	Worker::takeTool(Tool* tool){
	if (_tool == NULL){
		if (tool->getWorker()) tool->getWorker()->setTool(NULL);// Remove from last worker
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
		if (_workshop && !_workshop->getToolType().empty()){
			_workshop->workshopRelease(this);
			_workshop = NULL;
		}
	}
}

void	Worker::work(void){
	cout << "Working" << endl;
}
