
#include<iostream>
#include<string>
using namespace std;

enum Color { red, green,yellow, black, blue };					// putting color first to be able to use from all of classes

namespace namespace_1
{
	
	
	class Wheel                              // class wheel to have the following
	{
	
	private:
		double radius;
		double rpm;
		double angle;
		double pressure;

	public:

		friend class Pump;					//friend class to get into privte pressure
		friend class Car;
		bool SetRpm(double k);				//to set rpm with value k
		bool SetAngle(double k);
		double GetRpm();					// to get rpm
		double GetAngle();					// to get angle
		double GetRadius();					// to get radius
		Wheel();
		Wheel(double r);					//Wheel x1(3.2); //to create wheel with radius
		bool operator== (Wheel w);			 // if(w1.operator==(w2))  ... else ... ; 
		bool operator!= (Wheel w);
		bool operator>= (Wheel w);
		bool operator> (Wheel w);
		bool operator<= (Wheel w);
		bool operator< (Wheel w);
	};

	class Pump
	{
	public:
		void setPressure(Wheel &w, double k);
		double GetPre(Wheel w); 				// to verify that we have the right pressure to display
	};

	class Vehicle    //create class vehicle
	{
		public:
		Vehicle();
		virtual void print();  // function to print out the class name  //virtual to avoid error due static bindning
//																		// make it dynamic with virtual
	};

	class Car :virtual public Vehicle      //create class bike , inherit from vehicle //virtual to avoid diamond
	{

	private:

		Wheel * flWheel;            // to each wheel of the car
		Wheel * frWheel;
		Wheel * rlWheel;
		Wheel * rrWheel;
		double linearVelocity;
		double angularVelocity;
		Color color; 
		int w;
		string model;
		

	public:

		Car();
		Car(Car &object1);
		Car(string s);
		bool setSpeed(double sp);            // speed sp
		bool setTurningAngle(double k);
		string col(Color color);
		void SetCar(Color color1, int w1, double linear, double angular,string str);
		void GetCar();
		void GetWheel();
		void print();        // function to print out the class name
	};

	

	class Bike : public Vehicle          //create class bike , inherit from vehicle
	{
		public:
		virtual void print();       // function to print out the class name 
		Bike();																	
	};

	class Boat: virtual public Vehicle         //create class boat , inherit from vehicle //virtual to avoid diamond
	{
		public:
		Boat();
	};


	class Amphicar:public Boat,public Car       //create class Amphicar , inherit from car and boat //virtual to avoid diamond
	{
		public:
		Amphicar();
	};




} 
