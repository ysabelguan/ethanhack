//Ysabel Guan
//10/1/2019
//arrayAssignment.cc

#include <cmath>
#include <string>
#include <string.h> 
#include <fstream>
#include <algorithm> 

//REWRITE SEARCHSTRINGS AND STRCMP SO THAT THERE'S A FUNCTION THAT CHECKS EACH CHARACTER

//INITIALIZE ALL YOUR FUNCTIONS
int searchArray(int array[], int size, int target);
// This iterates through an array from the beginning and when it finds an element that is identical to target, it returns the index of that element

int* searchPointer(int array[], int size, int target);
// The same thing, but with pointers.  It should return a pointer to the element that matches the target

void copyArray(int source[], int size, int destination[]);
// Copies a source array with a given size into the destination array.

const char* searchStrings (const char* strings[], const char* targetString, int size);
// Takes an array of C-style strings and searches each one to see if it contains a string identical to targetString. Return a pointer to the first string that matches.

const char* strcmp (const char* element, const char* targetString, int size);
// Takes one element from the array of strings and compares each character to the target string. This is the only way to test if the strings are the same. 

//DEFINE THESE FUNCTIONS
int searchArray(int array[], int size, int target)
{
  for (int i=0; i<size; i++) //for every element in the array
    {
      int element = array[i];
      if (element == target)
	{
	  return i; 
	}
    }
}

int* searchPointer(int array[], int size, int target)
{
    for (int i=0; i<size; i++) //for every element in the array
    {
      int element = array[i];
      if (element == target)
	{
	  int* pointer = &element;
	  return pointer;
	}
    }
}

void copyArray(int source[], int size, int destination[])
{
  for (int i=0; i<size; i++)
    {
      destination[i] = source[i]; 
    }
} 

const char* searchStrings (const char* strings[], const char* targetString, int size)
{
    for (int i=0; i<size; i++) //for every element in the array
    {
      const char* element = strings[i]; //assume that last character is null
      strcmp (element, targetString, i);
    }
}

const char* strcmp (const char* element, const char* targetString, int size)
{
  for (int i=0; i<size; i++)
    {
      char character1 = element[i];
      char character2 = targetString[i];
      if (character1 == character2)
	{
	  return targetString; 
	}
    } 
}
  
//MAIN FUNCTION
int main() 
{
  int a[] = { 1,2,3,4 };
  int targ = 5;
  int size1 = sizeof(a);

  int dest[] = { 2,4,6,8,10 };
  int size2 = sizeof(dest);
  
  const char* strgs[] = {"pleasant", "fragrance", "fart", "defecate"};
  int size3 = sizeof(strgs);
  
  const char* targetStr = "defecate";
  int sorc[] = { 5,10,15,20 };
  
  searchArray(a, size1, targ);
  searchPointer(a, size1, targ);  
  copyArray(sorc, size2, dest);
  searchStrings(strgs, targetStr, size3);
 
  return 0;
}
