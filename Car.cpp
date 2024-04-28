#include "Car.hpp"
#include <iostream>
#include<string>

using namespace std;
using namespace namespace_1;

bool Wheel::SetRpm(double k)		//to set rpm with value k
{
	bool test=false;
	this->rpm = k;				//wheel x1; x1.setrpm(4.5);  //rpm=k
	test=true;
	return test;
}

double Wheel::GetRpm()
{
	return this->rpm;				//get rpm
}

bool Wheel::SetAngle(double k)			//to set angle with value k
{	
	bool test=false;
	this->angle = k;			//angle=k
	test=true;
	return test;
}


double Wheel::GetAngle()
{
	return this->angle;				//get rpm
}


double Wheel::GetRadius()
{
	return this->radius;
}

Wheel::Wheel(double k)				//Wheel x; 
{
	radius = k;						 // ex.(3.2)
}

Wheel::Wheel()
{
	rpm=0;
	radius=0;
	angle=0;
	pressure=0;

}

bool Wheel::operator== (Wheel w)
{
	bool test=false;
	if (radius*rpm == w.radius*w.rpm)			//if w1.operator == w2  //first and secund wheel
		test = true;
	return test;
}

bool Wheel::operator!= (Wheel w)				//if w1.operator != w2  //first and secund wheel
{	
	bool test=false;
	if (radius*rpm != w.radius*w.rpm)
		test = true;
	return test;
}


bool Wheel::operator>= (Wheel w)				//if w1.operator >= w2  //first and secund wheel
{	
	bool test=false;
	if (radius*rpm >= w.radius*w.rpm)
		test = true;
	return test;
}

bool Wheel::operator<= (Wheel w)			//if w1.operator <= w2  //first and secund wheel
{
	bool test=false;
	if (radius*rpm <= w.radius*w.rpm)
		test = true;
	return test;
}

bool Wheel::operator< (Wheel w)				//if w1.operator < w2  //first and secund wheel
{
	bool test=false;
	if (radius*rpm<w.radius*w.rpm)
		test = true;
	return test;
}

bool Wheel::operator> (Wheel w)			//if w1.operator > w2  //first and secund wheel
{
	bool test=false;
	if (radius*rpm>w.radius*w.rpm)
		test = true;
	return test;
}
void Pump::setPressure(Wheel &w, double k)			
{
	w.pressure = k;
}

double Pump::GetPre(Wheel w)
{
	return w.pressure;
}


void Car::SetCar(Color color1, int w1, double linear, double angular,string str)
{
	model = str;
	color = color1;
	w = w1;
	linearVelocity = linear;
	angularVelocity = angular;			//linear = rpm * radius
	rrWheel->radius=rlWheel->radius=flWheel->radius=frWheel->radius=linearVelocity/angularVelocity;	// same radius for all wheel
	rrWheel->rpm=linearVelocity/rrWheel->radius;
	rlWheel->rpm=linearVelocity/rlWheel->radius;
	flWheel->rpm=linearVelocity/flWheel->radius;		// same rpm for all wheels
	frWheel->rpm=linearVelocity/frWheel->radius;
}

void Car::GetCar()
{
	cout << "angular: " << angularVelocity << endl;
	cout << "linear: " << linearVelocity << endl;
	cout << "weight: " << w << endl;
	cout << "color: " << col(color) << endl;			//col to print out the actuall color, not it's number in the array
	cout << "model: " << model << endl;
}

string Car::col(Color color)			// to return color as string, not as number
{
	switch (color)
	{
	case blue: return "blue"; break;
	case black: return "black"; break;
	case yellow: return "yellow"; break;
	case red: return "red"; break;
	case green: return "green"; break;
	}

	return "error";						  //return error if we don't have that color
}



