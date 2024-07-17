#include <PackageReductionDiscountCommand.hpp>
#include <ThuesdayDiscountCommand.hpp>

int	main(void){
	Command	command(
		"Thuesday 18 July 2024 21:42",
		"Francois",
		"Akamaru Karaka Tori_Shoyu Veggie Akamaru Karaka Tori_Shoyu Veggie Akamaru Karaka"
	);
	PackageReductionDiscountCommand	packageReduction(
		"Thuesday 18 July 2024 21:42",
		"Francois",
		"Akamaru Karaka Tori_Shoyu Veggie Akamaru Karaka Tori_Shoyu Veggie Akamaru Karaka"
	);
	ThuesdayDiscountCommand			thuesday(
		"Thuesday 18 July 2024 21:42",
		"Francois",
		"Akamaru Karaka Tori_Shoyu Veggie Akamaru Karaka Tori_Shoyu Veggie Akamaru Karaka"
	);

	command.printAll();
	cout << "Total price : " << command.getTotalPrice() << '\n' << endl;
	packageReduction.printAll();
	cout << "Total price : " << packageReduction.getTotalPrice() << '\n' << endl;
	thuesday.printAll();
	cout << "Total price : " << thuesday.getTotalPrice() << endl;
	return (0);
}
