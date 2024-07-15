#include <Car.hpp>

int main(void){
	int i;
	Car	car;

	car.start();
	car.accelerate(21.f);
	car.accelerate(21.f);
	for (i = 0; i < 8; i++)
		car.shift_gears_up();
	for (i = 0; i < 8; i++)
		car.shift_gears_down();
	car.reverse();
	car.shift_gears_up();
	car.turn_wheel(-42.f);
	car.straighten_wheels();
	car.apply_force_on_brakes(.1f);
	car.apply_force_on_brakes(2.f);
	car.apply_emergency_brakes();
	car.stop();
	return (0);
}
