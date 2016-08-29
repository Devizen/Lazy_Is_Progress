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

	/*case levelzerob:*/
		//For First Character
		//Move Right
		//if (g_enemy.m_cLocation.X > 0 &&
		//	(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
		//	map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
		//{
		//	if (door2 == true || door4 == true)
		//	{
		//		g_enemy.m_cLocation.X++;
		//		bSomethingHappened = true;
		//	}
		//	else if (door2 == false || door4 == false)
		//	{
		//		if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] !=
		//			map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] ||
		//			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] !=
		//			map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X])
		//		{
		//			g_enemy.m_cLocation.X++;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}

		////Move Left
		//if (g_enemy.m_cLocation.X > 0 &&
		//	g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
		//	map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
		//{
		//	if (door2 == true || door4 == true)
		//	{
		//		g_enemy.m_cLocation.X--;
		//		bSomethingHappened = true;
		//	}
		//	else if (door2 == false || door4 == false)
		//	{
		//		if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] !=
		//			map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] ||
		//			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] !=
		//			map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X])
		//		{
		//			g_enemy.m_cLocation.X--;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}

		////Move Down
		//if (g_enemy.m_cLocation.Y > 0 &&
		//	(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
		//	map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
		//{
		//	//if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] == map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] &&
		//	//	door2 == true)
		//	//{
		//	//	g_enemy.m_cLocation.Y++;
		//	//	bSomethingHappened = true;
		//	//}
		//	//else if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] == map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X] &&
		//	//	door4 == true)
		//	//{
		//	//	g_enemy.m_cLocation.Y++;
		//	//	bSomethingHappened = true;
		//	//}
		//	if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] &&
		//		door4 == true)
		//	{
		//		g_enemy.m_cLocation.Y++;
		//		bSomethingHappened = true;
		//	}
		//	else if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X] &&
		//		door2 == true)
		//	{
		//		g_enemy.m_cLocation.Y++;
		//		bSomethingHappened = true;
		//	}
		//	else if (door2 == false && door4 == false)
		//	{
		//		if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] !=
		//			map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] ||
		//			map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X ] !=
		//			map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X])
		//		{
		//			g_enemy.m_cLocation.Y++;
		//			bSomethingHappened = true;
		//		}
		//	}
		//	else if (door4 == true && 
		//		map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] !=
		//		map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X])
		//	{
		//		g_enemy.m_cLocation.Y++;
		//	}
		//}

		////Move Up
		//if (g_enemy.m_cLocation.Y > 0 &&
		//	(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
		//	map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
		//{
		//	if (door2 == true || door4 == true)
		//	{
		//		g_enemy.m_cLocation.Y--;
		//		bSomethingHappened = true;
		//	}
		//	else if (door2 == false || door4 == false)
		//	{
		//		if (map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] !=
		//			map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] ||
		//			map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] !=
		//			map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X])
		//		{
		//			g_enemy.m_cLocation.Y--;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}

		////For Second Character
		////Move Right
		//if (g_enemy2.m_cLocation.X > 0 &&
		//	(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
		//	map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
		//{
		//	if (door1 == true || door3 == true)
		//	{
		//		g_enemy2.m_cLocation.X++;
		//		bSomethingHappened = true;
		//	}
		//	else if (door1 == false || door3 == false)
		//	{
		//		if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] !=
		//			map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] ||
		//			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] !=
		//			map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
		//		{
		//			g_enemy2.m_cLocation.X++;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}

		////Move Left
		//if (g_enemy2.m_cLocation.X > 0 &&
		//	g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
		//	map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
		//{
		//	if (door1 == true || door3 == true)
		//	{
		//		g_enemy2.m_cLocation.X--;
		//		bSomethingHappened = true;
		//	}
		//	else if (door1 == false || door3 == false)
		//	{
		//		if (map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] !=
		//			map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] ||
		//			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] !=
		//			map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
		//		{
		//			g_enemy2.m_cLocation.X--;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}

		////Move Down
		//if (g_enemy2.m_cLocation.Y > 0 &&
		//	(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
		//	map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
		//{
		//	if (door1 == true || door3 == true)
		//	{
		//		g_enemy2.m_cLocation.Y++;
		//		bSomethingHappened = true;
		//	}
		//	else if (door1 == false || door3 == false)
		//	{
		//		if (map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
		//			map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] || 
		//			map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
		//			map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
		//		{
		//			g_enemy2.m_cLocation.Y++;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}

		////Move Up
		//if (g_enemy2.m_cLocation.Y > 0 &&
		//	(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
		//	map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
		//{
		//	if (door1 == true || door3 == true)
		//	{
		//		g_enemy2.m_cLocation.Y--;
		//		bSomethingHappened = true;
		//	}
		//	else if (door1 == false || door3 == false)
		//	{
		//		if (map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] !=
		//			map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] ||
		//			map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] !=
		//			map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
		//		{
		//			g_enemy2.m_cLocation.Y--;
		//			bSomethingHappened = true;
		//		}
		//	}
		//}
	/*	break;*/

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
			ai_BounceTime = g_dElapsedTime + 0.15; // 125ms should be enough
		}
		break;

	case leveltwo:
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
			ai_BounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
		}
		break;
	}

	//if (bSomethingHappened)
	//{
	//	// set the bounce time to some time in the future to prevent accidental triggers
	//	ai_BounceTime = g_dElapsedTime + 0.175; // 125ms should be enough
	//}
}

