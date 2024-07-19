#include <iostream>

using namespace std;

class Car{
public:
	class Engine{
	private:
		Car*	_car;
		bool	_engine;
		float	_speed;
	public:
		Engine(void): _car(NULL), _engine(false), _speed(0.f){}
		bool	getEngine(void) const {return (_engine);};
		void	setCar(Car* car){_car = car;}

		void	start(void);
		void	stop(void);
		void	accelerate(float speed);
	};

	class GearLever{
	private:
		Car*	_car;
		int		_gear;
	public:
		GearLever(void): _car(NULL), _gear(0){}
		void	setCar(Car* car){_car = car;}

		void	shift_gears_up(void);
		void	shift_gears_down(void);
		void	reverse(void);
	};

	class Wheel{
	private:
		Car*	_car;
		float	_wheelAngle;
	public:
		Wheel(void): _car(NULL), _wheelAngle(0.f){}
		void	setCar(Car* car){_car = car;}

		void	turn_wheel(float angle);
		void	straighten_wheels(void);
	};

	class Brakes{
	private:
		Car*	_car;
		float	_brakesForce;
	public:
		Brakes(void): _car(NULL), _brakesForce(0.f){}
		void	setCar(Car* car){_car = car;}

		void	apply_force_on_brakes(float force);
		void	apply_emergency_brakes(void);
	};
private:
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
	_engine.setCar(this);
	_gearLever.setCar(this);
	_wheel.setCar(this);
	_brakes.setCar(this);
}

Car::~Car(){
}

void	Car::Engine::start(void){
	if (!_car)
		return ;
	_engine = true;
	cout << "Car start" << endl;
}

void	Car::Engine::stop(void){
	if (!_car)
		return ;
	_car->_brakes.apply_emergency_brakes();
	_engine = false;
	cout << "Car stop" << endl;
}

void	Car::Engine::accelerate(float speed){
	if (!_car || _car->_engine._engine == false)
		return ;
	_speed += speed;
	cout << "Car accelerate to " << _speed << endl;
}

void	Car::GearLever::shift_gears_up(void){
	if (!_car || _car->_engine.getEngine() == false)
		return ;
	if (_gear < 6){
		_gear++;
		cout << "Car gears up to " << _gear << endl;
	}
}

void	Car::GearLever::shift_gears_down(void){
	if (!_car || _car->_engine.getEngine() == false)
		return ;
	if (_gear > 0){
		_gear--;
		cout << "Car gears down to " << _gear << endl;
	}
}

void	Car::GearLever::reverse(void){
	if (!_car || _car->_engine.getEngine() == false)
		return ;
	_gear = -1;
	cout << "Car gears is reverse" << endl;
}

void	Car::Wheel::turn_wheel(float angle){
	if (!_car || _car->_engine.getEngine() == false)
		return ;
	_wheelAngle += angle;
	if (_wheelAngle < -45.f)
		_wheelAngle = -45.f;
	else if (_wheelAngle > 45.f)
		_wheelAngle = 45.f;
	cout << "Car wheel angle is " << _wheelAngle << endl;
}

void	Car::Wheel::straighten_wheels(void){
	if (!_car || _car->_engine.getEngine() == false)
		return ;
	_wheelAngle = 0.f;
	cout << "Car wheel angle is straighten" << endl;
}

void	Car::Brakes::apply_force_on_brakes(float force){
	if (!_car || force <= 0)
		return ;
	if (force > 1.f)
		_brakesForce = 1.f;
	else
		_brakesForce = force;
	cout << "Car brakes force is " << _brakesForce << endl;
}

void	Car::Brakes::apply_emergency_brakes(void){
	if (!_car)
		return ;
	_brakesForce = 1.f;
	cout << "Car brakes force is maxed" << endl;
}
