/*CS302-002, Program 3, May 2023
This file contains the class interface for the
Character, Adc, Tank, and Healer classes.
Character is the base class and the rest mentioned
are classes derived from it.
All characters have a name and stats like
atk (attack), hp (health pts), and mp (mana/magic pts).
The Character class is also an ABC.
Adc stands for attack damage carry and so characters of
this class do higher dmg with their attacks.
Adcs have moderate defending abilities.
Tanks have higher survivalability and so characters of
this class have higher hp and take less dmg when defending.
Healers have a special skill that allows them to be able to
regain hp. However, they are poor at defending.*/

#include <iostream>
#include <cstring>
#include <string>
#include <array>
#include <memory>
//required new library : cstdlib
//found: on web while searching for how to generate random numbers
//functionality: this library is used for generating random numbers
#include <cstdlib>
using std::string;

//ABC : Character
//this class manages all commonalities of 
//what a character has. 
//functions return true on success
class Character
{
	public:
		//constructor
		Character();
		//cons w/args
		Character(const string & a_name, const int a_atk, 
				  const int a_hp, const int a_mp);
		//virtual des
		virtual ~Character();

		//virtual functions
		//attack
		virtual int attack() = 0;
		//defend
		virtual int defend(const int incoming_dmg)const = 0;
		//display character info
		virtual int display() const = 0;
		//when the character is attacked
		virtual int take_dmg(const int incoming_dmg) = 0;
		//change the character's stats
		virtual int change_stats(const string & a_name, const int a_atk, 
								 const int a_hp, const int a_mp) = 0;
		//functions to compare the name
		virtual bool equal_to(const Character * op2) const;
		virtual bool less_than(const Character * op2) const;
		virtual bool greater_than(const Character * op2) const;

		//copy a Character
		virtual bool copy(const Character * op2);

	protected:
		string name; 	//character's name
		//string type;
		//the character's stats
		int atk; 	//attack
		int hp;		//health points
		int mp;		//magic points (mana)

};

//Attack damage carry, does extra dmg
//attacks will get a boost based on the strength of 
//the character
//will take less dmg when defending based on strength too
//functions return true on success
class Adc : public Character
{
//functions return true on success
	public:
		//default cons
		Adc();
		//destructor
		~Adc();
		//attack
		int attack() override;
		//defend
		int defend(const int incoming_dmg) const override;
		//display adc's info
		int display() const override;
		//when the chara is attacked
		int take_dmg(const int incoming_dmg) override;
		//change its stats
		int change_stats(const string & a_name, const int a_atk, 
						 const int a_hp, const int a_mp) override;
		//RTTI FUNCTION, uses downcasting
		//copies the adc passed in
		bool copy(const Character *& op2);
		//get the strength and return it
		int get_strength() const;

	private:
		int strength;	//determines atk boost
};

//Tank, has more hp
//hp increase is based on character's vit
//will take less dmg when defending based on vit value
//functions return true on success
class Tank : public Character
{
	public:
		//default cons
		Tank();
		//destructor
		~Tank();
		//attack
		int attack() override;
		//defend
		int defend(const int incoming_dmg) const override;
		//display
		int display() const override;
		//take damage
		int take_dmg(const int incoming_dmg) override;
		//change stats
		int change_stats(const string & a_name, const int a_atk, 
						 const int a_hp, const int a_mp) override;

	private:
	int vitality; //hp bonus
};

//Healer, can restore hp
//has weak defense though
//functions return true on success
class Healer : public Character
{
	public:
		//default cons
		Healer();
		//destructor
		~Healer();
		//attack
		int attack() override;
		//defend
		int defend(const int incoming_dmg) const override;
		//display
		int display() const override;
		//take damage
		int take_dmg(const int incoming_dmg) override;
		//change stats
		int change_stats(const string & a_name, const int a_atk, 
						 const int a_hp, const int a_mp) override;
	private:
	   int intelligence; 
};
