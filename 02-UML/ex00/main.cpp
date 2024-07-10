#include <iostream>
#include <vector>

using namespace std;

class LinkablePart{
public:
	LinkablePart(void){}
	virtual ~LinkablePart(){}

	virtual void	execute(float p_pression) = 0;
};

class Wheel{
public:
	Wheel(void){}
	~Wheel(){}

	void	executeRotation(float p_force){}
};

class Gear{
private:
	int	_demultiplier;
public:
	Gear(void){}
	~Gear(){}
};

template <typename T>
class Singleton{
protected:
	Singleton(void){}
	virtual ~Singleton(){}
public:
	static T&	getInstance(void){
		static T instance;
		return instance;
	}

	Singleton(const Singleton&) = delete;
	Singleton&	operator=(const Singleton&) = delete;
};

class GearLever: public Singleton<GearLever>{
	friend class Singleton<GearLever>;// Singleton needs to access the constructor
private:
	vector<Gear>	_gears;
	int				_level;
public:
	GearLever(void): _level(0){}
	~GearLever(){}

	void	change(void){
		if (!_gears.empty())
			_level = (_level + 1) % _gears.size();// Simple wrap-around logic
	}
	Gear*	activeGear(void){
		if (_gears.empty()){
			return nullptr;
		}
		return &_gears[_level];
	}
	void	addGear(const Gear& gear){
		_gears.push_back(gear);
	}
};

class Transmission{
private:
	vector<Wheel*>	_wheels;
public:
	Transmission(void){}
	~Transmission(){}

	void	activate(float p_force){
		for (auto wheel: _wheels)
			wheel->executeRotation(p_force);
	}
	void	addWheels(Wheel* wheel){
		_wheels.push_back(wheel);
	}
};

class Crankshaft{
private:
	Transmission*	_transmission;
public:
	Crankshaft(void){}
	~Crankshaft(){}

	void	receiveForce(float p_volume){}
};

class ExplosionChamber{
private:
	Crankshaft*	_crankshaft;
public:
	ExplosionChamber(void){}
	~ExplosionChamber(){}

	void fill(float p_volume){}
};

class Injector: public LinkablePart{
private:
	ExplosionChamber*	_explosionChamber;
public:
	Injector(void){}
	~Injector(){}

	void execute(float p_pression){}
};

class Motor{
private:
	Injector			_injector;
	ExplosionChamber	_explosionChamber;
	Crankshaft			_crankshaft;
public:
	Motor(void){}
	~Motor(){}

	void connectToTransmission(Transmission* p_transmission){}
};

class Pedal{
private:
	LinkablePart*	_linkablePart;
public:
	Pedal(void){}
	~Pedal(){}

	void	setTarget(LinkablePart* p_part){}
	void	use(float p_pression){}
};

class Direction{
private:
	vector<Wheel>	_wheels;
public:
	Direction(void){}
	~Direction(){}

	void	turn(float p_angle){}
};

class DAE{
private:
	Direction*	_direction;
	float		_force;
public:
	DAE(void){}
	~DAE(){}

	void	use(float p_angle){}
};

class SteerWheel{
private:
	DAE*	_dae;
public:
	SteerWheel(void){}
	~SteerWheel(){}

	void	turn(float p_angle){}
};

class Brake{
private:
	Wheel* _wheel;
public:
	Brake(void){}
	~Brake(){}

	void execute(float p_force){}
	void attackWheel(Wheel* p_wheel){}
};

class BrakeController: public LinkablePart{
private:
	vector<Brake>	_brakes;
public:
	BrakeController(void){}
	~BrakeController(){}

	void execute(float p_pression){}
};

class Cockpit{
private:
	Pedal		_pedal;
	SteerWheel	_steerWheel;
	GearLever	_gearLever;
public:
	Cockpit(void){}
	~Cockpit(){}
};

class Electronics{
private:
	DAE	_dae;
public:
	Electronics(void){}
	~Electronics(){}
};

class Car{
private:
	BrakeController	_brakeController;
	Direction		_direction;
	Transmission	_transmission;
	Motor			_motor;
	Electronics		_electronics;
	Cockpit			_cockpit;
public:
	Car(void){}
	~Car(){}
};

int	main(void){
	Car	car;

	return (0);
}
