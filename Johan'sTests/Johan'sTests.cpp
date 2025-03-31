#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Space Dungeon 1/loot.h"
#include "../Space Dungeon 1/fight.h"
#include "../Space Dungeon 1/player.h"
#include "../Space Dungeon 1/alien.h"
#include "../Space Dungeon 1/utils.h"
#include "../Space Dungeon 1/Progression.h"
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
			PPROGRESSION prog= initNewProg(1);
			
			
			WEAPON* weapon = generateRandomWeapon(prog->diffMod);

			
			Assert::IsNotNull(weapon);

			//Check to see if weapon is not Null and length of name is greater than 0
			Assert::IsTrue(weapon->name != nullptr && strlen(weapon->name) > 0);

			Assert::IsTrue(weapon->damage >= 15.0 && weapon->damage <= 25.0);

			destroyWeapon(weapon);
		}
		//Testing the generateRandomArmour()
		TEST_METHOD(TEST_LOOT_006)
		{
			PPROGRESSION prog = initNewProg(1);
			ARMOUR* armour = generateRandomArmour(prog->diffMod);


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
		//Testing the saveWeapon function and loadWeapon function
		TEST_METHOD(TEST_LOOT_009) {

			// Create a test weapon
			WEAPON* testWeapon = createWeapon("Test Sword", 25.5);
			Assert::IsNotNull(testWeapon);

			// Save it to a test file
			FILE* fp = fopen("weapon_test.bin", "wb");
			Assert::IsNotNull(fp);
			saveWeapon(fp, testWeapon);
			fclose(fp);

			// open file for reading
			fp = fopen("weapon_test.bin", "rb");
			Assert::IsNotNull(fp);

			// Read weapon
			WEAPON* loadedWeapon = loadWeapon(fp);
			fclose(fp);

			Assert::IsNotNull(loadedWeapon);
			Assert::AreEqual(std::string(testWeapon->name), std::string(loadedWeapon->name));
			Assert::AreEqual(testWeapon->damage, loadedWeapon->damage);

		
			destroyWeapon(testWeapon);
			destroyWeapon(loadedWeapon);
		}
		//Testing the saveArmour function and loadArmour function
		TEST_METHOD(TEST_LOOT_010) {

			ARMOUR* testArmour = createArmour("Test Helmet", 18.75);
			Assert::IsNotNull(testArmour);

			// Save it to a test file
			FILE* fp = fopen("armour_test.bin", "wb");
			Assert::IsNotNull(fp);
			saveArmour(fp, testArmour);
			fclose(fp);

			// Reopen file for reading
			fp = fopen("armour_test.bin", "rb");
			Assert::IsNotNull(fp);

			// Read back the armour
			ARMOUR* loadedArmour = loadArmour(fp);
			fclose(fp);

			// Validate that the armour data matches
			Assert::IsNotNull(loadedArmour);
			Assert::AreEqual(std::string(testArmour->name), std::string(loadedArmour->name));
			Assert::AreEqual(testArmour->protection, loadedArmour->protection);

			// Clean up memory
			destroyArmour(testArmour);
			destroyArmour(loadedArmour);

		}
		TEST_METHOD(TEST_FIGHT_001)
		{ // Set up test environment
		
			WEAPON* weapon = createWeapon("Sword", 10.00);
			ARMOUR* armour = createArmour("Helmet", 0.00);

			PPLAYER player = createPlayer(100, armour, weapon, 1);

			PALIEN alien = CreateAlien(1.0);
			double alienHealth = GetAlienHealth(*alien);

			// Manually set values for testing
			alien->health = 100.0;
			alien->attack = 10.0;
			alien->defence = 0.0;
			
		
			changeHealth(player, 20.00);
			ReduceAlienHealth(alien, 0);
			calculateDamage(player, alien, 1);


			// Expected values
			double expectedPlayerHealth = 80.00;
			double expectedAlienHealth = 90.00 ;

			// Assertions
			Assert::AreEqual(expectedPlayerHealth, player->health);
			Assert::AreEqual(expectedAlienHealth, alien->health);
			destroyPlayer(player);
			DestroyAlien(alien);
		}



	};
}
