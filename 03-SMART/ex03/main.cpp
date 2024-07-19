#include <EmployeeManager.hpp>

int	main(void){
	EmployeeManager		manager;
	TempWorker			tempWorker(10);
	ContractEmployee	contractEmployee(13);
	Apprentice			apprentice(8);

	manager.addEmployee(&tempWorker);
	manager.addEmployee(&contractEmployee);
	manager.addEmployee(&apprentice);

	// Simulate workdays
	for (int i = 0; i < 5; i++)
		manager.executeWorkday();

	// Calculate payroll
	// Should be 0
	// Should be 455
	// Should be 280
	manager.calculatePayroll();

	// Log additional hours
	tempWorker.mobilize(35);
	contractEmployee.logVacation(35);
	apprentice.logSchoolHours(35);

	// Simulate workdays
	for (int i = 0; i < 5; i++)
		manager.executeWorkday();

	// Calculate payroll
	// Should be 350
	// Should be 455
	// Should be 420
	cout << endl;
	manager.calculatePayroll();
	return (0);
}
