//header file
// DEFINE CLASS

//GUARDS
#ifndef SMARTARRAY_HH
#define SMARTARRAY_HH

#include <stdexcept>
template<typename T>
class SmartArray
{
public: //DECLARE METHODS
  void setValue(int index, T value);
  T getValue(int index); //access indexes
  SmartArray copyArray();
  void append(T valuetoappend); 
  void remove(int index);
  SmartArray(int size);  //constructor
  SmartArray(const SmartArray& original);//copy cosntructor 
  ~SmartArray(); //deconstructor
private:
  T* array;
  int size; 
};

// DEFINE METHODS
template<typename T> 
SmartArray<T>::SmartArray(int size) //constructor
{
  array = new T[size];
  if (size<1)
    {
      std::domain_error("Negative number passed"); 
    }
}

template<typename T> 
SmartArray<T>::SmartArray(const SmartArray& original) //copy constructor
{
  size = original.size; //the new object copies the old object's data.
}

template<typename T> 
void SmartArray<T>::append(T valuetoappend)
{ 
  T* newArray = new T[size +1];
  
  for (int i=0; i<size; i++)
    {
      newArray[i]=array[i];
    }
  
  delete[] array;
  array = newArray;
  ++size;

}

template<typename T>
void SmartArray<T>::remove(int index) 
{
  for (int i=index+1; i<size; i++)
    {
      array[i-1] = array[i]; 
    }
  --size; 
}

template<typename T> 
void SmartArray<T>::setValue(int index, T value)
{
  array[index] = value; 
}

template<typename T> 
T SmartArray<T>::getValue(int index)
{
  for (int i=0; i<size; i++)
    {
      T element = array[i];
      if (i == index)
	{
	  return element; 
	}
    }
}

template<typename T> 
SmartArray<T>::~SmartArray()
{
  delete []array;
}

#endif 
