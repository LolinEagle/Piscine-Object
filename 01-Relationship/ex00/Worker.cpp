#include <Worker.hpp>

Worker::Worker(void){
	cout << BLUE << "Worker: Constructor called" << ENDL;
	_coordonnee.x = 0;
	_coordonnee.y = 0;
	_coordonnee.z = 0;
	_stat.level = 1;
	_stat.exp = 0;
}

Worker::~Worker(){
	cout << RED << "Worker: Destructor called" << ENDL;
	for (vector<Tool*>::iterator it = _tools.begin(); it != _tools.end(); it++)
		(*it)->setWorker(NULL);
	for (vector<Workshop*>::iterator it = _workshops.begin(); it != _workshops.end(); it++)
		(*it)->workshopRelease(this);
}

int					Worker::getCoordonnee(int i) const{
	if (i == 0) return (_coordonnee.x);
	if (i == 1) return (_coordonnee.y);
	if (i == 2) return (_coordonnee.z);
	throw (runtime_error("Bad index"));
}

int					Worker::getStat(int i) const{
	if (i == 0) return (_stat.level);
	if (i == 1) return (_stat.exp);
	throw (runtime_error("Bad index"));
}

vector<Tool*>		Worker::getTools(void) const{
	return (_tools);
}

vector<Workshop*>	Worker::getWorkshops(void) const{
	return (_workshops);
}

void	Worker::takeTool(Tool* tool){
	// If tool is null
	if (!tool){
		cout << YELLOW << "Worker can't take this tool" << ENDL;
		return ;
	}

	// Find if worker already have this tool
	if (find(_tools.begin(), _tools.end(), tool) != _tools.end()){
		cout << YELLOW << "Worker already have this tool" << ENDL;
		return ;
	}

	if (tool->getWorker()) tool->getWorker()->giveBackTool(tool);// Remove from last worker
	tool->setWorker(this);	// Add worker to tool
	_tools.push_back(tool);	// Add tool to worker
	cout << GREEN << "Worker take a tool" << ENDL;
}

void	Worker::giveBackTool(Tool* tool){
	// If tool is null of tool don't have worker
	if (!tool && !tool->getWorker()){
		cout << YELLOW << "Worker can't give back this tool" << ENDL;
		return ;
	}

	vector<Tool*>::iterator it = find(_tools.begin(), _tools.end(), tool);
	if (it != _tools.end()) _tools.erase(it);	// Remove tool from worker
	tool->setWorker(NULL);						// Remove worker from tool
	cout << "Worker give back a tool" << endl;

	// Check if worker should leave the workshops
	for (vector<Workshop*>::iterator it = _workshops.begin(); it != _workshops.end(); it++){
		if ((*it)->getToolType().empty() == false){// If workshop have tool type
			// If worker don't have the good tool type anymore
			if (((*it)->getToolType() == "Shovel" && !getTool<Shovel>()) ||
				((*it)->getToolType() == "Hammer" && !getTool<Hammer>())
			)
				(*it)->workshopRelease(this);
		}
	}
}

void	Worker::workerRegister(Workshop* workshop){
	if (find(_workshops.begin(), _workshops.end(), workshop) != _workshops.end())
		_workshops.push_back(workshop);
}

void	Worker::workerRelease(Workshop* workshop){
	vector<Workshop*>::iterator it = find(_workshops.begin(), _workshops.end(), workshop);
	if (it != _workshops.end()) _workshops.erase(it);
}

void	Worker::work(void){
	cout << this << " is working" << endl;
}
