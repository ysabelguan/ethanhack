//SO TODAY WE'RE GOING TO TALK KABOUT INHERITANCE.
//LET'S TAKE AN EXAMPLE CLASS CAR.
//IT SOLVES THE PROBLEM OF INCEPTION-LIKE IF STATEMENTS AND FOR LOOPS.
//the way it works: base class inherits the derived classes; in other words,
//parent class has children classes that inherit all the traits from the parent class
//SYNTAX OF INHERITANCE:
class Vehicle
{
  Vehicle(int wheels);
		     public void accelerate(); 
}
  class Car:public Vehicle
  {
    public void airBags();
    //AND WHEN YOU'RE DEFINING AN OBJECT IN THE CLASS CAR YOU GO
    Car ferrarri
      {
       ferrarri.accelerate(); 
      }
  }

//BUT HOW DO YOU MANAGE WITH THE CAR CONSTRUCTOR?
    Car::Car(double fuelCap): //initializer list below
      //FIRST MEMBER OF INITIALIZER LIST MUST BE YOUR BASE CLASS CONSTRUCTOR, UNLESS!!! UNLESS THE BASE CLASS CONSTRUCTOR IS DEFAULT (DOESN'T TAKE PARAMETERS), THEN YOU DON'T HAVE TO INCLUDE ITS CONSTRUCTOR IN THE INITIALIZER LIST.
      Vehicle(4),
      fuelCapacity(fuelCap)
    {}
//THE RULE OF INHERITANCE IS THAT YOU MUST BE ABLE TO MAKE A SENTENCE USING
//THE BASE AND DERIVED CLASSES: [Derived class] is a [base class].
//Preferably you want several inheritance trees that stem from one huge class.
//THERE'S ANOTHER PROTECTION LEVEL BETWEEN public AND private SPECIFICALLY FOR DERIVED AND BASE CLASSES: it is called "protected". Only the base classes and derived classes get access to the protected members of a class.
//ALWAYS MAKE THE FIELDS PRIVATE!!! EVEN IF THE FUNCTIONS THAT INCLUDE THEM ARE PROTECTED!!!!!!! 
//IF YOU HAVE GRANDCHILDREN CLASSES THAT INHERIT FROM THE FIRST GENERATION DERIVED CLASSES, IN THE CONSTRUCTOR, YOU ONLY NEED TO CALL THE CONSTRUCTOR CLASS OF THE GRANDCHILDREN'S PARENT CLASS. 
*********ASK ABOUT HYBRID AND CAR AND VEHICLE CLASSES*****************
//IN ROOT, EVERY FILE OF A PROGRAM MUST HAVE A FUNCTION OF THE EXACT SAME NAME 
//EVERYTHING'S A POINTER IN ROOT
// HOMEWORK FOR 2/12: CLASS STRUCTURE!!!!!!!!!!!!!!!!!!!!!! WORKS WITH INHERITANCE
// - FIGHTING CHARACTERS!! DIFFERENT CHARACTERS THAT FIGHT ONE ANOTHER!
// - YOU HAVE AN INHERITANCE TREE, WITH THE BASE CLASS BEING A CHARACTER WITH GENERAL CHARACTERISTICS THAT ALL CHARACTERS HAVE, THEN YOU HAVE TWO OR MORE DERIVED CLASSES THAT ARE OPPONENTS IN THE GAME
// - GIVE A HANDFUL OF MEMBERS AND METHODS AND WRITE UP A STRUCTURE.
// - EACH CLASS NEEDS A HEADER AND SOURCE FILE, PLUS THE MAIN FILE. 
//SOME CHARACTERISTICS A WARRIOR CAN HAVE
//VECTOR CLASS: SO YOU CAN DO OPERATOR OVERLOADING
//GETTERS AND SETTERS, SIMPLE FUNCTIONS LIKE MAGNITUDE,
//OVERLOAD THE OPERATORS LIKE SCALAR MULTIPLCATION AND + or - 

