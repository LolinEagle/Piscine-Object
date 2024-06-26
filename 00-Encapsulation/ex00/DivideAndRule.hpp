#include <iostream>
#include <vector>

using namespace std;

struct Bank{
private:
	struct Account{
	public:
		int	_id;
		int	_value;

		Account(int initalId, int initalValue);
		friend ostream&	operator<<(ostream& p_os, const Account& p_account){
			p_os << "Id:" << p_account._id << ' ' << "Value:" << p_account._value;
			return (p_os);
		}
	};

	int				_idIterator;
	int				_liquidity;
	vector<Account>	_clientAccounts;
public:
	Bank(void);
	Bank(int initalLiquidity);
	const Account&	operator[](int id);
	friend ostream&	operator<<(ostream& p_os, const Bank& p_bank);

	void	createAccount(int initalValue);
	void	deleteAccount(int id);
	void	addValueToAccount(int id, int value);
	void	addLiquidityToBank(int liquidity);
};
