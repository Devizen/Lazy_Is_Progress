#include "ai.h"
#include "level1.h"
#include "game.h"
#include "health.h"

//Done by Eugene.
void motiondetect()
{
	bool bSomethingHappened = false;
	if (ai_BounceTime > g_dElapsedTime)
	{
		return;
	}

	//For First Character
	if (g_enemy.m_cLocation.X > 0 &&
		(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
		//g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y &&
		//(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) >= -4) &&
		map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
	{
		g_enemy.m_cLocation.X++;
		bSomethingHappened = true;
	}

	if (g_enemy.m_cLocation.X > 0 &&
		g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 && 
		//g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y &&
		//g_enemy.m_cLocation.X - g_sChar.m_cLocation.X <= 4 && 
		map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
	{
		g_enemy.m_cLocation.X--;
		bSomethingHappened = true;
	}
	


	if (g_enemy.m_cLocation.Y > 0 &&
		(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
		//g_enemy.m_cLocation.X == g_sChar.m_cLocation.X &&
		//(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) >= -4) &&
		map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
	{
		g_enemy.m_cLocation.Y++;
		bSomethingHappened = true;
	}

	if (g_enemy2.m_cLocation.Y > 0 &&
		(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0)
	{
		switch (load)
		{
		case levelone:
			if (door1 == true)
			{
				if (map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
				{
					g_enemy2.m_cLocation.Y++;
					bSomethingHappened = true;
					break;
				}
			}
			if (door1 == false)
			{
				if (g_enemy2.m_cLocation.Y < g_Console.getConsoleSize().Y - 1 &&
					map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219 &&
					map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
					map[release_enemy.m_cLocation.Y][release_enemy.m_cLocation.X])
				{
					g_enemy2.m_cLocation.Y++;
					bSomethingHappened = true;
					break;
				}
			}
		case leveltwo:
			if (map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
			{
				g_enemy2.m_cLocation.Y++;
				bSomethingHappened = true;
				break;
			}
		}
	}


	if (g_enemy.m_cLocation.Y > 0 &&
		(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
		//g_enemy.m_cLocation.X == g_sChar.m_cLocation.X &&
		//(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) <= 4) &&
		map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
	{
		g_enemy.m_cLocation.Y--;
		bSomethingHappened = true;
	}

	//Second Character
	if (g_enemy2.m_cLocation.X > 0 &&
		(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
		//g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y &&
		//(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) >= -4) &&
		map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
	{
		g_enemy2.m_cLocation.X++;
		bSomethingHappened = true;

	}

	if (g_enemy2.m_cLocation.X > 0 &&
		g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
		//g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y &&
		//g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X <= 4 &&
		map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
	{
		g_enemy2.m_cLocation.X--;
		bSomethingHappened = true;
	}

	//if (g_enemy2.m_cLocation.Y > 0 &&
	//	(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
	//	//g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X &&
	//	//(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) >= -4) &&
	//	map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
	//{
	//	g_enemy2.m_cLocation.Y++;
	//	bSomethingHappened = true;
	//}


	if (g_enemy2.m_cLocation.Y > 0 &&
		(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
		//g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X &&
		//(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) <= 4) &&
		map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
	{
		g_enemy2.m_cLocation.Y--;
		bSomethingHappened = true;
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		ai_BounceTime = g_dElapsedTime + 0.175; // 125ms should be enough
	}

	if (map[g_box1.m_cLocation.Y][g_box1.m_cLocation.X] == (char)219)
	{
		g_box1.m_cLocation.X = 54;
		g_box1.m_cLocation.Y = 21;
	}
}