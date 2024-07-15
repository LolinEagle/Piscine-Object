#include <iostream>

using namespace std;

class Car{
private:
	bool	_engine;
	float	_speed;
	int		_gear;
	float	_wheelAngle;
	float	_brakesForce;
public:
	Car(void);
	~Car();

	void	start(void);
	void	stop(void);
	void	accelerate(float speed);
	void	shift_gears_up(void);
	void	shift_gears_down(void);
	void	reverse(void);
	void	turn_wheel(float angle);
	void	straighten_wheels(void);
	void	apply_force_on_brakes(float force);
	void	apply_emergency_brakes(void);
};

Car::Car(void): _engine(false), _speed(0.f), _gear(0), _wheelAngle(0.f), _brakesForce(0.f){
}

Car::~Car(){
}

void	Car::start(void){
	_engine = true;
	cout << "Car start" << endl;
}

void	Car::stop(void){
	apply_emergency_brakes();
	_engine = false;
	cout << "Car stop" << endl;
}

void	Car::accelerate(float speed){
	if (_engine == false)
		return ;
	_speed += speed;
	cout << "Car accelerate to " << _speed << endl;
}

void	Car::shift_gears_up(void){
	if (_engine == false)
		return ;
	if (_gear < 6){
		_gear++;
		cout << "Car gears up to " << _gear << endl;
	}
}

void	Car::shift_gears_down(void){
	if (_engine == false)
		return ;
	if (_gear > 0){
		_gear--;
		cout << "Car gears down to " << _gear << endl;
	}
}

void	Car::reverse(void){
	if (_engine == false)
		return ;
	_gear = -1;
	cout << "Car gears is reverse" << endl;
}

void	Car::turn_wheel(float angle){
	if (_engine == false)
		return ;
	_wheelAngle += angle;
	if (_wheelAngle < -45.f)
		_wheelAngle = -45.f;
	else if (_wheelAngle > 45.f)
		_wheelAngle = 45.f;
	cout << "Car wheel angle is " << _wheelAngle << endl;
}

void	Car::straighten_wheels(void){
	if (_engine == false)
		return ;
	_wheelAngle = 0.f;
	cout << "Car wheel angle is straighten" << endl;
}

void	Car::apply_force_on_brakes(float force){
	if (force < 0)
		return ;
	if (force > 1.f)
		_brakesForce = 1.f;
	else
		_brakesForce = force;
	cout << "Car brakes force is " << _brakesForce << endl;
}

void	Car::apply_emergency_brakes(void){
	_brakesForce = 1.f;
	cout << "Car brakes force is maxed" << endl;
}
