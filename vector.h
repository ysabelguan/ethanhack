// Ysabel Guan
// VECTOR CLASS
// version 3/10/2020
//ask about friend functions and why operator arguments are const &
#ifndef VECTORCLASS_HH
#define VECTORCLASS_HH

template<typename T> 
class Vector
{
public:
  Vector(T x1, T y1);
  Vector(const Vector& original);
  ~Vector();

  Vector operator + (Vector const &v1); //adding vectors
  Vector operator * (T scalar); //scalar multiplication
  Vector operator - (Vector const &v1); //subtracting vectors
  Vector operator - (); //negating vectors 
  
private:
  T x;
  T y; 
};

template <typename T>
Vector<T>::Vector(T x1, T y1)
{
  Vector<T> vector = new Vector<T>(x1,y1); 
}

template <typename T>
Vector<T>::Vector(const Vector& original)
{
  x = original.x;
  y = original.y;
}

template <typename T>
Vector<T> Vector<T>::operator + (Vector<T> const &v1)
{
  return Vector<T>(v1.x+x, v1.y+y); 
}

template <typename T>
Vector<T> Vector<T>::operator * (T scalar)
{
  return Vector<T>(scalar*x, scalar*y);
}

template <typename T>
Vector<T> Vector<T>::operator - (Vector const &v1)
{
  return Vector<T>(x-v1.x, y-v1.y);  
}

template <typename T>
Vector<T> Vector<T>::operator - ()
{
  return Vector<T>(x*(-1), y*(-1));
}

template <typename T>
Vector<T>::~Vector()
{
  delete x;
  delete y; 
}
  
#endif
