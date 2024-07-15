#pragma once

#include <Command.hpp>

class PackageReductionDiscountCommand: public Command{
public:
	PackageReductionDiscountCommand(
		const string& date, const string& client, const string& articles
	);
	~PackageReductionDiscountCommand();

	float	getTotalPrice(void);
};

PackageReductionDiscountCommand::PackageReductionDiscountCommand(
	const string& date, const string& client, const string& articles
){
	_date = date;
	_client = client;
	_articles = articles;
}

PackageReductionDiscountCommand::~PackageReductionDiscountCommand(){
}

float	PackageReductionDiscountCommand::getTotalPrice(void){
	float	total_price = Command::getTotalPrice();

	if (total_price >= 150.f)
		total_price -= 10.f;
	return (total_price);
}
