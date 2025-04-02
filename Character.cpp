/*CS302-002, Program 3, May 2023
This Character.cpp file contains the implementation of the
Character, Adc, Tank, and Healer classes.
Character is the base class.
Adc, Tank, and Healer are its derived.
i.e. in a "is a" relationship
functions return true on success*/

#include "Character.h"
using namespace std;

//constructor, inits data
Character::Character() : name("not set"), atk(0), hp(0), mp(0) {}



//destructor, no dynamic mem
Character::~Character() {}



//this function copies the character passed in and returns true on success
bool Character::copy(const Character * op2)
{
	name = op2->name;
	atk = op2->atk;
	hp = op2->hp;
	mp = op2->mp;
	return true;
}



//this func checks if character name matches
bool Character::equal_to(const Character * op2) const
{
	if(op2->name == name)
		return true;
	return false;
}



//checks if character name is less than
bool Character::less_than(const Character * op2) const
{
	if(op2->name < name)
		return true;
	return false;
}



//checks if character name is greater than
bool Character::greater_than(const Character * op2) const
{
	if(op2->name > name)
		return true;
	return false;
}

/************************************/

//cons, inits data mem
Adc::Adc() : strength(0) {}



//destructor, no dynamic mem
Adc::~Adc() {}



//get the strength and return it
int Adc::get_strength() const
{
	return strength;
}


//RTTI FUNCTION
//copy character passed in, downcasts to Adc *
//does this to access strength
bool Adc::copy(const Character *& op2)
{
	bool result = Character::copy(op2);

	const Adc * adc_ptr = dynamic_cast<const Adc*>(op2);
	if(adc_ptr != nullptr)
		strength = adc_ptr->strength;
		
		//strength = op2->get_strength();
	else
		strength = 5;
	return result;
}



//this func returns attack dealt
int Adc::attack()
{
	return atk;
}



//this func reduces incoming dmg
int Adc::defend(const int incoming_dmg) const
{
	if(incoming_dmg == 0)
		return 0;
	int dmg_reduction = incoming_dmg - strength/2;
	if(dmg_reduction < 0)
		return 0;
	return dmg_reduction;
}



//this func displays character
int Adc::display() const 
{
	cout << "ADC Info " << endl
		 << "Name: " << name << endl
		 << "ATK: " << atk << endl
		 << "HP: " << hp << endl
		 << "MP: " << mp << endl
		 << endl;
	return 1;
}



//this func allows chara to take dmg
int Adc::take_dmg(const int incoming_dmg) 
{
	hp -= incoming_dmg;
	if(hp <= 0)
	{
		cout << "The character's HP has fallen to 0!\n\n";
		hp = 0;
		return hp;
	}
	cout << "The character has taken " << incoming_dmg << " dmg!\n";
	
	return hp;
}



//this func changes stats of chara to ones passed in
int Adc::change_stats(const string & a_name, const int a_atk, 
				 const int a_hp, const int a_mp) 
{
	name = a_name;
	strength = name.length();
	atk = a_atk + strength;
	hp = 100;
	mp = 0;
	return 1;
}

/**********************************************/

//default cons
Tank::Tank() : vitality(0) {}



//destructor, no dynamic mem to worry about
Tank::~Tank() {}



//this func returns attack dealt
int Tank::attack()
{
	return atk;
}



//this func reduces incoming dmg
int Tank::defend(const int incoming_dmg) const
{
	if(incoming_dmg == 0)
		return 0;
	int dmg_reduction = incoming_dmg - vitality/2;
	if(dmg_reduction < 0)
		return 0;
	return dmg_reduction;
}



//this func displays the character
int Tank::display() const 
{
	cout << "Tank Info " << endl
		 << "Name: " << name << endl
		 << "ATK: " << atk << endl
		 << "HP: " << hp << endl
		 << "MP: " << mp << endl
		 << endl;
	return 1;
}



//this func allows chara to take dmg
int Tank::take_dmg(const int incoming_dmg) 
{
	hp -= incoming_dmg;
	if(hp <= 0)
	{
		cout << "The character's HP has fallen to 0!\n\n";
		hp = 0;
		return hp;
	}
	cout << "The character has taken " << incoming_dmg << " dmg!\n";
	
	return hp;
}



//this func changes stats of chara to ones passed in
int Tank::change_stats(const string & a_name, const int a_atk, 
				 const int a_hp, const int a_mp) 
{
	name = a_name;
	vitality = 2 * name.length();
	atk = a_atk;
	hp = 100;
	mp = 0;
	return 1;
}

/**********************************************/

//default cons, init data mem
Healer::Healer() : intelligence(0) {}



//destructor, no dynamic mem to worry about
Healer::~Healer() {}



//this func returns attack dealt
int Healer::attack()
{
	return atk;
}



//this func reduces incoming dmg
int Healer::defend(const int incoming_dmg) const
{
	if(incoming_dmg == 0)
		return 0;
	int dmg_reduction = incoming_dmg;
	if(dmg_reduction < 0)
		return 0;
	return dmg_reduction;
}



//this func displays the chara
int Healer::display() const 
{
	cout << "Healer Info " << endl
		 << "Name: " << name << endl
		 << "ATK: " << atk << endl
		 << "HP: " << hp << endl
		 << "MP: " << mp << endl
		 << endl;
	return 1;
}



//this func allows the chara to take dmg
int Healer::take_dmg(const int incoming_dmg) 
{
	hp -= incoming_dmg;
	if(hp <= 0)
	{
		cout << "The character's HP has fallen to 0!\n\n";
		hp = 0;
		return hp;
	}
	cout << "The character has taken " << incoming_dmg << " dmg!\n";
	
	return hp;
}



//this func changes stats of chara to ones passed in
int Healer::change_stats(const string & a_name, const int a_atk, 
				 const int a_hp, const int a_mp) 
{
	name = a_name;
	intelligence = name.length();
	atk = a_atk;
	hp = 100;
	mp = 30 + 2 * intelligence;
	return 1;
}

/**********************************************/


