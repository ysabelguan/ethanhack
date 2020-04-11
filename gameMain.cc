//Ysabel Guan
//INHERITANCE ASSIGNMENT FOR 0212
//VERSION 1
#include "gameBaseChar.h"
#include "gameChar1.h"
#include "gameChar2.h"

int main()
{
  Warrior* char1 = new Hero;
  Warrior* char2 = new Villain;
  char1->fight();
  char2->fight();
  
  return 0;
}
