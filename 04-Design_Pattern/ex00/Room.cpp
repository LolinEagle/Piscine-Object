#include <Room.hpp>

Room::Room(void){
	static size_t id = 0;

	_id = id++;
}

bool	Room::canEnter(Person* person){
	if (find(_occupants.begin(), _occupants.end(), person) == _occupants.end())
		return (true);
	return (false);
}

void	Room::enter(Person* person){
	if (find(_occupants.begin(), _occupants.end(), person) == _occupants.end())
		_occupants.push_back(person);
}

void	Room::exit(Person* person){
	auto	it = find(_occupants.begin(), _occupants.end(), person);
	if (it != _occupants.end())
		_occupants.erase(it);
}

void	Room::printOccupant(void){
	for (auto occupants: _occupants)
		cout << occupants->getName() << endl;
}

void			SecretarialOffice::addForm(Form* form){
	if (find(_archivedForms.begin(), _archivedForms.end(), form) == _archivedForms.end())
		_archivedForms.push_back(form);
}
