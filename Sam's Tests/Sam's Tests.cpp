

#include "pch.h"
#include "CppUnitTest.h"

//#define _CRT_SECURE_NO_WARNINGS

extern "C" {
#include "../Space Dungeon 1/Alien.h"
#include "../Space Dungeon 1/Alien.c"
#include "../Space Dungeon 1/utils.h"
#include "../Space Dungeon 1/utils.c"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SamsTests
{
	TEST_CLASS(Alien_Module_Tests)
	{
	public:
		
		TEST_METHOD(CreateAlien_health_001)
		{
			double difficultyMod = 1.00;
			PALIEN alien = CreateAlien(difficultyMod);

			//double actualHealth = GetAlienHealth(*alien);
			//double actualAttack = GetAlienAttack(*alien);
			//double actualDefence = GetAlienDefence(*alien);
			//char* actualName = GetAlienName(*alien);

			bool boolHealth = (alien->health >= 10 && alien->health <= 30);
			//bool boolHealth = (actualHealth >= 10 && actualHealth <= 30);
			//bool boolAttack = (actualAttack >= 3 && actualAttack <= 9);
			//bool boolDefence = (actualDefence >= 2 && actualDefence <= 6);

			Assert::IsTrue(boolHealth);
			//Assert::IsTrue(boolAttack);
			//Assert::IsTrue(boolDefence);
		}
		TEST_METHOD(CreateAlien_attack_001)
		{
			double difficultyMod = 1.00;
			PALIEN alien = CreateAlien(difficultyMod);

			//double actualAttack = GetAlienAttack(*alien);

			bool boolAttack = (alien->attack >= 3 && alien->attack <= 9);

			Assert::IsTrue(boolAttack);

		}
		TEST_METHOD(CreateAlien_defence_001)
		{
			double difficultyMod = 1.00;
			PALIEN alien = CreateAlien(difficultyMod);

			//double actualDefence = GetAlienDefence(*alien);

			bool boolDefence = (alien->defence >= 2 && alien->defence <= 6);

			Assert::IsTrue(boolDefence);

		}
		TEST_METHOD(CreateAlien_name_001)
		{
			double difficultyMod = 1.00;
			PALIEN alien = CreateAlien(difficultyMod);

			//char* actualName = GetAlienName(*alien);
			char* actualName = alien->name;

			bool boolName = (actualName == "Dirty Space Xenomorph"
				|| actualName == "Dirty Space Pirate"
				|| actualName == "Grotesque Space Xenomorph"
				|| actualName == "Grotesque Space Pirate");

			Assert::IsTrue(boolName);

		}
	};
}
