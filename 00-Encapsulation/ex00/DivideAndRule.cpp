#include <DivideAndRule.hpp>

Bank::Account::Account(int initalId, int initalValue): _id(initalId), _value(initalValue){
}

Bank::Bank(void): _idIterator(0), _liquidity(0){
	cout << "Bank is create with liquidity of 0" << endl;
}

Bank::Bank(int initalLiquidity): _idIterator(0), _liquidity(initalLiquidity){
	cout << "Bank is create with liquidity of " << _liquidity << endl;
}

const Bank::Account&	Bank::operator[](int id){
	if (id < 0 || id >= _idIterator)
		throw (out_of_range("out_of_range"));
	return (_clientAccounts[id]);
}

ostream&	operator<<(ostream& p_os, const Bank& p_bank){
	p_os << "Number of account:" << p_bank._idIterator << endl;
	p_os << "Liquidity:" << p_bank._liquidity;
	for (int i = 0; i < p_bank._idIterator; i++)
		p_os << '\n' << p_bank._clientAccounts[i];
	return (p_os);
}

void	Bank::createAccount(int initalValue){
	int		inflow = initalValue / 20;
	Account	account(_idIterator++, initalValue - inflow);

	_liquidity += inflow;
	_clientAccounts.push_back(account);
	cout << "Account " << account._id << " is create with liquidity of " << account._value <<
			" bank take " << inflow << endl;
}

void	Bank::deleteAccount(int id){
	if (id < 0 || id >= _idIterator)
		throw (out_of_range("out_of_range"));
	_liquidity += _clientAccounts[id]._value;
	cout << "Account " << id << " is delete bank take " << _clientAccounts[id]._value << endl;
	_clientAccounts.erase(_clientAccounts.begin() + id);
	_idIterator--;
	for (vector<Account>::iterator it = _clientAccounts.begin() + id;
	it != _clientAccounts.end(); it++)
		(*it)._id--;
}

void	Bank::addValueToAccount(int id, int value){
	if (id < 0 || id >= _idIterator)
		throw (out_of_range("out_of_range"));
	if (value > _liquidity)
		value = _liquidity;

	int	inflow = value / 20;

	_liquidity += inflow;
	value -= inflow;
	_clientAccounts[id]._value += value;
	cout << "Account " << id << " gain liquidity of " << value << " bank take " << inflow << endl;
}

void	Bank::addLiquidityToBank(int liquidity){
	_liquidity += liquidity;
	if (liquidity > 0)
		cout << "Bank gain value of " << liquidity << " for a new total of " << _liquidity << endl;
	else
		cout << "Bank loss value of " << liquidity << " for a new total of " << _liquidity << endl;
}