//Done by Eugene.
void rendercharacters()
{
	WORD charColor = 0x0C;
	WORD charColor2 = 0x0A;
	WORD charColor3 = 0x2B;
	WORD yellow = 0x5E;
	WORD purple = 0x780F;


	//const WORD colors[] =
	//{
	//	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	//	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	//};

	switch (load)
	{
	case levelzeroa:
		//First Character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

		//Second Character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

		break;

	case levelzerob:
		//First Character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

		//Second Character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
		//g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

		//Doors
		g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(g_door2.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(g_door3.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(g_door4.m_cLocation, (char)219, charColor);

		//Close Doors
		g_Console.writeToBuffer(closedoor1.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(closedoor2.m_cLocation, (char)219, charColor);

		//Levers
		g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, yellow);
		g_Console.writeToBuffer(g_lever2.m_cLocation, (char)219, yellow);
		g_Console.writeToBuffer(g_lever3.m_cLocation, (char)219, yellow);
		g_Console.writeToBuffer(g_lever4.m_cLocation, (char)219, yellow);

		//Boxes
		g_Console.writeToBuffer(boxone.m_cLocation, (char)254, charColor);
		g_Console.writeToBuffer(boxtwo.m_cLocation, (char)254, charColor);
		g_Console.writeToBuffer(boxthree.m_cLocation, (char)254, charColor);
		g_Console.writeToBuffer(boxfour.m_cLocation, (char)254, charColor);

		break;

	case levelone:

		//First Character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

		//Second Character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

		//Door
		g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, charColor);

		//Lever
		g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, yellow);

		//Teleporter
		g_Console.writeToBuffer(g_lever2.m_cLocation, (char)234, charColor3);

		//Box
		g_Console.writeToBuffer(g_box1.m_cLocation, (char)254, charColor);

		//Release A.I
		g_Console.writeToBuffer(release_enemy.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy1.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy2.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy3.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy4.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy5.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy6.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy7.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy8.m_cLocation, (char)219, charColor);

		//Powerup
		g_Console.writeToBuffer(g_powerup.m_cLocation, (char)206, charColor3);

		//TimerUp
		g_Console.writeToBuffer(g_timeboost.m_cLocation, (char)64, charColor3);
		break;

	case leveltwo:
		if (g_sChar.m_bActive)
		{
			charColor = 0x0A;
		}
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

		// Draw the location of the character
		if (g_nChar.m_bActive)
		{
			charColor = 0x0C;
		}
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

		//platform
		g_Console.writeToBuffer(g_platform.m_cLocation, (char)254, charColor3);

		//powerup
		COORD C;
		C.X = 23;
		C.Y = 10;

		g_Console.writeToBuffer(C, (char)206, charColor3);
		break;

	case levelthree:
		if (g_sChar.m_bActive)
		{
			charColor = 0x0A;
		}
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

		// Draw the location of the character
		if (g_nChar.m_bActive)
		{
			charColor = 0x0C;
		}
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

		//platform
		g_Console.writeToBuffer(g_platform.m_cLocation, (char)254, charColor3);

		//powerup
		C.X = 23;
		C.Y = 10;

		g_Console.writeToBuffer(C, (char)206, charColor3);
		break;
	}
}

//Done by Yoong Soon and Eugene.
void patrolenemy(struct SGameChar enemy)
{
	bool bSomethingHappened = false;
	if (ai_BounceTime > g_dElapsedTime)
	{
		return;
	}

	unsigned int randtemp;
	randtemp = 1 + rand() % 4;

	switch (load)
	{
	case levelzerob:
		{
			for (unsigned loop = 1; loop != 5; loop++)
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
			}
		}

		if (g_enemy.m_cLocation.X == g_nChar.m_cLocation.X && g_enemy.m_cLocation.Y == g_nChar.m_cLocation.Y)
		{
			restarthealth = false;
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

void epatrolenemy()
{
	enum direction
	{
		rightd,
		downd,
		leftd,
		upd
	};
	direction check = rightd;


	bool bSomethingHappened = false;
	if (ai_BounceTime > g_dElapsedTime)
	{
		return;
	}


	switch (check)
	{
	case rightd:
		if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 18] != (char)219 && check == rightd)
		{
			g_enemy.m_cLocation.X++;
			bSomethingHappened = true;
		}
		break;
		check = downd;

	case downd:
		if (map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219 && check == downd)
		{
			g_enemy.m_cLocation.Y++;
			bSomethingHappened = true;
		}
		break;
		check = leftd;

	case leftd:
		if (map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 2] != (char)219 && check == leftd)
		{
			g_enemy.m_cLocation.X--;
			bSomethingHappened = true;
		}
		break;
		check = upd;

	case upd:
		if (map[g_enemy.m_cLocation.Y - 8][g_enemy.m_cLocation.X] != (char)219 && check == upd)
		{
			g_enemy.m_cLocation.Y--;
			bSomethingHappened = true;
		}
		break;
		check = rightd;
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		ai_BounceTime = g_dElapsedTime + 0.05f; // 125ms should be enough

	}
}