#pragma once

#include <Datas.hpp>
#include <mutex>
#include <thread>

using namespace std;

template<typename T, class C>
class Singetons{
protected:
	vector<T*>		_list;
	static C*		_instance;
	static mutex	_mutex;

	Singetons(void){}
	~Singetons(){}
public:
	Singetons(const Singetons &copy) = delete;
	void	operator=(const Singetons &copy) = delete;

	vector<T*>	getList(void) const {return (_list);}
	static C*	getInstance(void);

	void	addList(T* list);
	void	removeList(T* list);
};

template<typename T, class C>
C*	Singetons<T, C>::_instance = NULL;

template<typename T, class C>
mutex				Singetons<T, C>::_mutex;

template<typename T, class C>
C*	Singetons<T, C>::getInstance(void){
	lock_guard<mutex>	lock(_mutex);
	if (_instance == NULL)
		_instance = new C();
	return (_instance);
}

template<typename T, class C>
void	Singetons<T, C>::addList(T* list){
	if (find(_list.begin(), _list.end(), list) == _list.end())
		_list.push_back(list);
}

template<typename T, class C>
void	Singetons<T, C>::removeList(T* list){
	auto	it = find(_list.begin(), _list.end(), list);
	if (it != _list.end())
		_list.erase(it);
}
