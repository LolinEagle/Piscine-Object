#pragma once

#include <iostream>
#include <sstream>

using namespace std;

size_t id = 0;

class Command{
protected:
	size_t	_id;
	string	_date;
	string	_client;
	string	_articles;
public:
	Command(void);
	Command(const string& date, const string& client, const string& articles);
	~Command();

	void	printAll(void);
	float	getTotalPrice(void);
};

Command::Command(void){
	_id = id++;
}

Command::Command(const string& date, const string& client, const string& articles){
	_id = id++;
	_date = date;
	_client = client;
	_articles = articles;
}

Command::~Command(){
}

void	Command::printAll(void){
	cout << "Id : " << _id << '\n' << "Date : " << _date << '\n' << "Client : " <<
			_client << '\n' << "Articles : " << _articles << endl;
}

float	Command::getTotalPrice(void){
	istringstream	iss(_articles);
	string			token;
	float			total_price = 0;

	iss >> token;
	while (token.empty() == false){
		if (token == "Shiromaru")
			total_price += 14.f;
		else if (
			token == "Akamaru" || token == "Karaka" || token == "Tori_Shoyu" || token == "Veggie"
		)
			total_price += 15.f;
		else
			cout << token << " are not on the menu." << endl;
		token.clear();
		iss >> token;
	}
	return (total_price);
}