//POLYMORPHISM!!!!!!!!
//For each object of an inheritnace class, there's a hidden vtbl in the base class it belongs to (virtual table) that is a pointer to the inheritance class's functions. The vtable is not known at compile time. In order to cal an inheritance class function, you must call the vtable. Here's how you do it:
//WRITE THE KEYWORD VIRTUAL ON ANY FUNCTION YOU WANT TO HAVE POLYMORPHIC BEHAVIOR. 
virtual void special(); //THIS IS WRITTEN IN THE PARENT FUNCTION
void special() override; //THIS IS WRITTEN IN THE CHILD FUNCTION 
//This works for functions that are default in the parent class but can be modified/changed in a child class.
Warrior* char1 = new Hero(); //YOU NEED POINTERS!!!!!
//YOU NEED POINTERS BECAUSE IF YOU DO THIS
Warrior char1 = Hero(); //ALL THE DATA THAT IS SPECIFIC TO HERO GETS WIPED OUT AND THE OBJECT TYPE IS JUST CONVERTED TO WARRIOR WITHOUT THE SPECIFICS OF HERO!!!!!!!!! THE POINTER POITNS TO THE SPECIFIC DATA IN HERO AND YOU WANT THAT BECAUSE YOU STILL WANT TO RETAIN THE QUALITIES OF THE INHERITANCE CLASS 

//TEMPLATES: indicate what a function looks like but the user fills in all the information, specifically the type of the function
template<typename T> //Put in header file because it's not source code 
T square(T x)
{
  return x*x; 
} //the compiler does not check the syntax of this
double a;
double b = square(a); //compiler figures out based on the template that the type of the parameter and the type of the function are both doubles
//the function is created at compile time
double square(double x)
{
  return x*x; 
}
//TEMPLATE CLASSES
template<typename T>
class SmartArray
{
  //write teh class as normal but put T instead 
}
//HOW TO USE:
  SmartArray<char*> array(3); 
//the definitions of the methods for the class don't go in the source file because the class is in the header file; thus, you have to define in the header file
#include "SmartARray.icc"
//and then every single individual method needs the template typename T in front in the SmartArray.icc file
template<typename T>
T& SmartArray::operator[](int index)
{
  return array[index]; 
}
//templates can have multiple arguments
//templates allow integers as template arguments; ou can use templates to make arrays
//size is a template parameter; is not actually stored in the memory; the array generates the size of the array at compile time 
//GO BACK TO SMART ARRAY CLASS AND TEMPLATE IT!!!!!!!!!!!


//3/4/2020
std::string //works intuitively
#include <string>
//PUT IN SOURCE FILE:
using std::string; 
//HOW TO USE (HOW TO INITIATE A STRING)
std::string string = "Defecate"; //EVERYTHING IS LOWERCASE
//YOU CAN PASS AND RETURN IT FROM A FUNCTION
//YOU CAN COMPARE IT TO OTHER STRINGS
//USES COPY CONSTRUCTOR
std::string string2(string);
//can also be interpreted as a char array and access individual characters directly
string[4] = c;
string[4]++; //increments the 5th letter up by one letter, from c to d
auto string3 = string+string2;
//TO CONVERT FROM STRING TO INT:
string3 += std::to_string(7); //converts the number 7 to a string and concatenates it, can convert anything of any type
//TO CONVERT FROM STRING TO CHAR*: 
char* charArray = string3.c_str(); 

#include <vector>
//BASICALLY A SMARTARRAY BUT BETTER 
//how to initialize:
vector<double> eggSizes={5,3.5,6.9}; //WILL CHANGE SIZE TO WHATEVER YOU PUT IN IT
eggSizes.push_back(2.2); //means to ADD SOMETHING TO THE END OF THE ARRAY
//can have direct access and modify it like an array as well
//to ensure protection from seg faulting and accidentally accessing an element that isn't there:
eggSizes.at(3) =2; //throws exception if the element doesn't exist 
eggSizes[3]* = 2; 
