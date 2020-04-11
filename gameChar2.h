//Ysabel Guan
//INHERITANCE ASSIGNMENT FOR 0212
//VERSION 1 

#ifndef GAMECHAR2_HH
#define GAMECHAR2_HH
class Villain : public Warrior
{
public:
  Villain();
  void fight() override;
  void impale(); //villain has sword while hero has brass knuckles 
  void slice(); 
}; 
#endif
