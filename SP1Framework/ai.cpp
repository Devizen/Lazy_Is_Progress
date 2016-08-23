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



	if (g_enemy.m_cLocation.X > 0 &&
		(g_enemy.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
		//g_enemy.m_cLocation.Y == g_nChar.m_cLocation.Y &&
		//(g_enemy.m_cLocation.X - g_nChar.m_cLocation.X) >= -4) &&
		map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
	{
		g_enemy.m_cLocation.X++;
		bSomethingHappened = true;
	}

	if (g_enemy.m_cLocation.X > 0 &&
		g_enemy.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
		//g_enemy.m_cLocation.Y == g_nChar.m_cLocation.Y &&
		//g_enemy.m_cLocation.X - g_nChar.m_cLocation.X <= 4 &&
		map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
	{
		g_enemy.m_cLocation.X--;
		bSomethingHappened = true;
	}

	//Duplicate Y++?
	if (g_enemy.m_cLocation.Y > 0 &&
		(g_enemy.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
		//g_enemy.m_cLocation.X == g_nChar.m_cLocation.X &&
		//(g_enemy.m_cLocation.Y - g_nChar.m_cLocation.Y) >= -4) &&
		map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
	{
		g_enemy.m_cLocation.Y++;
		bSomethingHappened = true;
	}

	if (g_enemy.m_cLocation.Y > 0 &&
		(g_enemy.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
		//g_enemy.m_cLocation.X == g_nChar.m_cLocation.X &&
		//(g_enemy.m_cLocation.Y - g_nChar.m_cLocation.Y) <= 4) &&
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


	//if (bSomethingHappened)
	//{
	//	// set the bounce time to some time in the future to prevent accidental triggers
	//	g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	//}

	//	while (1)
	//{
	//	g_enemy.m_cLocation.X += 1;
	//	g_enemy.m_cLocation.Y += 1;
	//	g_enemy.m_cLocation.X -= 1;
	//	g_enemy.m_cLocation.Y -= 1;
	//	break;
	//}
	//static int square_state = 0;

	//// bottom left to top left is done
	//if (g_enemy.m_cLocation.Y <= g_enemy.m_cLocation.Y- 25 && square_state == 0)
	//	square_state = 1;

	//// top left to top right is done
	//if (g_enemy.m_cLocation.X >= g_enemy.m_cLocation.X + 25 && square_state == 1)
	//	square_state = 2;

	//// top right to bottom right is done
	//if (g_enemy.m_cLocation.Y >= g_enemy.m_cLocation.Y + 25  && square_state == 2)
	//	square_state = 3;

	//// bottom right to bottom left is done
	//if (g_enemy.m_cLocation.X <= g_enemy.m_cLocation.X - 25  && square_state == 3)
	//	square_state = 0;

	//switch (square_state)
	//{
	//case 0: // bottom left to top left
	//	g_enemy.m_cLocation.Y -= 1;
	//	break;

	//case 1: // top left to top right
	//	g_enemy.m_cLocation.X += 1;
	//	break;

	//case 2: // top right to bottom right
	//	g_enemy.m_cLocation.Y += 1;
	//	break;

	//case 3: // bottom right to bottom left
	//	g_enemy.m_cLocation.X -= 1;
	//	break;
	//}

}