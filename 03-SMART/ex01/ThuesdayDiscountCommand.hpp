#pragma once

#include <Command.hpp>

class ThuesdayDiscountCommand: public Command{
public:
	ThuesdayDiscountCommand(const string& date, const string& client, const string& articles);
	~ThuesdayDiscountCommand();

	float	getTotalPrice(void);
};

ThuesdayDiscountCommand::ThuesdayDiscountCommand(
	const string& date, const string& client, const string& articles
){
	_date = date;
	_client = client;
	_articles = articles;
}

ThuesdayDiscountCommand::~ThuesdayDiscountCommand(){
}

float	ThuesdayDiscountCommand::getTotalPrice(void){
	float	total_price = Command::getTotalPrice();

	if (_date.find("Thuesday") != string::npos)
		total_price = total_price * .9f;
	return (total_price);
}
