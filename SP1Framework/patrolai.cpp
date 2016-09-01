#include "patrolai.h"

//Done by Eugene.
void patrolai()
{
	bool bSomethingHappened = false;

	if (ai_BounceTime > g_dElapsedTime)
	{
		return;
	}

	for (unsigned int loop = 1; loop != 5; loop++)
	{
		switch (loop)
		{
		case 1:
			if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219 &&
				g_enemy.m_cLocation.Y != 7 && g_enemy.m_cLocation.X == 38)
			{
				g_enemy.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219 &&
				g_enemy2.m_cLocation.Y == 5 && g_enemy2.m_cLocation.X != 42)
			{
				g_enemy2.m_cLocation.X--;
				bSomethingHappened = true;
			}

			if (map[g_enemy3.m_cLocation.Y + 1][g_enemy3.m_cLocation.X] != (char)219 &&
				g_enemy3.m_cLocation.Y != 4 && g_enemy3.m_cLocation.X == 49)
			{
				g_enemy3.m_cLocation.Y++;
				bSomethingHappened = true;
			}
			break;

		case 2:
			if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219 &&
				g_enemy.m_cLocation.X != 45 && g_enemy.m_cLocation.Y == 7)
			{

				g_enemy.m_cLocation.X++;
				bSomethingHappened = true;
			}

			if (map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219 &&
				g_enemy2.m_cLocation.Y != 2 && g_enemy2.m_cLocation.X == 42)
			{
				g_enemy2.m_cLocation.Y--;
				bSomethingHappened = true;
			}

			if (map[g_enemy3.m_cLocation.Y][g_enemy3.m_cLocation.X + 1] != (char)219 &&
				g_enemy3.m_cLocation.X != 59 && g_enemy3.m_cLocation.Y == 4)
			{

				g_enemy3.m_cLocation.X++;
				bSomethingHappened = true;
			}
			break;
		case 3:

			if (map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219 &&
				g_enemy.m_cLocation.Y != 3 && g_enemy.m_cLocation.X == 45)
			{
				g_enemy.m_cLocation.Y--;
				bSomethingHappened = true;
			}

			if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219 &&
				g_enemy2.m_cLocation.Y == 2 && g_enemy2.m_cLocation.X != 51)
			{
				g_enemy2.m_cLocation.X++;
				bSomethingHappened = true;
			}

			if (map[g_enemy3.m_cLocation.Y - 1][g_enemy3.m_cLocation.X] != (char)219 &&
				g_enemy3.m_cLocation.Y != 1 && g_enemy3.m_cLocation.X == 59)
			{
				g_enemy3.m_cLocation.Y--;
				bSomethingHappened = true;
			}
			break;

		case 4:

			if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219 &&
				g_enemy.m_cLocation.X != 38 && g_enemy.m_cLocation.Y == 3)
			{
				g_enemy.m_cLocation.X--;
				bSomethingHappened = true;
			}

			if (map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219 &&
				g_enemy2.m_cLocation.Y != 5 && g_enemy2.m_cLocation.X == 51)
			{
				g_enemy2.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			if (map[g_enemy3.m_cLocation.Y][g_enemy3.m_cLocation.X - 1] != (char)219 &&
				g_enemy3.m_cLocation.X != 49 && g_enemy3.m_cLocation.Y == 1)
			{
				g_enemy3.m_cLocation.X--;
				bSomethingHappened = true;
			}
			break;

			if (loop = 4)
			{
				loop = 1;
			}
		}


		if (g_enemy.m_cLocation.X == g_nChar.m_cLocation.X && g_enemy.m_cLocation.Y == g_nChar.m_cLocation.Y ||
			g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X && g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y ||
			g_enemy3.m_cLocation.X == g_nChar.m_cLocation.X && g_enemy3.m_cLocation.Y == g_nChar.m_cLocation.Y)
		{
			restarthealth = false;
			splash = true;

			//Resetting Doors.
			door1 = false;
			door2 = false;
			door3 = false;
			door4 = false;
			door5 = false;

			g_sChar.health -= 1;

			spawn();
		}
	}


	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		ai_BounceTime = g_dElapsedTime + 0.05f; // 125ms should be enough

	}
}

