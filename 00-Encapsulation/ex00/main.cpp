#include <DivideAndRule.hpp>

int	main(void){
	try{
		Bank	bank(999);
		try{
			cout << "-------------------------------------------------" << endl;
			bank.createAccount(100);
			bank.createAccount(100);
			bank.addLiquidityToBank(-200);
			bank.addValueToAccount(0, 400);
			bank.addValueToAccount(-1, 400);
		} catch(const out_of_range& e){
			cerr << e.what() << '\n';
		} try{
			cout << "-------------------------------------------------" << endl;
			cout << "Account:" << endl;
			cout << bank[0] << endl;
			cout << bank[1] << endl;
			cout << bank[2] << endl;
		} catch(const out_of_range& e){
			cerr << e.what() << '\n';
		} try{
			cout << "-------------------------------------------------" << endl;
			cout << "Bank:" << endl;
			cout << bank << endl;
			bank.deleteAccount(1);
			bank.deleteAccount(0);
			cout << bank << endl;
			bank.deleteAccount(0);
		} catch(const out_of_range& e){
			cerr << e.what() << '\n';
		}
	} catch(const exception& e){
		cerr << e.what() << '\n';
	}
	return (0);
}
