#include <iostream>

using namespace std;

class Car{
private:
	struct Engine{
		Car*	_car;
		bool	_engine;
		float	_speed;

		Engine(void): _engine(false), _speed(0.f){}
		void	start(void);
		void	stop(void);
		void	accelerate(float speed);
	};

	struct GearLever{
		Car*	_car;
		int		_gear;

		GearLever(void): _gear(0){}
		void	shift_gears_up(void);
		void	shift_gears_down(void);
		void	reverse(void);
	};

	struct Wheel{
		Car*	_car;
		float	_wheelAngle;

		Wheel(void): _wheelAngle(0.f){}
		void	turn_wheel(float angle);
		void	straighten_wheels(void);
	};

	struct Brakes{
		Car*	_car;
		float	_brakesForce;

		Brakes(void): _brakesForce(0.f){}
		void	apply_force_on_brakes(float force);
		void	apply_emergency_brakes(void);
	};

	Engine		_engine;
	GearLever	_gearLever;
	Wheel		_wheel;
	Brakes		_brakes;
public:
	Car(void);
	~Car();

	void	start(void){_engine.start();}
	void	stop(void){_engine.stop();}
	void	accelerate(float speed){_engine.accelerate(speed);}
	void	shift_gears_up(void){_gearLever.shift_gears_up();}
	void	shift_gears_down(void){_gearLever.shift_gears_down();}
	void	reverse(void){_gearLever.reverse();}
	void	turn_wheel(float angle){_wheel.turn_wheel(angle);}
	void	straighten_wheels(void){_wheel.straighten_wheels();}
	void	apply_force_on_brakes(float force){_brakes.apply_force_on_brakes(force);}
	void	apply_emergency_brakes(void){_brakes.apply_emergency_brakes();}
};

Car::Car(void){
	_engine._car = this;
	_gearLever._car = this;
	_wheel._car = this;
	_brakes._car = this;
}

Car::~Car(){
}

void	Car::Engine::start(void){
	_engine = true;
	cout << "Car start" << endl;
}

void	Car::Engine::stop(void){
	_car->_brakes.apply_emergency_brakes();
	_engine = false;
	cout << "Car stop" << endl;
}

void	Car::Engine::accelerate(float speed){
	if (_car->_engine._engine == false)
		return ;
	_speed += speed;
	cout << "Car accelerate to " << _speed << endl;
}

void	Car::GearLever::shift_gears_up(void){
	if (_car->_engine._engine == false)
		return ;
	if (_gear < 6){
		_gear++;
		cout << "Car gears up to " << _gear << endl;
	}
}

void	Car::GearLever::shift_gears_down(void){
	if (_car->_engine._engine == false)
		return ;
	if (_gear > 0){
		_gear--;
		cout << "Car gears down to " << _gear << endl;
	}
}

void	Car::GearLever::reverse(void){
	if (_car->_engine._engine == false)
		return ;
	_gear = -1;
	cout << "Car gears is reverse" << endl;
}

void	Car::Wheel::turn_wheel(float angle){
	if (_car->_engine._engine == false)
		return ;
	_wheelAngle += angle;
	if (_wheelAngle < -45.f)
		_wheelAngle = -45.f;
	else if (_wheelAngle > 45.f)
		_wheelAngle = 45.f;
	cout << "Car wheel angle is " << _wheelAngle << endl;
}

void	Car::Wheel::straighten_wheels(void){
	if (_car->_engine._engine == false)
		return ;
	_wheelAngle = 0.f;
	cout << "Car wheel angle is straighten" << endl;
}

void	Car::Brakes::apply_force_on_brakes(float force){
	if (force <= 0)
		return ;
	if (force > 1.f)
		_brakesForce = 1.f;
	else
		_brakesForce = force;
	cout << "Car brakes force is " << _brakesForce << endl;
}

void	Car::Brakes::apply_emergency_brakes(void){
	_brakesForce = 1.f;
	cout << "Car brakes force is maxed" << endl;
}
