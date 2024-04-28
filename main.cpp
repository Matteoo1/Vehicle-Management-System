#include <iostream>
#include<fstream>
#include<string.h>
#include "Car.hpp"

using namespace std;
using namespace namespace_1;

int main()
{
cout<<">>>> Exercise 1"<<endl;
Car car1;                        //default const
Bike bike1;
Vehicle vehicle1;
car1.print();        //print car
bike1.print();       //print bike
vehicle1.print();    //print Vehicle
cout<<">>>> Exercise 2"<<endl;
Vehicle *v1= new Car();             //make momory for car and print out then
Vehicle *v2= new Bike();            //make momory for car and print out then
(*v1).print();
(*v2).print();
cout<<">>>> Exercise 3"<<endl;
Amphicar amphicar1;
amphicar1.print();               // will take print from car.
cout<<">>>> Exercise 4"<<endl;
Vehicle *aux[200];        //array with max 200
char name[15],c;          // to take an alphabet by time
ifstream file("vehicles.txt");     // to read from the file
int j=0,k1=0;

while(file.good())      // read an alphabet by time to reach the end of file
{
file.get(c);           // bike\n  --> car\n
if(c=='\n')
{
name[j]='\0';   // to close the char, when the word end, for example at bike
if(name[0]!='\0')      // to avoid problem in the end of the file, if name[0] are = \0 then the file has enden
{
if(strcmp(name,"amphicar")==0) {aux[k1]=new Amphicar(); k1+=1;}  //if name are same as "amphicar", it's a 0, then make memory for Amphicar
else if(strcmp(name,"bike")==0) {aux[k1]=new Bike(); k1+=1;}     //else
else if(strcmp(name,"car")==0) {aux[k1]=new Car(); k1+=1;}	     //else
}
j=0;        // when you are done by the firs while, make j to 0 so we can move forward to a new line/word
}
else
{name[j]=c; j+=1;}     //name={b,i,k,e,\n} = bike\n
}

	return 0;
}
