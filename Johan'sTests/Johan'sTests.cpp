#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Space Dungeon 1/loot.h"
#include "../Space Dungeon 1/fight.h"
#include "../Space Dungeon 1/player.h"
#include "../Space Dungeon 1/alien.h"
#include "../Space Dungeon 1/utils.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace JohansTests
{
	TEST_CLASS(JohansTests)
	{
	public:
		// Test to see if createWeapon() has successfully allocated memory for Weapon
		TEST_METHOD(TEST_LOOT_001)
		{
		
			WEAPON* weapon = createWeapon("Fire Sword", 20.0);

			// memory allocation was successful
			Assert::IsNotNull(weapon);
			destroyWeapon(weapon);
		}
		//Test on createWeapon() function to see expected value
		TEST_METHOD(TEST_LOOT_002)
		{

			char* expectedName = "Fire Sword";
			double expectedDamage = 20.0;


			WEAPON* weapon = createWeapon("Fire Sword", 20.0);


			Assert::AreEqual(expectedName, weapon->name);
			Assert::AreEqual(expectedDamage, weapon->damage);


			destroyWeapon(weapon);
		}
		// Test to see if createArmour() has successfully allocated memory for Armour
		TEST_METHOD(TEST_LOOT_003)
		{

			ARMOUR* armour = createArmour("Fire Helmet", 10.0);

			// memory allocation was successful
			Assert::IsNotNull(armour);
			destroyArmour(armour);
		}
		TEST_METHOD(TEST_LOOT_004) // createArmour() Test
		{
		    char* expectedName = "Fire Helmet";
			double expectedProtection = 10.0;

			ARMOUR* armour = createArmour(expectedName, expectedProtection);

			
			Assert::AreEqual(expectedName, armour->name);
			Assert::AreEqual(expectedProtection, armour->protection);

			destroyArmour(armour);
		}
		//Testing the generateRandomWeapon()
		TEST_METHOD(TEST_LOOT_005)
		{
			
			WEAPON* weapon = generateRandomWeapon();

			
			Assert::IsNotNull(weapon);

			//Check to see if weapon is not Null and length of name is greater than 0
			Assert::IsTrue(weapon->name != nullptr && strlen(weapon->name) > 0);

			Assert::IsTrue(weapon->damage >= 15.0 && weapon->damage <= 25.0);

			destroyWeapon(weapon);
		}
		//Testing the generateRandomArmour()
		TEST_METHOD(TEST_LOOT_006)
		{

			ARMOUR* armour = generateRandomArmour();


			Assert::IsNotNull(armour);

			//Check to see if armour is not Null and length of name is greater than 0
			Assert::IsTrue(armour->name != nullptr && strlen(armour->name) > 0);

			Assert::IsTrue(armour->protection >= 15.0 && armour->protection <= 25.0);

			destroyArmour(armour);
		}

		// Test to ensure createWeapon() handles negative damage 
		TEST_METHOD(TEST_LOOT_007)
		{
			WEAPON* weapon = createWeapon("Invalid Weapon", -5.0);
			Assert::IsNull(weapon);
			destroyWeapon(weapon);

		}
		// Test to ensure createArmour() handles negative protection
		TEST_METHOD(TEST_LOOT_008)
		{
			ARMOUR* armour = createArmour("Invalid armour", -3.0);
			Assert::IsNull(armour);
			destroyArmour(armour);
		}
		
		TEST_METHOD(TEST_FIGHT_001)
		{ // Set up test environment
			PPLAYER player = createPlayer(100,{"fire Helmet" , 0.0},{"Fire sword", 10.0},1);

			PALIEN alien = CreateAlien(1.0);
			

			// Manually set values for testing
			alien->health = 100.0;
			alien->attack = 10.0;
			alien->defence = 0.0;
			
		
			changeHealth(player, 20);
			ReduceAlienHealth(alien, 0);
			calculateDamage(player, alien, 1);


			// Expected values
			double expectedPlayerHealth = 80.0;
			double expectedAlienHealth = 90.0;

			// Assertions
			Assert::AreEqual(expectedPlayerHealth, player->health);
			Assert::AreEqual(expectedAlienHealth, alien->health);
			destroyPlayer(player);
			DestroyAlien(alien);
		}
		TEST_METHOD(TEST_SAVEWEAPON_001) {

			//// Set up test environment
			//char* testFilePath = "test_weapon.dat";
			//FILE* fp = fopen(testFilePath, "wb");

			//WEAPON weapon;
			//strcpy(weapon.name, "Sword");
			//weapon.damage = 50.0;

			//// Call function
			//saveWeapon(fp, &weapon);
			//fclose(fp);

			//// Reopen file to validate written data
			//fp = fopen(testFilePath, "rb");

			//// Read values from file
			//int weaponNameLength;
			//fread(&weaponNameLength, sizeof(int), 1, fp);
			//char weaponName[256];
			//fread(weaponName, sizeof(char), weaponNameLength, fp);
			//double weaponDamage;
			//fread(&weaponDamage, sizeof(double), 1, fp);
			//fclose(fp);

			//// Expected values
			//int expectedNameLength = 6; // "Sword" + null terminator
			//char expectedName[] = "Sword";
			//double expectedDamage = 50.0;

			//// Assertions
			//Assert::AreEqual(expectedNameLength, weaponNameLength);
			//Assert::AreEqual(0, strcmp(expectedName, weaponName)); // String comparison
			//Assert::AreEqual(expectedDamage, weaponDamage);
		}


	};
}
