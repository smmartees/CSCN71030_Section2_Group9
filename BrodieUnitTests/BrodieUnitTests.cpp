#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../Space Dungeon 1/loot.h"
#include "../Space Dungeon 1/player.h"
#include "../Space Dungeon 1/saveload.h"
#include "../Space Dungeon 1/Progression.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BrodieUnitTests
{
	TEST_CLASS(Player_Module)
	{
	public:
		
		TEST_METHOD(Test_createPlayer)
		{
			// default player values
			double health = 100.00;
			ARMOUR* armour = createArmour("Helmet", 10.50);
			WEAPON* weapon = createWeapon("Axe", 11.40);
			int potions = 0;
			PPLAYER player = createPlayer(health, armour, weapon, potions);

			double expectedHealth = 100.00;
			char* expectedArmourName = "Helmet";
			double expectedArmourRating = 10.50;
			char* expectedWeaponName = "Axe";
			double expectedWeaponRating = 11.40;
			int expectedPotions = 0;

			Assert::AreEqual(expectedHealth, player->health);
			Assert::AreEqual(expectedArmourName, player->armour->name);
			Assert::AreEqual(expectedArmourRating, player->armour->protection);
			Assert::AreEqual(expectedWeaponName, player->weapon->name);
			Assert::AreEqual(expectedWeaponRating, player->weapon->damage);
			Assert::AreEqual(expectedPotions, player->potions);

		}

		TEST_METHOD(Test_changeArmour)
		{
			// default player values
			double health = 100.00;
			ARMOUR* armour = createArmour("Helmet", 10.50);
			WEAPON* weapon = createWeapon("Axe", 11.40);
			int potions = 0;
			PPLAYER player = createPlayer(health, armour, weapon, potions);
			ARMOUR* newArmour = createArmour("ChestPlate", 15.00);
			
			changeArmour(player, newArmour);

			Assert::AreEqual(player->armour->name, "ChestPlate");
			Assert::AreEqual(player->armour->protection, 15.00);
		}

		TEST_METHOD(Test_changeWeapon)
		{
			// default player values
			double health = 100.00;
			ARMOUR* armour = createArmour("Helmet", 10.50);
			WEAPON* weapon = createWeapon("Axe", 11.40);
			int potions = 0;
			PPLAYER player = createPlayer(health, armour, weapon, potions);
			WEAPON* newWeapon = createWeapon("Sword", 14.25);

			changeWeapon(player, newWeapon);

			Assert::AreEqual(player->weapon->name, "Sword");
			Assert::AreEqual(player->weapon->damage, 14.25);
		}

		TEST_METHOD(Test_usePotion)
		{
			// default player values
			double health = 50.00;
			ARMOUR* armour = createArmour("Helmet", 10.50);
			WEAPON* weapon = createWeapon("Axe", 11.40);
			int potions = 1;
			PPLAYER player = createPlayer(health, armour, weapon, potions);
			
			usePotion(player);

			int expectedPotions = 0;
			double expectedHealth = 100.00;

			Assert::AreEqual(expectedPotions, player->potions);
			Assert::AreEqual(expectedHealth, player->health);
		}

		TEST_METHOD(Test_addPotion)
		{
			// default player values
			double health = 100.00;
			ARMOUR* armour = createArmour("Helmet", 10.50);
			WEAPON* weapon = createWeapon("Axe", 11.40);
			int potions = 0;
			PPLAYER player = createPlayer(health, armour, weapon, potions);

			addPotion(player);

			int expectedPotions = 1;

			Assert::AreEqual(expectedPotions, player->potions);
		}


		TEST_METHOD(Test_attack)
		{
			// default player values
			double health = 100.00;
			ARMOUR* armour = createArmour("Helmet", 10.50);
			WEAPON* weapon = createWeapon("Axe", 11.40);
			int potions = 0;
			PPLAYER player = createPlayer(health, armour, weapon, potions);

			double expectedDamage = 11.40;

			Assert::AreEqual(expectedDamage, attack(player));
		}

		TEST_METHOD(Test_changeHealth)
		{
			// default player values
			double health = 100.00;
			ARMOUR* armour = createArmour("Helmet", 10.50);
			WEAPON* weapon = createWeapon("Axe", 11.40);
			int potions = 0;
			PPLAYER player = createPlayer(health, armour, weapon, potions);

			double damage = 25.75;
			
			changeHealth(player, damage);

			double expectedHealth = 74.25;

			Assert::AreEqual(expectedHealth, player->health);
		}

	};

	TEST_CLASS(SaveLoad_Module)
	{
	public:

		TEST_METHOD(Test_SaveGame)
		{
			// default player values
			double health = 100.00;
			ARMOUR* armour = createArmour("Helmet", 10.50);
			WEAPON* weapon = createWeapon("Axe", 11.40);
			int potions = 0;
			PPLAYER player = createPlayer(health, armour, weapon, potions);

			ARMOUR* newArmour = createArmour("ChestPlate", 15.00);

			int modifier = 1;
			PPROGRESSION prog = initNewProg(modifier);

			bool saveCheck = saveGame(player, prog, "testFile.bin");

			Assert::AreEqual(saveCheck, true);
		}

		TEST_METHOD(Test_loadGame)
		{
			// initialize default player/progression values that will be saved
			double defaultHealth = 50.00;
			ARMOUR* defaultArmour = createArmour("Gloves", 5.50);
			WEAPON* defaultWeapon = createWeapon("Saber", 20.50);
			int defaultPotions = 5;
			PPLAYER defaultPlayer = createPlayer(defaultHealth, defaultArmour, defaultWeapon, defaultPotions);
			int defaultModifier = 1;
			PPROGRESSION defaultProg = initNewProg(defaultModifier);
			// change level progress of prog
			defaultProg->progCount = 2;

			bool saveCheck = saveGame(defaultPlayer, defaultProg, "testFile.bin");

			// initialize a player/progression who's vaules will be overwritten
			double Health = 100.00;
			ARMOUR* armour = createArmour("Helmet", 10.50);
			WEAPON* weapon = createWeapon("Axe", 11.40);
			int Potions = 0;
			int newModifier = 2;
			PPLAYER loadPlayer = createPlayer(Health, armour, weapon, Potions);
			PPROGRESSION loadProg = initNewProg(newModifier);


			bool loadCheck = loadGame(loadPlayer, loadProg, "testFile.bin");

			Assert::AreEqual(saveCheck, true);
			Assert::AreEqual(loadCheck, true);

			Assert::AreEqual(loadPlayer->armour->name, "Gloves");
			Assert::AreEqual(loadPlayer->armour->protection, 5.50);
			Assert::AreEqual(loadPlayer->weapon->name, "Saber");
			Assert::AreEqual(loadPlayer->weapon->damage, 20.50);
			Assert::AreEqual(loadPlayer->health, defaultHealth);
			Assert::AreEqual(loadPlayer->potions, defaultPotions);

			Assert::AreEqual(loadProg->commandMod, defaultModifier);
			Assert::AreEqual(loadProg->progCount, 2);
		}

	};


}
