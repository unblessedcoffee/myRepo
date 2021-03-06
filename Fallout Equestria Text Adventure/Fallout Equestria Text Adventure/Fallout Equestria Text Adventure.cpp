#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int Barter();
int Inventory(int armour, int weapon);

int GiveRandomWeapon(int* currentWeapon);
int GiveRandomArmour(int* currentArmour);

// this will be a very simple warmup text adventure
int main()
{
	int userChoice;
	int rollResult;

	int playerArmour = 10;
	int playerWeapon = 10;
	int playerArmourSave = 0;
	int playerWeaponBonus = 0;

	

	// start adventure
	cout << "You leave the Stable, full of hope.\n";
	
	do {

		// generate random number
		cout << "What would you like to do...\n";
		cout << "1: Continue your adventure.  2. Check your inventory.\n";
		cin >> userChoice;
		switch (userChoice)
		{
			case 1:
				cout << "In spite of it all, you must carry on...\n";
				break;
			case 2:
				Inventory(playerArmour, playerWeapon);
				break;
			default:
				cout << "I don't know what that means...\n";
		}


		rollResult = rand() % 10;

		// print it
		switch (rollResult)
		{
			case 0: case 1: case 2: case 3:
			{
				cout << "You roam the wastes for a time.\n";
				int encounterRoll = rand() % 10;

				// if we get a 9, get a random item
				if (encounterRoll < 9)
				{
					if (rand() % 2 != 0)
					{
						// even, return armour
						cout << "You found some armour.\n";
						playerArmourSave = GiveRandomArmour(&playerArmour);
					}
					else
					{
						// odd, return weapon
						cout << "You found a weapon.\n";
						playerWeaponBonus = GiveRandomWeapon(&playerWeapon);
					}
				}
				break;
			}
			case 4: case 5:
			{
				cout << "You encounter some vicious Raiders.\n";
				cout << "What will you do?\n";
				cin >> userChoice;
				break;
			}
			case 6:
			{
				cout << "You meet some Steel Rangers patrolling the area.\n";
				break;
			}
			case 7: case 8:
			{
				cout << "You encounter a small group of vengeful Alicorns.\n";
				cout << "What will you do?\n";
				cin >> userChoice;
				break;
			}
			case 9:
			{
				cout << "You arrive at a small settlement.\n";
				cout << "What will you do?\n";
				cin >> userChoice;
				break;
			}
			default:
				cout << "I don't know what to do here.\n";
				break;
		}
	

	} while (true);

	return 0;
}

int Barter()
{
	return 0;
}

// print out what items the player has equipped in their inventory.
int Inventory(int armour, int weapon)
{
	// print what items I have
	cout << "\n\n";
	switch (armour)
	{
	case 0: case 1:
		cout << "Apparel: \t" << "A crudely modified set of Stable overalls." << "\n";
		break;
	case 2: case 3:
		cout << "Apparel: \t" << "Lightly welded Metal armour." << "\n";
		break;
	case 4: case 5:
		cout << "Apparel: \t" << "Old combat armour from before the war." << "\n";
		break;
	case 6: case 7: case 8:
		cout << "Apparel: \t" << "Some simple leathers, used by most wastelanders." << "\n";
		break;
	case 9:
		cout << "Apparel: \t" << "Ancient Power armour, as used by the Steel Rangers." << "\n";
		break;
	case 10:
		cout << "Apparel: \t" << "Your old Stable overalls are filthy and stained." << "\n";
		break;
	default:
		break;
	}
	switch (weapon)
	{
	case 0: case 1:
		cout << "Armament: \t" << "A simple semi-automatic pistol." << "\n";
		break;
	case 2: case 3:
		cout << "Armament: \t" << "A substantials wooden stocked hunting rifle, shame about the condition." << "\n";
		break;
	case 4: case 5:
		cout << "Armament: \t" << "A magical rifle, the gems are on the way out." << "\n";
		break;
	case 6: case 7: case 8:
		cout << "Armament: \t" << "A blunt instrument is all you have to hand." << "\n";
		break;
	case 9:
		cout << "Armament: \t" << "A .44 magnum in mint condition, all you could ask for." << "\n";
		break;
	case 10:
		cout << "Armament: \t" << "Your hooves are all you can call upon at this time." << "\n";
		break;
	default:
		break;
	}
	cout << "\n\n";

	return 0;
}

// picks a random weapon and returns its save (from which it's type can be inferred.
// should also update the inventory number
int GiveRandomWeapon(int* currentWeapon)
{
	int encounterRoll = rand() % 10;
	if ((encounterRoll < *currentWeapon) && !(*currentWeapon == 10))
	{
		cout << "It's old junk compared to what you have." << "\n";
		return 0;
	}


	switch (encounterRoll)
	{
	case 0: case 1:
		cout << "Armament: \t" << "A simple semi-automatic pistol." << "\n";
		*currentWeapon = 0;
		return 2;
		break;
	case 2: case 3:
		cout << "Armament: \t" << "A substantials wooden stocked hunting rifle, shame about the condition." << "\n";
		*currentWeapon = 2;
		return 3;
		break;
	case 4: case 5:
		cout << "Armament: \t" << "A magical rifle, the gems are on the way out." << "\n";
		*currentWeapon = 4;
		return 4;
		break;
	case 6: case 7: case 8:
		cout << "Armament: \t" << "A blunt instrument is all you have to hand." << "\n";
		*currentWeapon = 6;
		return 1;
		break;
	case 9:
		cout << "Armament: \t" << "A .44 magnum in mint condition, all you could ask for." << "\n";
		*currentWeapon = 4;
		return 9;
		break;
	default:
		cout << "I don't know what to do here." << "\n";
	}
	return 0;
}

int GiveRandomArmour(int *currentArmour)
{
	int encounterRoll = rand() % 10;
	if ((encounterRoll < *currentArmour) && !(*currentArmour == 10))
	{
		cout << "It's old junk compared to what you have." << "\n";
		return 0;
	}


	switch (encounterRoll)
	{
	case 0: case 1:
		cout << "Apparel: \t" << "A crudely modified set of Stable overalls." << "\n";
		*currentArmour = 0;
		return 1;
		break;
	case 2: case 3:
		cout << "Apparel: \t" << "Lightly welded Metal armour." << "\n";
		*currentArmour = 2;
		return 2;
		break;
	case 4: case 5:
		cout << "Apparel: \t" << "Old combat armour from before the war." << "\n";
		*currentArmour = 4;
		return 3;
		break;
	case 6: case 7: case 8:
		cout << "Apparel: \t" << "Some simple leathers, used by most wastelanders." << "\n";
		*currentArmour = 6;
		return 1;
		break;
	case 9:
		cout << "Apparel: \t" << "Ancient Power armour, as used by the Steel Rangers." << "\n";
		*currentArmour = 9;
		return 4;
		break;
	default:
		break;
	}
	return 0;
}