//Ysabel Guan
//INHERITANCE ASSIGNMENT FOR 0212
//VERSION 1 

#ifndef GAMEBASECHAR_HH
#define GAMEBASECHAR_HH
class Warrior
{
public:
  Warrior(double height, double weight); //constructor
  virtual void fight()=0; //THIS MAKES THE BASE CLASS ABSTRACT!
  void chase();
  void dodge(); 
  void kill();
  void surrender(); 
private:
  double x; //x position coordinate 
  double y; //y position coordinate
  double vel; //velocity
  double health; //health status of character
  double height;
  double weight; 
  double strength;
}; 
#endif
