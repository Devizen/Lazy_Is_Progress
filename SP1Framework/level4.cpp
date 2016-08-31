#include  "level4.h"
#include "characters.h"
#include "game.h"
#include "health.h"

bool door5 = false;

//Done by Yoong Soon.
void level4()
{
	WORD charColor = 0x0C;
	WORD charColor2 = 0x0A;
	WORD yellow = 0xFFE0;

	string line = " ";
	COORD c;

	if (splash == true)
	{
		string name = "Text/Screen/level4.txt";
		loadlevel(name);

		c.X = 15;
		c.Y = 7;

		clearScreen();
		for (int i = 0; i <= y; i++)
		{
			line = map[i];
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}

		if (g_dCountTime < 59 && story == true)
		{
			name = "Text/Story/level4.txt";
			loadlevel(name);

			c.X = 0;
			c.Y = 0;

			clearScreen();
			for (int i = 0; i <= y; i++)
			{
				line = map[i];
				g_Console.writeToBuffer(c, line);
				c.Y++;
			}

			if (g_dCountTime < 55)
			{
				splash = false;
				story = false;
				renderGame();
			}
		}

		if (g_dCountTime < 59 && story == false)
		{
			splash = false;
			renderGame();
		}
	}

	if (splash == false)
	{
		string name = "Text/Level/level4.txt";
		loadlevel(name);

		//COORD c;

		c.X = 0;
		c.Y = 0;

		for (int i = 0; i <= y; i++)
		{
			line = map[i];
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}

		COORD y;
		y.X = 15;
		y.Y = 15;

		//string line = " ";
		//string name = "Text/Level/level4.txt";
		//loadlevel(name);
		//COORD c;


		//c.X = 0;
		//c.Y = 0;


		//for (int i = 0; i <= y; i++)
		//{
		//	line = map[i];
		//	g_Console.writeToBuffer(c, line);
		//	c.Y++;
		//}

	
		rendercharacters();
		//motiondetect();
		//patrolfour();

		if (boxreturn(boxone) == true || boxreturndoor(boxone, g_door5) == true)
		{
			boxone.m_cLocation.X = 14;
			boxone.m_cLocation.Y = 8;
		}

		if (boxreturn(boxtwo) == true)
		{
			boxtwo.m_cLocation.X = 41;
			boxtwo.m_cLocation.Y = 18;
		}


		//Unlock Door 1
		if (map[boxone.m_cLocation.Y][boxone.m_cLocation.X] == map[g_lever1.m_cLocation.Y][g_lever1.m_cLocation.X])
		{
			g_Console.writeToBuffer(boxone.m_cLocation, (char)219, charColor2);
			g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, charColor2);
			g_Console.writeToBuffer(g_door2.m_cLocation, (char)219, charColor2);
			g_Console.writeToBuffer(g_door3.m_cLocation, (char)219, charColor2);
			g_Console.writeToBuffer(g_door4.m_cLocation, (char)219, charColor2);

			door1 = true;
			door2 = true;
			door3 = true;
			door4 = true;
		}
		else
		{
			door1 = false;
			door2 = false;
			door3 = false;
			door4 = false;
		}

		//Unlock Door 2
		if (map[boxtwo.m_cLocation.Y][boxtwo.m_cLocation.X] == map[g_lever3.m_cLocation.Y][g_lever3.m_cLocation.X])
		{
			g_Console.writeToBuffer(boxtwo.m_cLocation, (char)219, charColor2);
			g_Console.writeToBuffer(g_door5.m_cLocation, (char)219, charColor2);

			door5 = true;
		}
		else
		{
			door5 = false;
		}
	
		if ((g_enemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y) ||
			(g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y))
		{
			//Set boolean to false so the health will not reset.
			restarthealth = false;


			//Deduct one health.
			g_sChar.health -= 1;

			//Displaying Splash Screen.
			splash = true;

			//Revert the level settings.
			spawn();
		}

		//Teleport character to the right.

		if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == map[g_lever2.m_cLocation.Y][g_lever2.m_cLocation.X])
		{
			g_sChar.m_cLocation.X = 48;
			g_sChar.m_cLocation.Y = 8;
		}
	   /* if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == map[g_portal.m_cLocation.Y][g_portal.m_cLocation.X])
		{
			g_sChar.m_cLocation.X = 3;
			g_sChar.m_cLocation.Y = 1;
		}*/
		


		//Teleport character to the left.
		if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X] == map[g_portal.m_cLocation.Y][g_portal.m_cLocation.X])
		{
			g_nChar.m_cLocation.X = 3;
			g_nChar.m_cLocation.Y = 1;
		}
	/*	if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X] == map[g_lever2.m_cLocation.Y][g_lever2.m_cLocation.X])
		{
			g_nChar.m_cLocation.X = 48;
			g_nChar.m_cLocation.Y = 8;
		}
*/
		if (g_sChar.health < 1)
		{
			level = four;
			load = defeated;
			renderGame();
			rendercharacters();
		}
	}

}

