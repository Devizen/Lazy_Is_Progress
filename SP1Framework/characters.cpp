#include "characters.h"
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

	switch (load)
	{
	case levelzeroa:
		//For First Character
		//Right
		if (g_enemy.m_cLocation.X > 0 &&
			(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
		{
			g_enemy.m_cLocation.X++;
			bSomethingHappened = true;
		}

		//Left
		if (g_enemy.m_cLocation.X > 0 &&
			g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
		{
			g_enemy.m_cLocation.X--;
			bSomethingHappened = true;
		}

		//Down
		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
			map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		//Up
		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
			map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		//For Second Character
		if (g_enemy2.m_cLocation.X > 0 &&
			(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
		{
			g_enemy2.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.X > 0 &&
			g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
		{
			g_enemy2.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
			map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
			map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		if (bSomethingHappened)
		{
			// set the bounce time to some time in the future to prevent accidental triggers
			ai_BounceTime = g_dElapsedTime + 0.124; // 125ms should be enough
		}
		break;

	case levelone:
		//For First Character
		if (g_enemy.m_cLocation.X > 0 &&
			(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
		{
			g_enemy.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.X > 0 &&
			g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
		{
			g_enemy.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
			map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
			map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		//Second Character
		if (g_enemy2.m_cLocation.X > 0 &&
			(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
		{
			g_enemy2.m_cLocation.X++;
			bSomethingHappened = true;

		}

		if (g_enemy2.m_cLocation.X > 0 &&
			g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
		{
			g_enemy2.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
			map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			check = downd;
			if (door1 == true)
			{
				g_enemy2.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			else if (door1 == false)
			{
				if (/*map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
					map[release_enemy.m_cLocation.Y][release_enemy.m_cLocation.X] ||*/
					releasestate(g_enemy2, release_enemy) == true ||
					releasestate(g_enemy2, release_enemy1) == true ||
					releasestate(g_enemy2, release_enemy2) == true ||
					releasestate(g_enemy2, release_enemy3) == true ||
					releasestate(g_enemy2, release_enemy4) == true ||
					releasestate(g_enemy2, release_enemy5) == true ||
					releasestate(g_enemy2, release_enemy6) == true ||
					releasestate(g_enemy2, release_enemy7) == true ||
					releasestate(g_enemy2, release_enemy8) == true)
				{
					g_enemy2.m_cLocation.Y++;
					bSomethingHappened = true;
				}
			}
			else
			{

			}
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
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

		break;

	case leveltwo:
		if (partb == false)
		{
			//For First Character
			if (g_enemy.m_cLocation.X > 0 &&
				(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
				map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
			{
				g_enemy.m_cLocation.X++;
				bSomethingHappened = true;
			}

			if (g_enemy.m_cLocation.X > 0 &&
				g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
				map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
			{
				g_enemy.m_cLocation.X--;
				bSomethingHappened = true;
			}

			if (g_enemy.m_cLocation.Y > 0 &&
				(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
				map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
			{
				g_enemy.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			if (g_enemy.m_cLocation.Y > 0 &&
				(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
				map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
			{
				g_enemy.m_cLocation.Y--;
				bSomethingHappened = true;
			}

			//For Second Character
			if (g_enemy2.m_cLocation.X > 0 &&
				(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
				map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
			{
				g_enemy2.m_cLocation.X++;
				bSomethingHappened = true;
			}

			if (g_enemy2.m_cLocation.X > 0 &&
				g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
				map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
			{
				g_enemy2.m_cLocation.X--;
				bSomethingHappened = true;
			}

			if (g_enemy2.m_cLocation.Y > 0 &&
				(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
				map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
			{
				g_enemy2.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			if (g_enemy2.m_cLocation.Y > 0 &&
				(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
				map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
			{
				g_enemy2.m_cLocation.Y--;
				bSomethingHappened = true;
			}

			if (bSomethingHappened)
			{
				// set the bounce time to some time in the future to prevent accidental triggers
				ai_BounceTime = g_dElapsedTime + 0.225; // 125ms should be enough
			}
		}
		else if (partb == true && partc == false)
		{
			if (g_enemy.m_cLocation.X > 0 &&
				(g_enemy.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
				map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
			{
				g_enemy.m_cLocation.X++;
				bSomethingHappened = true;
			}

			if (g_enemy.m_cLocation.X > 0 &&
				g_enemy.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
				map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
			{
				g_enemy.m_cLocation.X--;
				bSomethingHappened = true;
			}

			if (g_enemy.m_cLocation.Y > 0 &&
				(g_enemy.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
				map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
			{
				g_enemy.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			if (g_enemy.m_cLocation.Y > 0 &&
				(g_enemy.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
				map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
			{
				g_enemy.m_cLocation.Y--;
				bSomethingHappened = true;
			}

			//For Second Character
			if (g_enemy2.m_cLocation.X > 0 &&
				(g_enemy2.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
				map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
			{
				g_enemy2.m_cLocation.X++;
				bSomethingHappened = true;
			}

			if (g_enemy2.m_cLocation.X > 0 &&
				g_enemy2.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
				map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
			{
				g_enemy2.m_cLocation.X--;
				bSomethingHappened = true;
			}

			if (g_enemy2.m_cLocation.Y > 0 &&
				(g_enemy2.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
				map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
			{
				g_enemy2.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			if (g_enemy2.m_cLocation.Y > 0 &&
				(g_enemy2.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
				map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
			{
				g_enemy2.m_cLocation.Y--;
				bSomethingHappened = true;
			}

			if (bSomethingHappened)
			{
				// set the bounce time to some time in the future to prevent accidental triggers
				ai_BounceTime = g_dElapsedTime + 0.325; // 125ms should be enough
			}
		}
		else if (partc == true)
		{
			if (g_enemy.m_cLocation.X > 0 &&
				(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
				map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
			{
				g_enemy.m_cLocation.X++;
				bSomethingHappened = true;
			}

			if (g_enemy.m_cLocation.X > 0 &&
				g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
				map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
			{
				g_enemy.m_cLocation.X--;
				bSomethingHappened = true;
			}

			if (g_enemy.m_cLocation.Y > 0 &&
				(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
				map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
			{
				g_enemy.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			if (g_enemy.m_cLocation.Y > 0 &&
				(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
				map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
			{
				g_enemy.m_cLocation.Y--;
				bSomethingHappened = true;
			}

			//For Second Character
			if (g_enemy2.m_cLocation.X > 0 &&
				(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
				map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
			{
				g_enemy2.m_cLocation.X++;
				bSomethingHappened = true;
			}

			if (g_enemy2.m_cLocation.X > 0 &&
				g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
				map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
			{
				g_enemy2.m_cLocation.X--;
				bSomethingHappened = true;
			}

			if (g_enemy2.m_cLocation.Y > 0 &&
				(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
				map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
			{
				g_enemy2.m_cLocation.Y++;
				bSomethingHappened = true;
			}

			if (g_enemy2.m_cLocation.Y > 0 &&
				(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
				map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
			{
				g_enemy2.m_cLocation.Y--;
				bSomethingHappened = true;
			}

			if (bSomethingHappened)
			{
				// set the bounce time to some time in the future to prevent accidental triggers
				ai_BounceTime = g_dElapsedTime + 0.4; // 125ms should be enough
			}
		}
		break;
	case levelthree:
		//For First Character
		//Right
		if (g_enemy.m_cLocation.X > 0 &&
			(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
		{
			g_enemy.m_cLocation.X++;
			bSomethingHappened = true;
		}

		//Left
		if (g_enemy.m_cLocation.X > 0 &&
			g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
		{
			g_enemy.m_cLocation.X--;
			bSomethingHappened = true;
		}

		//Down
		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
			map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		//Up
		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
			map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		//For Second Character
		if (g_enemy2.m_cLocation.X > 0 &&
			(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
		{
			g_enemy2.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.X > 0 &&
			g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
		{
			g_enemy2.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
			map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
			map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		if (bSomethingHappened)
		{
			// set the bounce time to some time in the future to prevent accidental triggers
			ai_BounceTime = g_dElapsedTime + 0.124; // 125ms should be enough
		}
		break;


	case levelfiveb:
		//For First Character

		//Right
		if (g_enemy3.m_cLocation.X > 0 &&
			(g_enemy3.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
			map[g_enemy3.m_cLocation.Y][g_enemy3.m_cLocation.X + 1] != (char)219)
		{
			g_enemy3.m_cLocation.X++;
			bSomethingHappened = true;
		}

		//Left
		if (g_enemy3.m_cLocation.X > 0 &&
			g_enemy3.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
			map[g_enemy3.m_cLocation.Y][g_enemy3.m_cLocation.X - 1] != (char)219)
		{
			g_enemy3.m_cLocation.X--;
			bSomethingHappened = true;
		}

		//Down
		if (g_enemy3.m_cLocation.Y > 0 &&
			(g_enemy3.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
			map[g_enemy3.m_cLocation.Y + 1][g_enemy3.m_cLocation.X] != (char)219)
		{
			g_enemy3.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		//Up
		if (g_enemy3.m_cLocation.Y > 0 &&
			(g_enemy3.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
			map[g_enemy3.m_cLocation.Y - 1][g_enemy3.m_cLocation.X] != (char)219)
		{
			g_enemy3.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		//For Second Character
		if (g_enemy4.m_cLocation.X > 0 &&
			(g_enemy4.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
			map[g_enemy4.m_cLocation.Y][g_enemy4.m_cLocation.X + 1] != (char)219)
		{
			g_enemy4.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy4.m_cLocation.X > 0 &&
			g_enemy4.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
			map[g_enemy4.m_cLocation.Y][g_enemy4.m_cLocation.X - 1] != (char)219)
		{
			g_enemy4.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy4.m_cLocation.Y > 0 &&
			(g_enemy4.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
			map[g_enemy4.m_cLocation.Y + 1][g_enemy4.m_cLocation.X] != (char)219)
		{
			g_enemy4.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy4.m_cLocation.Y > 0 &&
			(g_enemy4.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
			map[g_enemy4.m_cLocation.Y - 1][g_enemy4.m_cLocation.X] != (char)219)
		{
			g_enemy4.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		if (bSomethingHappened)
		{
			// set the bounce time to some time in the future to prevent accidental triggers
			ai_BounceTime = g_dElapsedTime + 0.5; // 125ms should be enough
		}
		break;

	case levelfour:
		//For First Character
		//Right
		//if (g_enemy.m_cLocation.X > 0 &&
		//	(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
		//	map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
		//{
		//	g_enemy.m_cLocation.X++;
		//	bSomethingHappened = true;
		//}

		////Left
		//if (g_enemy.m_cLocation.X > 0 &&
		//	g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
		//	map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
		//{
		//	g_enemy.m_cLocation.X--;
		//	bSomethingHappened = true;
		//}

		////Down
		//if (g_enemy.m_cLocation.Y > 0 &&
		//	(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
		//	map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
		//{
		//	g_enemy.m_cLocation.Y++;
		//	bSomethingHappened = true;
		//}

		////Up
		//if (g_enemy.m_cLocation.Y > 0 &&
		//	(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
		//	map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
		//{
		//	g_enemy.m_cLocation.Y--;
		//	bSomethingHappened = true;
		//}

		//For Second Character
			if (g_nChar.m_cLocation.X > 30 && g_nChar.m_cLocation.Y < 80 && g_sChar.m_cLocation.X < 30 && g_sChar.m_cLocation.Y <80)/*(( map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X] - map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X] )
				<(map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] - map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X])))
				*/
			{
				if (g_enemy2.m_cLocation.X > 0 &&
					(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
					map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
				{
					if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] && door1 == false)
					{
						g_enemy2.m_cLocation.X++;
						bSomethingHappened = true;
					}

					else if (door1 == true)
					{
						g_enemy2.m_cLocation.X++;
						bSomethingHappened = true;
					}
				}

				if (g_enemy2.m_cLocation.X > 0 &&
					g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
					map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
				{
					if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X] && door3 == false)
					{
						g_enemy2.m_cLocation.X--;
						bSomethingHappened = true;
					}

					else if (door3 == true)
					{
						g_enemy2.m_cLocation.X--;
						bSomethingHappened = true;
					}
				}

				if (g_enemy2.m_cLocation.Y > 0 &&
					(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
					map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
				{
					if (map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] && door2 == false)
					{
						g_enemy2.m_cLocation.Y++;
						bSomethingHappened = true;
					}

					else if (door2 == true)
					{
						g_enemy2.m_cLocation.Y++;
						bSomethingHappened = true;
					}
				}

				if (g_enemy2.m_cLocation.Y > 0 &&
					(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
					map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
				{
					if (map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X] && door4 == false)
					{
						g_enemy2.m_cLocation.Y--;
						bSomethingHappened = true;
					}

					else if (door4 == true)
					{
						g_enemy2.m_cLocation.Y--;
						bSomethingHappened = true;
					}
				}
			}

			else if (g_sChar.m_cLocation.X > 30 && g_sChar.m_cLocation.Y < 80)/* && ((map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] - map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X])
				<(map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X] - map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X])))*/
			{
				if (((g_sChar.m_cLocation.X) - (g_enemy2.m_cLocation.X)) < ((g_nChar.m_cLocation.X) - (g_enemy2.m_cLocation.X)) ||
					((g_sChar.m_cLocation.Y) - (g_enemy2.m_cLocation.Y)) < ((g_nChar.m_cLocation.Y) - (g_enemy2.m_cLocation.Y)) ||
					((g_enemy2.m_cLocation.Y) - (g_sChar.m_cLocation.Y)) < ((g_enemy2.m_cLocation.Y) - (g_nChar.m_cLocation.Y)) ||
					((g_enemy2.m_cLocation.Y) - (g_sChar.m_cLocation.Y)) < ((g_enemy2.m_cLocation.Y) - (g_nChar.m_cLocation.Y)))
				{
					if (g_enemy2.m_cLocation.X > 0 &&
						(g_enemy2.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
						map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
					{
						if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] && door1 == false)
						{
							g_enemy2.m_cLocation.X++;
							bSomethingHappened = true;
						}

						else if (door1 == true)
						{
							g_enemy2.m_cLocation.X++;
							bSomethingHappened = true;
						}
					}

					if (g_enemy2.m_cLocation.X > 0 &&
						g_enemy2.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
						map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
					{
						if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X] && door3 == false)
						{
							g_enemy2.m_cLocation.X--;
							bSomethingHappened = true;
						}

						else if (door3 == true)
						{
							g_enemy2.m_cLocation.X--;
							bSomethingHappened = true;
						}
					}

					if (g_enemy2.m_cLocation.Y > 0 &&
						(g_enemy2.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
						map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
					{
						if (map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] && door2 == false)
						{
							g_enemy2.m_cLocation.Y++;
							bSomethingHappened = true;
						}

						else if (door2 == true)
						{
							g_enemy2.m_cLocation.Y++;
							bSomethingHappened = true;
						}
					}

					if (g_enemy2.m_cLocation.Y > 0 &&
						(g_enemy2.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
						map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
					{
						if (map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X] && door4 == false
							&& map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
						{
							g_enemy2.m_cLocation.Y--;
							bSomethingHappened = true;
						}

						else if (door4 == true)
						{
							g_enemy2.m_cLocation.Y--;
							bSomethingHappened = true;
						}
					}
				}
				else{
					if (g_enemy2.m_cLocation.X > 0 &&
						(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
						map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
					{
						if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] && door1 == false)
						{
							g_enemy2.m_cLocation.X++;
							bSomethingHappened = true;
						}

						else if (door1 == true)
						{
							g_enemy2.m_cLocation.X++;
							bSomethingHappened = true;
						}
					}

					if (g_enemy2.m_cLocation.X > 0 &&
						g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
						map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
					{
						if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X] && door3 == false)
						{
							g_enemy2.m_cLocation.X--;
							bSomethingHappened = true;
						}

						else if (door3 == true)
						{
							g_enemy2.m_cLocation.X--;
							bSomethingHappened = true;
						}
					}

					if (g_enemy2.m_cLocation.Y > 0 &&
						(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
						map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
					{
						if (map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] && door2 == false)
						{
							g_enemy2.m_cLocation.Y++;
							bSomethingHappened = true;
						}

						else if (door2 == true)
						{
							g_enemy2.m_cLocation.Y++;
							bSomethingHappened = true;
						}
					}

					if (g_enemy2.m_cLocation.Y > 0 &&
						(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
						map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
					{
						if (map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X] && door4 == false)
						{
							g_enemy2.m_cLocation.Y--;
							bSomethingHappened = true;
						}

						else if (door4 == true)
						{
							g_enemy2.m_cLocation.Y--;
							bSomethingHappened = true;
						}
					}
				}
				}
			

		if (bSomethingHappened)
		{
			// set the bounce time to some time in the future to prevent accidental triggers
			ai_BounceTime = g_dElapsedTime + 0.02f; // 125ms should be enough

		}
		break;
	}
	
}

//Done by Eugene.
void rendercharacters()
{
	switch (load)
	{
	case levelzeroa:
		//First Character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, red);

		//Second Character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, green);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, green);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, green);

		break;

	case levelzerob:
		//First Character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, red);

		//Second Character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, green);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, green);
		//g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, green);

		//Doors
		g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(g_door2.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(g_door3.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(g_door4.m_cLocation, (char)219, red);

		//Close Doors
		g_Console.writeToBuffer(closedoor1.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(closedoor2.m_cLocation, (char)219, red);

		//Levers
		g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, yellow);
		g_Console.writeToBuffer(g_lever2.m_cLocation, (char)219, yellow);
		g_Console.writeToBuffer(g_lever3.m_cLocation, (char)219, yellow);
		g_Console.writeToBuffer(g_lever4.m_cLocation, (char)219, yellow);

		//Boxes
		g_Console.writeToBuffer(boxone.m_cLocation, (char)254, red);
		g_Console.writeToBuffer(boxtwo.m_cLocation, (char)254, red);
		g_Console.writeToBuffer(boxthree.m_cLocation, (char)254, red);
		g_Console.writeToBuffer(boxfour.m_cLocation, (char)254, red);

		break;

	case levelone:

		//First Character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, red);

		//Second Character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, green);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, green);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, green);

		//Door
		g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, red);

		//Lever
		g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, yellow);

		//Teleporter
		g_Console.writeToBuffer(g_lever2.m_cLocation, (char)234, lightblue);

		//Box
		g_Console.writeToBuffer(g_box1.m_cLocation, (char)254, red);

		//Release A.I
		g_Console.writeToBuffer(release_enemy.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(release_enemy1.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(release_enemy2.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(release_enemy3.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(release_enemy4.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(release_enemy5.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(release_enemy6.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(release_enemy7.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(release_enemy8.m_cLocation, (char)219, red);

		//Powerup
		g_Console.writeToBuffer(g_powerup.m_cLocation, (char)206, purple);

		//TimerUp
		g_Console.writeToBuffer(g_timeboost.m_cLocation, (char)64, purple);
		break;

	case leveltwo:
		// Draw the location of the character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, red);

		// Draw the location of the character

		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, green);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, green);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, green);

		////platform
		//g_Console.writeToBuffer(g_platform.m_cLocation, (char)254, purple);

		////powerup
		//COORD C;
		//C.X = 23;
		//C.Y = 10;

		//g_Console.writeToBuffer(C, (char)206, purple);
		break;

	case levelthree:
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, red);

		// Draw the location of the character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, green);

		//Enemy

		
		

		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, green);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, green);

		//Lever
		g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, yellow);
		g_Console.writeToBuffer(g_lever4.m_cLocation, (char)219, yellow);


		//Door
		g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(g_door2.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(g_door3.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(g_door4.m_cLocation, (char)219, red);
		//Box
		g_Console.writeToBuffer(boxone.m_cLocation, (char)254, red);
		g_Console.writeToBuffer(boxone.m_cLocation, (char)254, red);
		g_Console.writeToBuffer(boxfour.m_cLocation, (char)254, red);
		g_Console.writeToBuffer(boxfour.m_cLocation, (char)254, red);
		

		//platform
		g_Console.writeToBuffer(g_platform.m_cLocation, (char)254, purple);

		//powerup
		//C.X = 23;
		//C.Y = 10;

		//g_Console.writeToBuffer(C, (char)206, purple);
		break;

	case levelfour:
		
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, red);

		// Draw the location of the character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, green);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, green);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, green);

		//Doors
		g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(g_door2.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(g_door3.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(g_door4.m_cLocation, (char)219, red);
		g_Console.writeToBuffer(g_door5.m_cLocation, (char)219, red);

		//Levers
		g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, yellow);
		g_Console.writeToBuffer(g_lever3.m_cLocation, (char)219, yellow);

		//Teleporter
		g_Console.writeToBuffer(g_lever2.m_cLocation, (char)234,lightblue);
		g_Console.writeToBuffer(g_portal.m_cLocation, (char)234,lightblue);

		//Boxes
		g_Console.writeToBuffer(boxone.m_cLocation, (char)254, red);
		g_Console.writeToBuffer(boxtwo.m_cLocation, (char)254, red);

		break;

	case levelfive:

			// Draw the location of the character
			g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, red);
			g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, green);

			//Enemy
			g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, green);
			g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, green);
			g_Console.writeToBuffer(g_enemy3.m_cLocation, (char)1, green);

			//Doors
			g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, red);
			g_Console.writeToBuffer(g_door2.m_cLocation, (char)219, red);
			g_Console.writeToBuffer(g_door3.m_cLocation, (char)219, red);
			g_Console.writeToBuffer(g_door4.m_cLocation, (char)219, red);
			g_Console.writeToBuffer(g_door5.m_cLocation, (char)219, red);

			//Time Boost
			g_Console.writeToBuffer(g_lever1.m_cLocation, (char)64, purple);
			g_Console.writeToBuffer(g_lever2.m_cLocation, (char)64, purple);
			g_Console.writeToBuffer(g_lever3.m_cLocation, (char)64, purple);
			g_Console.writeToBuffer(g_lever4.m_cLocation, (char)64, purple);
			g_Console.writeToBuffer(g_lever5.m_cLocation, (char)64, purple);
		break;

	case levelfiveb:

		// Draw the location of the character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, red);
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, green);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, green);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, green);
		g_Console.writeToBuffer(g_enemy3.m_cLocation, (char)1, green);
		g_Console.writeToBuffer(g_enemy4.m_cLocation, (char)1, green);

		//Teleporters
		g_Console.writeToBuffer(g_lever1.m_cLocation, (char)234, lightblue);
		g_Console.writeToBuffer(g_lever2.m_cLocation, (char)234, lightblue);
		//g_Console.writeToBuffer(g_lever3.m_cLocation, (char)234, lightblue);
		//g_Console.writeToBuffer(g_lever4.m_cLocation, (char)234, lightblue);
	}
}

//Done by Yoong Soon and Eugene.
void patrolzerob()
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
		{
			if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219 &&
				g_enemy.m_cLocation.Y != 12 && g_enemy.m_cLocation.X == 33)
			{
				g_enemy.m_cLocation.Y++;
				bSomethingHappened = true;
			}
			break;
		}

		case 2:
		{
			if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219 &&
				g_enemy.m_cLocation.X != 44 && g_enemy.m_cLocation.Y == 11)
			{

				g_enemy.m_cLocation.X++;
				bSomethingHappened = true;
			}
			break;
		}
		case 3:
		{
			if (map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219 &&
				g_enemy.m_cLocation.Y != 8 && g_enemy.m_cLocation.X == 44)
			{
				g_enemy.m_cLocation.Y--;
				bSomethingHappened = true;
			}
			break;
		}
		case 4:
		{
			if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219 &&
				g_enemy.m_cLocation.X != 33 && g_enemy.m_cLocation.Y == 8)
			{
				g_enemy.m_cLocation.X--;
				bSomethingHappened = true;
			}
			break;

		}

			if (loop = 4)
			{
				loop = 1;
			}
		}


		if (g_enemy.m_cLocation.X == g_nChar.m_cLocation.X && g_enemy.m_cLocation.Y == g_nChar.m_cLocation.Y)
		{
			restarthealth = false;
			splash = true;
			g_sChar.health -= 1;

			spawn();
		}
	}


	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		ai_BounceTime = g_dElapsedTime + 0.02f; // 125ms should be enough

	}
}

//Done by Yoong Soon and Eugene.
void patrolfour()
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
		{
			if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219 &&
				g_enemy.m_cLocation.Y != 15 && g_enemy.m_cLocation.X == 13)
			{
				g_enemy.m_cLocation.Y++;
				bSomethingHappened = true;
			}
			break;
		}

		case 2:
		{
			if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219 &&
				g_enemy.m_cLocation.X != 21 && g_enemy.m_cLocation.Y == 14)
			{

				g_enemy.m_cLocation.X++;
				bSomethingHappened = true;
			}
			break;
		}
		case 3:
		{
			if (map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219 &&
				g_enemy.m_cLocation.Y != 11 && g_enemy.m_cLocation.X == 21)
			{
				g_enemy.m_cLocation.Y--;
				bSomethingHappened = true;
			}
			break;
		}
		case 4:
		{
			if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219 &&
				g_enemy.m_cLocation.X != 13 && g_enemy.m_cLocation.Y == 11)
			{
				g_enemy.m_cLocation.X--;
				bSomethingHappened = true;
			}
			break;

		}
			if (loop = 4)
			{
				loop = 1;
			}
		}


		if (g_enemy.m_cLocation.X == g_nChar.m_cLocation.X && g_enemy.m_cLocation.Y == g_nChar.m_cLocation.Y)
		{
			restarthealth = false;
			splash = true;
			g_sChar.health -= 1;

			spawn();
		}
	}


	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		ai_BounceTime = g_dElapsedTime + 0.0222f; // 125ms should be enough

	}
}