Car::Car()
{
	cout << ">>> default constructor" << endl;			// It's the default contructor
	angularVelocity = 0;   //angular=0					// if not 0 it will gave me random value from memory
	linearVelocity = 0;    //linear=0					// if not 0 it will gave me random value from memory
	w = 0;
	model = "";
	color = red;
	rrWheel=new Wheel;
	rlWheel=new Wheel;
	flWheel=new Wheel;
	frWheel=new Wheel;
	rrWheel->radius=rlWheel->radius=flWheel->radius=frWheel->radius=5;    //the same data forr all wheels
	rrWheel->rpm=rlWheel->rpm=flWheel->rpm=frWheel->rpm=0;
	cout << "model: " << model << endl;										// model of car
	cout<<"======================================"<<endl;
}

Car::Car(Car &object1)		 // car x1;  car x2(x1);		
{														// copy constructor to copy data from x1 to x2
	cout << ">>> copy constructor" << endl;
	rrWheel=object1.rrWheel;
	rlWheel=object1.rlWheel;
	flWheel=object1.flWheel;
	frWheel=object1.frWheel;
	angularVelocity = object1.angularVelocity;
	linearVelocity = object1.linearVelocity;
	model = object1.model;
	color = object1.color;
	w = object1.w;
	cout << "model: " << model << endl;
	cout<<"======================================"<<endl;
}

Car::Car(string s)
{
	cout << ">>> not default constructor" << endl;
	linearVelocity = 0;      //linear = 0				
	angularVelocity = 0;        // angular = 0
	rrWheel=new Wheel;
	rlWheel=new Wheel;
	flWheel=new Wheel;
	frWheel=new Wheel;
	rrWheel->radius=rlWheel->radius=flWheel->radius=frWheel->radius=3;		//the same data forr all wheels
	rrWheel->rpm=rlWheel->rpm=flWheel->rpm=frWheel->rpm=0;
	color = blue;
	w = 0;
	model = s;
	cout << "model: " << model << endl;
	cout<<"======================================"<<endl;
}

bool Car::setSpeed(double sp)
{
	bool test=false;
	if((flWheel->radius * flWheel->rpm >= sp) && (frWheel->radius * frWheel->rpm >= sp) && (rlWheel->radius * rlWheel->rpm >= sp ) && (rrWheel->radius * rrWheel->rpm >= sp))  //to set speed, radius * rpm should be >= sp  
	{
		test=true;				//if it's true then test=true           // speed=rpm*radius   >> rpm=speed/radius
		flWheel->rpm=sp/flWheel->radius;
		frWheel->rpm=sp/frWheel->radius;
		rlWheel->rpm=sp/rlWheel->radius;
		rrWheel->rpm=sp/rrWheel->radius;
	}

	return test;
}

bool Car::setTurningAngle(double k)
{
	bool test=false;
	if(k<=30 && k>=-30)					// [-30,30]   assume that angle is allways between [-30,30] 
	{flWheel->SetAngle(k);				 //set the angle for front left wheel
	frWheel->SetAngle(k);					//set the angle for front right wheel
	test=true;
	}
	return test;
}

void Car::GetWheel()					// to print out current angle and rpm for each wheel
{
	cout<<"fl(rpm): "<<flWheel->rpm<<endl;
	cout<<"fl(radius): "<<flWheel->radius<<endl;
	cout<<"fr(rpm): "<<frWheel->rpm<<endl;
	cout<<"fr(radius): "<<frWheel->radius<<endl;
	cout<<"rl(rpm): "<<rlWheel->rpm<<endl;
	cout<<"rl(radius): "<<rlWheel->radius<<endl;
	cout<<"rr(rpm): "<<rrWheel->rpm<<endl;
	cout<<"rr(radius): "<<rrWheel->radius<<endl;
}


Bike::Bike()
{;}

void Bike::print()			// to printe out the class name
{
cout<<"Bike"<<endl;
}

void Car::print()		// to printe out the class name
{
cout<<"Car"<<endl;
}


Vehicle::Vehicle()
{;}

void Vehicle::print()   // to printe out the class name
{
cout<<"Vehicle"<<endl;
}
	
Amphicar::Amphicar()
{;}

Boat::Boat()
{;}
