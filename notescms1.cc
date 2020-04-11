class Vector
{
public:
  Vector(double ix, double iy);
  Vector add(Vector V);
  
private:
  double x;
  double y;
};
Vector add(Vector v1, Vector v2); //standalone function
//OR put
static Vector add(Vector v1, Vector v2); //in place of Vector add(Vector V)
//static function is a standalone function that uses the private data members so that it maeks sense to put it in the class. 
//OPERATOR OVERLOADING:
Vector operator+(Vector h);
//OR
static Vector operator+(Vector lh, Vector rh); //only use "staticd" in the declaration of the code
//You can only ownverload existing operators
static operator*(Vector this, double this);
//always implement operators in terms of operators ????
std::ostream& operator<<(std::ostream&str, Vector vec)
{
  str<< "<"<<vec.getX()<<","<<vec.getY()<<">";
  return str; 
}
//^that helps make the below function work
cont << vec;
//don't use define macros


double gpa(inte grade[]); //wen 
//new enum
enum class Grade{A,B,c,D}; //dclares a new enum; put in the header file 
double gpa(Grade grades][);
Grade mygrade = Grade::A; 
//you could assign integers to chars too in your enum
enum class Grade{A=4, B=3, C=2, D=1};

//Casting means to change the type of something.
int a = 3;
int b = 2;
double ratio = a/b;

//you need soeone take vaot eh girl
double ratio = static_cast<tdoubel>(a) /b;

double total = 0;
for (Grade grade grades)
  {
    total+ = static_cast<int>(grade);
  }

//HOMEWORK: WRITE A VECTOR CLASS THAT USES OPERATOR OVERLOADING 
