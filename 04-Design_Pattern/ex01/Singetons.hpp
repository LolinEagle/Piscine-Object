#pragma once

#include <Datas.hpp>

using namespace std;

template <typename List>
class Singetons{
private:
	vector<List*>	_list;
public:
	Singetons(void){}
	~Singetons(){}

	Singetons(const Singetons &copy) = delete;
	void	operator=(const Singetons &copy) = delete;

	vector<List*>	getList(void) const{
		return (_list);
	}
	void			addList(List* list){
		if (find(_list.begin(), _list.end(), list) == _list.end())
			_list.push_back(list);
	}
	void			removeList(List* list){
		(void)list;
		// vector<List*>::iterator	it = find(_list.begin(), _list.end(), list);
		// if (it != _list.end())
		// 	_list.erase(it);
	}
};
