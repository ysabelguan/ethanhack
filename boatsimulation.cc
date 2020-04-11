//Ysabel Guan
//9/11/2019
//revising of boatsimulation.cc

//VELOCITY IS A VECTOR
//DECLARE FUNCTIONS WITH COMMENTS AND DEFINE THEM LATER
//INCLUDE MORE FUNCTIONS; THE MORE FUNCTIONS THE BETTER
//MORE MATH UTILITY FUNCTIONS 

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

//DECLARE STRUCTS
struct FourVector
{
  double time;
  double x;
  double y;
  double z; 
};
  struct Vehicle
  {
    double velocity; //in terms of c, relative to earth 
    double radius;
    FourVector spacetime; 
  };
  //INITIALIZE STRUCTS
Vehicle boat1={0.6,5,{1,3,4,0}};

Vehicle boat2={0.6,5,{1,-20,15,0}};

Vehicle torpedo={0.5,2,{1,5,9,0}}; //muzzle velocity is relative to boat1

//DIFFERENCE BETWEEN TORPEDO AND BOAT2
struct Coordinate
{
  double x;
  double y;
};
  
Coordinate distance(Vehicle torpedo, Vehicle boat2) 
{
  double x1 = torpedo.spacetime.x;
  double x2 = boat2.spacetime.x;
  double differenceX = x2-x1;
    
  double y1 = torpedo.spacetime.y;
  double y2 = boat2.spacetime.y;
  double differenceY = y2-y1;

  Coordinate dist = {differenceX,differenceY};
    return dist; 
}

//RELATIVISTIC FUNCTIONS
double gamma(double velocity) //calculating gamma value
{
  double fraction = std::pow(velocity,2);
  double denominator = std::sqrt(1-fraction);
  double calculation = 1/denominator;
    return calculation;
}

struct Lorentz
{
  double gamma;
  double nsubx;
  double nsuby;
  double nsubz; 
};

Lorentz lorentzvalues(Vehicle object, const Lorentz& lorentzvalues) //converting time b/t 2 rf
{
  double originalt = object.spacetime.time;
  double v = -1 * object.velocity;
  lorentzvalues.gamma = gamma(v);
  lorentzvalues.nsubx; //need to add this 
  lorentzvalues.nsuby;
  lorentzvalues.nsubz;
  return lorentzvalues; 
}
double tprime(Vehicle object, Lorentz lorentzvalues)
{
  lorentzvalues(object, lorentzvalues); 
  double t1 = object.spacetime.time;
    double t2 = -1 * lorentzvalues.gamma * v * lorentzvalues.nsubx;
    double t3 = -1 * lorentzvalues.gamma * v * lorentzvalues.nsuby;
    double t4 = -1 * lorentzvalues.gamma * v * lorentzvalues.nsubz;
    double tprime = t1 + t2 + t3 + t4;
    return tprime;
}

double xprime(Vehicle object, Lorentz lorentzvalues) //converting x b/t 2 rf
{  
  lorentzvalues(object, lorentzvalues); 
  double x1 = -1 * lorentzvalues.gamma * v * lorentzvalues.nsubx;
  double x2 = 1 + (lorentzvalues.gamma-1)*pow(lorentzvalues.nsubx,2);
  double x3 = (lorentzvalues.gamma-1)*lorentzvalues.nsubx*lorentzvalues.nsuby;
    double x4 = (lorentzvalues.gamma-1)*lorentzvalues.nsubx*lorentzvalues.nsubz;
    double xprime = x1 + x2 + x3 + x4;
    return xprime;
}

double yprime(Vehicle object, Lorentz lorentzvalues) //converting y b/t 2 rf
{
  lorentzvalues(object, lorentzvalues); 
  double y1 =  -1 * lorentzvalues.gamma * v * lorentzvalues.nsuby;
    double y2 = (lorentzvalues.gamma-1)*lorentzvalues.nsubx*lorentzvalues.nsuby;
    double y3 = 1 + (lorentzvalues.gamma-1)*pow(lorentzvalues.nsuby,2);
    double y4 = (lorentzvalues.gamma-1)*lorentzvalues.nsuby*lorentzvalues.nsubz;
    double yprime = y1 + y2 + y3 + y4;
    return yprime;
}

double zprime(Vehicle object, Lorentz lorentzvalues) //converting z b/t 2 rf
{
  lorentzvalues(object, lorentzvalues); 
  double z1 = -1 * lorentzvalues.gamma * v * lorentzvalues.nsubz;
    double z2 = (lorentzvalues.gamma-1)*lorentzvalues.nsubx*lorentzvalues.nsubz;
    double z3 = (lorentzvalues.gamma-1)*lorentzvalues.nsubz*lorentzvalues.nsuby;
    double z4 = 1 + (lorentzvalues.gamma-1)*pow(lorentzvalues.nsubz,2);
    double zprime = z1 + z2 + z3 + z4;
    return zprime;
}

double timeincrement(const Vehicle& object)
{
  double time = ++object.spacetime.time;
  return time;
}

FourVector lorentztrans(Vehicle object, Lorentz lorentzvalues) //Lorentz Transformation with matrix 
{
  tprime(boat1,lorentzvalues);
  xprime(boat1,lorentzvalues);
  yprime(boat1,lorentzvalues);
  zprime(boat1,lorentzvalues);
  FourVector new4vec; 
  return new4vec; 
}

//MAIN FUNCTION



