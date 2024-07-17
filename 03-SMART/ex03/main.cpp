#include <EmployeeManagement.hpp>

int	main(void){
	EmployeeManagement	manager;
	TempWorker			tempWorker(10);
	ContractEmployee	contractEmployee(13);
	Apprentice			apprentice(8);

	manager.addEmployee(&tempWorker);
	manager.addEmployee(&contractEmployee);
	manager.addEmployee(&apprentice);

	// Simulate workdays
	for (int i = 0; i < 20; i++)
		manager.executeWorkday();

	// Log additional hours
	tempWorker.mobilize(32);
	contractEmployee.logVacation(5);
	apprentice.logSchoolHours(8);

	// Calculate payroll
	manager.calculatePayroll();
	// Should be 1720
	// Should be 1820
	// Should be 1120
	return (0);
}
