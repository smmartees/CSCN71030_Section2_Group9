#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>

//#define _CRT_SECURE_NO_WARNINGS

extern "C" {
#include "../Space Dungeon 1/Alien.h"
#include "../Space Dungeon 1/utils.h"
#include "../Space Dungeon 1/Progression.h"
#include "../Space Dungeon 1/Event.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SamsTests
{
	TEST_CLASS(Alien_Module_Tests)
	{

	public:
		
		TEST_METHOD(CreateAlien_001)
		{
			int comMod = 2;
			PPROGRESSION prog = initNewProg(comMod);

			PALIEN alien = CreateAlien(prog->diffMod);

			Assert::IsNotNull(alien);
		}
		TEST_METHOD(CreateAlien_health_001)
		{
			int comMod = 2;
			PPROGRESSION prog = initNewProg(comMod);

			PALIEN alien = CreateAlien(prog->diffMod);

			double healthFloor = ALIEN_HEALTH_FLOOR * prog->diffMod;
			double healthCeiling = (ALIEN_HEALTH_FLOOR + ALIEN_HEALTH_RANGE) * prog->diffMod;

			bool boolHealth = (alien->health >= healthFloor && alien->health <= healthCeiling);

			Assert::IsTrue(boolHealth);
		}
		TEST_METHOD(CreateAlien_attack_001)
		{
			int comMod = 2;
			PPROGRESSION prog = initNewProg(comMod);

			PALIEN alien = CreateAlien(prog->diffMod);

			double attackFloor = ALIEN_ATTACK_FLOOR * prog->diffMod;
			double attackCeiling = (ALIEN_ATTACK_FLOOR + ALIEN_ATTACK_RANGE) * prog->diffMod;

			bool boolAttack = (alien->attack >= attackFloor && alien->attack <= 9);

			Assert::IsTrue(boolAttack);

		}
		TEST_METHOD(CreateAlien_defence_001)
		{
			int comMod = 1;
			PPROGRESSION prog = initNewProg(comMod);

			PALIEN alien = CreateAlien(prog->diffMod);

			//double actualDefence = GetAlienDefence(*alien);

			bool boolDefence = (alien->defence >= 2 && alien->defence <= 6);

			Assert::IsTrue(boolDefence);

		}
		TEST_METHOD(CreateAlien_name_001)
		{
			// This test needs the defined ALIEN_NAME_OPTION to 1
			double difficultyMod = 1.00;
			PALIEN alien = CreateAlien(difficultyMod);

			char* actualResult = alien->name;
			bool nameMatch;

			if (strcmp(actualResult, "Dirty Space Xenomorph") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Dirty Space Pirate") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Dirty Space Kracken") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Grotesque Space Xenomorph") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Grotesque Space Pirate") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Grotesque Space Kracken") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Unfathomable Space Xenomorph") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Unfathomable Space Pirate") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Unfathomable Space Kracken") == 0)
				nameMatch = true;
			else
				nameMatch = false;

			Assert::IsTrue(nameMatch);

		}
		TEST_METHOD(SetAlienName_001)
		{
			// This test needs the defined ALIEN_NAME_OPTION to 1
			char* actualResult = SetAlienName();
			bool nameMatch;

			if (strcmp(actualResult, "Dirty Space Xenomorph") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Dirty Space Pirate") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Dirty Space Kracken") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Grotesque Space Xenomorph") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Grotesque Space Pirate") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Grotesque Space Kracken") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Unfathomable Space Xenomorph") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Unfathomable Space Pirate") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Unfathomable Space Kracken") == 0)
				nameMatch = true;
			else
				nameMatch = false;

			Assert::IsTrue(nameMatch);

		}
		TEST_METHOD(ReduceAlienHealth_001)
		{
			// This test needs the defined ALIEN_NAME_OPTION to 1
			double difficultyMod = 1.00;
			PALIEN alien = CreateAlien(difficultyMod);
			
			double damageReceived = 4.00;
			double expectedHealth = alien->health - damageReceived;
			ReduceAlienHealth(alien, damageReceived);
			double actualHealth = alien->health;

			Assert::AreEqual(expectedHealth, actualHealth);
		}
		TEST_METHOD(ReduceAlienHealth_002)
		{
			// This test needs the defined ALIEN_NAME_OPTION to 1
			double difficultyMod = 1.00;
			PALIEN alien = CreateAlien(difficultyMod);

			double damageReceived = 0.00;
			double expectedHealth = alien->health - damageReceived;
			ReduceAlienHealth(alien, damageReceived);
			double actualHealth = alien->health;

			Assert::AreEqual(expectedHealth, actualHealth);
		}
		TEST_METHOD(DestroyAlien_001)
		{
			// This test needs the defined ALIEN_NAME_OPTION to 1
			double difficultyMod = 1.00;
			PALIEN alien = CreateAlien(difficultyMod);

			bool expectedResult = true;
			bool actualResult = DestroyAlien(alien);

			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(GetAlienName_001)
		{
			// This test needs the defined ALIEN_NAME_OPTION to 1
			double difficultyMod = 1.00;
			PALIEN alien = CreateAlien(difficultyMod);

			/*char expectedResult[ALIEN_FULL_NAME] = "Dirty Space Xenomorph";
			char* actualResult = GetAlienName(*alien);

			Assert::AreEqual(expectedResult, actualResult);*/

			char* actualResult = GetAlienName(*alien);
			bool nameMatch;

			if (strcmp(actualResult, "Dirty Space Xenomorph") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Dirty Space Pirate") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Dirty Space Kracken") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Grotesque Space Xenomorph") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Grotesque Space Pirate") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Grotesque Space Kracken") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Unfathomable Space Xenomorph") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Unfathomable Space Pirate") == 0)
				nameMatch = true;
			else if (strcmp(actualResult, "Unfathomable Space Kracken") == 0)
				nameMatch = true;
			else
				nameMatch = false;

			Assert::IsTrue(nameMatch);

		}
		TEST_METHOD(GetAlienHealth_001)
		{
			// This test needs the defined ALIEN_NAME_OPTION to 1
			double difficultyMod = 1.00;
			PALIEN alien = CreateAlien(difficultyMod);

			double actualHealth = GetAlienHealth(*alien);
			double expectedHealth = alien->health;

			Assert::AreEqual(expectedHealth, actualHealth);
		}
		TEST_METHOD(GetAlienAttack_001)
		{
			// This test needs the defined ALIEN_NAME_OPTION to 1
			double difficultyMod = 1.00;
			PALIEN alien = CreateAlien(difficultyMod);

			double actualAttack = GetAlienAttack(*alien);
			double expectedAttack = alien->attack;

			Assert::AreEqual(expectedAttack, actualAttack);
		}
		TEST_METHOD(GetAlienDefence_001)
		{
			// This test needs the defined ALIEN_NAME_OPTION to 1
			double difficultyMod = 1.00;
			PALIEN alien = CreateAlien(difficultyMod);

			double actualDefence = GetAlienDefence(*alien);
			double expectedDefence = alien->defence;

			Assert::AreEqual(expectedDefence, actualDefence);
		}
	};

	TEST_CLASS(Progression_Module_Tests)
	{
	public:

		TEST_METHOD(initNewProg_001)
		{
			int comMod = 2;
			PPROGRESSION prog = initNewProg(comMod);

			Assert::IsNotNull(prog);

		}
		TEST_METHOD(initNewProg_002)
		{
			int comMod = 2;
			PPROGRESSION prog = initNewProg(comMod);
			
			Assert::IsTrue((prog->progCount == 1 && prog->commandMod == 2 
				&& prog->progMod == 1.01 && prog->diffMod == 1.03));

		}
		TEST_METHOD(SetProgMod_001)
		{
			int comMod = 3;
			PPROGRESSION prog = initNewProg(comMod);
			double expected = 1.01;

			Assert::AreEqual(expected, prog->progMod);
		}
		TEST_METHOD(SetDiffMod_001)
		{
			int comMod = 3;
			PPROGRESSION prog = initNewProg(comMod);
			double expected = 1.04;

			Assert::AreEqual(expected, prog->diffMod);
		}
		TEST_METHOD(incrProgCount_001)
		{
			int comMod = 3;
			PPROGRESSION prog = initNewProg(comMod);
			incrProgCount(prog);

			Assert::IsTrue((prog->progCount == 2 && prog->progMod == 1.02
				&& prog->diffMod == 1.05));
		}
	};

	TEST_CLASS(EventTrigger_Module_Tests)
	{
	public:

		TEST_METHOD(eventTrigger_001)
		{
			int actual = eventTrigger();

			Assert::IsTrue((actual == 1 || actual == 2));
		}
	};
}