void patrolfiveb()
{
	bool bSomethingHappened = false;

	if (ai_BounceTime > g_dElapsedTime)
	{
		return;
	}

	for (unsigned int loop = 1; loop != 5; loop++)
	{
		switch (loop)
		{

		case 1:
			if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219 &&
				g_enemy.m_cLocation.Y != 18 && g_enemy.m_cLocation.X == 11)
			{
				g_enemy.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219 &&
				g_enemy2.m_cLocation.Y == 17 && g_enemy2.m_cLocation.X != 50)
			{
				g_enemy2.m_cLocation.X++;
				bSomethingHappened = true;
			}
			break;

		case 2:
			if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219 &&
				g_enemy.m_cLocation.X != 18 && g_enemy.m_cLocation.Y == 18)
			{

				g_enemy.m_cLocation.X++;
				bSomethingHappened = true;
			}

			if (map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219 &&
				g_enemy2.m_cLocation.Y != 18 && g_enemy2.m_cLocation.X == 50)
			{
				g_enemy2.m_cLocation.Y++;
				bSomethingHappened = true;
			}
			break;

		case 3:
			if (map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219 &&
				g_enemy.m_cLocation.Y != 17 && g_enemy.m_cLocation.X == 18)
			{
				g_enemy.m_cLocation.Y--;
				bSomethingHappened = true;
			}

			if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219 &&
				g_enemy2.m_cLocation.X != 43 && g_enemy2.m_cLocation.Y == 18)
			{
				g_enemy2.m_cLocation.X--;
				bSomethingHappened = true;
			}
			break;

		case 4:
			if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219 &&
				g_enemy.m_cLocation.X != 11 && g_enemy.m_cLocation.Y == 17)
			{
				g_enemy.m_cLocation.X--;
				bSomethingHappened = true;
			}

			if (map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219 &&
				g_enemy2.m_cLocation.Y != 17 && g_enemy2.m_cLocation.X == 43)
			{
				g_enemy2.m_cLocation.Y--;
				bSomethingHappened = true;
			}
			break;

			if (loop == 4)
			{
				loop = 1;
			}
		}
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		ai_BounceTime = g_dElapsedTime + 0.05f; // 125ms should be enough

	}
}

//Done by Eugene.
void patrolcredits()
{
	bool bSomethingHappened = false;

	if (ai_BounceTime > g_dElapsedTime)
	{
		return;
	}

	for (unsigned int loop = 1; loop != 5; loop++)
	{
		switch (loop)
		{
		case 1:
			if (map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219 &&
				g_sChar.m_cLocation.Y != 10 && g_sChar.m_cLocation.X == 3)
			{
				g_sChar.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			if (map[g_nChar.m_cLocation.Y + 1][g_nChar.m_cLocation.X] != (char)219 &&
				g_nChar.m_cLocation.Y != 10 && g_nChar.m_cLocation.X == 3)
			{
				g_nChar.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219 &&
				g_enemy.m_cLocation.Y != 10 && g_enemy.m_cLocation.X == 3)
			{
				g_enemy.m_cLocation.Y++;
				bSomethingHappened = true;
			}
			break;

		case 2:
			if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219 &&
				g_sChar.m_cLocation.X != 20 && g_sChar.m_cLocation.Y == 10)
			{

				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;
			}

			if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != (char)219 &&
				g_nChar.m_cLocation.X != 20 && g_nChar.m_cLocation.Y == 10)
			{
				g_nChar.m_cLocation.X++;
				bSomethingHappened = true;
			}

			if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219 &&
				g_enemy.m_cLocation.X != 20 && g_enemy.m_cLocation.Y == 10)
			{

				g_enemy.m_cLocation.X++;
				bSomethingHappened = true;
			}
			break;
		case 3:

			if (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219 &&
				g_sChar.m_cLocation.Y != 5 && g_sChar.m_cLocation.X == 20)
			{
				g_sChar.m_cLocation.Y--;
				bSomethingHappened = true;
			}

			if (map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] != (char)219 &&
				g_nChar.m_cLocation.Y != 5 && g_nChar.m_cLocation.X == 20)
			{
				g_nChar.m_cLocation.Y--;
				bSomethingHappened = true;
			}

			if (map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219 &&
				g_enemy.m_cLocation.Y != 5 && g_enemy.m_cLocation.X == 20)
			{
				g_enemy.m_cLocation.Y--;
				bSomethingHappened = true;
			}
			break;

		case 4:

			if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219 &&
				g_sChar.m_cLocation.X != 3 && g_sChar.m_cLocation.Y == 5)
			{
				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;
			}

			if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != (char)219 &&
				g_nChar.m_cLocation.X != 3 && g_nChar.m_cLocation.Y == 5)
			{
				g_nChar.m_cLocation.X--;
				bSomethingHappened = true;
			}

			if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219 &&
				g_enemy.m_cLocation.X != 3 && g_enemy.m_cLocation.Y == 5)
			{
				g_enemy.m_cLocation.X--;
				bSomethingHappened = true;
			}
			break;

			if (loop = 4)
			{
				loop = 1;
			}
		}
	}


	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		ai_BounceTime = g_dElapsedTime + 0.05f; // 125ms should be enough

	}
}