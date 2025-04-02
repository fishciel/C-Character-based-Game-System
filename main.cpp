/*CS302-002, Program 3, May 2023
This file contains the "fight" function that allows
two characters to battle.
In main, the functions of Character and it's derived,
and the BST are tested.
"menu" type interface */

//#include "Character.h"
#include "BST.h"
using namespace std;


//this function allows two characters to battle
//does rtti testing
void fight(Character * player, Character * opponent)
{
	int option{0};
	int player_hp{100};
	int opp_hp{100};
	int dmg{0};
	int healer{0};
	bool defending{false};
	bool healing{false};

	cout << "Is your character a healer?\n"
		 << "1. Yes\n"
		 << "2. No\n"
		 << endl;
	cin >> healer;
	cin.ignore(100, '\n');

	//test to see if character is a healer
	if(healer == 1)
	{
		const Healer * healer_ptr = dynamic_cast<const Healer*>(player);
		if(healer_ptr == nullptr)
		{
			cout << "Your character is not a healer\n";
			healer = 2;
		}
	}


	do
	{
		cout << "Your character: \n";
		player->display();

		cout<< "Your opponent's character: \n";
		opponent->display();
		
		if(healer == 1)
		{
			cout << "It's your turn to make a move.\n";
			cout << "1. Attack \n"
				 << "2. Defend \n"
				 << "3. Heal \n"
				 << endl;
		}
		else
		{
			cout << "It's your turn to make a move.\n";
			cout << "1. Attack \n"
				 << "2. Defend \n"
				 << endl;
		}
		cout << "Option: ";
		cin >> option;
		cin.ignore(100, '\n');
		cout << endl;
		
		//defend
		if(option == 2)
		{
			cout << "You will take less damage the next turn.\n";
			defending = true;
		}
		//heal
		else if(option == 3 && healer == 1)
		{
			cout << "You will regain hp when hit\n";
			healing = true;
			
		}
		//defaults to attack
		else
		{
			cout << "You have chosen to attack!\n";
			dmg = player->attack();
			opp_hp = opponent->take_dmg(dmg);
		}
		cout << endl;

		//opposing chara will also choose to attack
		cout << "Your opponent has chosen to attack!\n\n";
		dmg = opponent->attack();
		if(defending == true)
		{
			dmg -= player->defend(dmg);
			defending = false;
		}
		if(healing == true)
		{
			dmg -= 10;
			cout << "Your character has healed 10 hp!\n";
			healing = false;
		}
		player_hp = player->take_dmg(dmg);
	}
	while(player_hp != 0 && opp_hp != 0);

	if(player_hp == 0)
		cout << "Your character has lost!\n";
	else
		cout << "Your character has won!\n";
	
	cout << endl;
}



int main()
{
	int option{0};
	const int SIZE{6};
	//int count{0};
	//string name;
	int attack{0};
	int num1{0};
	int num2{0};
	//unique_ptr<Character> character_ptr;
	//Character * archive[SIZE]{nullptr};
	srand(time(nullptr));

	cout << "Welcome to the prog.3 game!\n"
		 << "The types of characters are: \n"
		 << "1. Adc, attack dmg carry\n"
		 << "2. Tank, higher survivalability\n"
		 << "3. Healer, can heal self\n\n";

	//just going to pre-build the characters
	Adc gunner;
	Adc rogue;
	Tank paladin;
	Tank guardian;
	Healer druid;
	Healer saintess;

	array<Character *, SIZE> archive;
	BST arena;

	//10-20 inclusive
	//attack = rand() % 11 + 11;

	archive[0] = &gunner;
	attack = rand() % 11 + 11;
	archive[0]->change_stats("gunner", attack, 0, 0);

	archive[1] = &rogue;
	attack = rand() % 11 + 11;
	archive[1]->change_stats("rogue", attack, 0, 0);

	archive[2] = &paladin;
	attack = rand() % 11 + 11;
	archive[2]->change_stats("paladin", attack, 0, 0);

	archive[3] = &guardian;
	attack = rand() % 11 + 11;
	archive[3]->change_stats("guardian", attack, 0, 0);

	archive[4] = &druid;
	attack = rand() % 11 + 11;
	archive[4]->change_stats("druid", attack, 0, 0);

	archive[5] = &saintess;
	attack = rand() % 11 + 11;
	archive[5]->change_stats("saintess", attack, 0, 0);
	
	cout << "Current archive of characters: \n";
	for(int i = 0; i < SIZE; ++i)
	{
		archive[i]->display();
	}
	cout << endl;
		
	cout << "End of current archive of characters...\n\n";

	//this is just testing my compare funcs
	/*
	cout << "testing matches...\n";
	archive[5]->display();
	if(archive[5]->equal_to(archive[5]) == true)
		cout << "saintess match!\n";
	else
		cout << "saintess does not match!\n";
	archive[4]->display();
	if(archive[5]->equal_to(archive[4]) == true)
		cout << "saintess match!\n";
	else
		cout << "saintess does not match!\n";
	*/


	cout << "Now adding characters in archive to arena...\n\n";
	for(int i = 0; i < SIZE; ++i)
	{
		arena.insert(archive[i]);
	}

	do
	{
		cout << "What would you like to do: \n"
			 << "1. Display archive (Array of Character *)\n"
			 << "2. Display arena, it is sorted by name (BST)\n"
			 << "3. Have two characters fight each other\n"
			 << "4. Remove a character from the arena\n"
			 << "5. Test RTTI function and quit\n"
			 << "6. Quit\n"
			 << "Option: ";
		cin >> option;
		cin.ignore(100, '\n');
		cout << endl;

		//display archive
		if(option == 1)
		{
			cout << "Current archive of characters: \n";
			for(int i = 0; i < SIZE; ++i)
			{
				archive[i]->display();
			}
			cout << endl;
				
			cout << "End of current archive of characters...\n\n";
		}
		//display BST
		else if(option == 2)
		{
			cout << "Displaying characters in the arena...\n";
			arena.display();
			cout << "Done displaying characters in the arena...\n\n";
		}
		//pick 2 characters to fight
		else if(option == 3)
		{
			cout << "Your options: \n";
			for(int i = 0; i < SIZE; ++i)
			{
				cout << "Option " << i << endl;
				archive[i]->display();
			}
			cout << "Your character (you control): ";
			cin >> num1;
			cin.ignore(100, '\n');

			cout << "Your opponent (AI controlled): ";
			cin >> num2;
			cin.ignore(100, '\n');

			if(num1 == num2)
				cout << "You can't have a character fight itself.\n";
			else if (num1 < 0 || num1 >= SIZE)
				cout << "Please pick a valid option\n";
			else if (num2 < 0 || num2 >= SIZE)
				cout << "Please pick a valid option\n";
			else
				fight(archive[num1], archive[num2]);
			cout << endl;
		}
		//remove a character
		else if(option == 4)
		{
			cout << "You've chosen to remove a character from the arena\n";
			cout << "Your options: \n";
			for(int i = 0; i < SIZE; ++i)
			{
				cout << "Option " << i << endl;
				archive[i]->display();
			}
			cout << "Select a character remove (0-5): ";
			cin >> option;
			cin.ignore(100, '\n');

			arena.remove(archive[option]);
			
			option = 4;
		}
	}
	while(option >= 1 && option <= 4);

	if(option == 6)
	{
		cout << "original: \n";
		archive[0]->display();
		cout << "to copy: \n";
		archive[1]->display();
		cout << "after using RTTI copy func: \n";
		archive[0]->copy(archive[1]);
		archive[0]->display();
		archive[1]->display();
		cout << endl << endl;
	}

	return 0;
}
