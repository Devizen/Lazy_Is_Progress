#include "level2.h"
#include "characters.h"
#include "game.h"
#include "health.h"
SGameChar enemy;

//Done by Eugene.
void level2()
{

	WORD color = 0X4D;
	WORD color1 = 0x3C;
	WORD color2 = 0x2B;
	WORD red = 0x0C;
	WORD charColor2 = 0x0A;
	WORD charColor3 = 0x2B;
	WORD yellow = 0x5E;
	WORD purple = 0x780F;

	string line = " ";
	COORD c;

	if (splash == true)
	{
		string name = "Text/Screen/level2.txt";
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

		if (g_dCountTime < 59)
		{
			splash = false;
			renderGame();
		}
	}

	if (splash == false)
	{
		string name = "Text/Level/level2.txt";
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

		if (g_dCountTime <= 60 && g_dCountTime >= 50)
		{
			COORD d;
			d.X = 63;
			d.Y = 15;
			g_Console.writeToBuffer(d, "Run away from");
			d.Y = 16;
			g_Console.writeToBuffer(d, "the enemies for");
			d.Y = 17;
			g_Console.writeToBuffer(d, "10 seconds!");
		}
		if (g_dCountTime <= 50 && partb == false)
		{
			COORD d;
			d.X = 63;
			d.Y = 15;
			g_Console.writeToBuffer(d, "Hurry to the");
			d.Y = 16;
			g_Console.writeToBuffer(d, "teleporters!");
		}

		if (g_dCountTime <= 50 && partb == true)
		{
			COORD d;
			d.X = 63;
			d.Y = 15;
			g_Console.writeToBuffer(d, "Empty your mind.");
			d.Y = 16;
			g_Console.writeToBuffer(d, "Alternate mind.");
			d.Y = 17;
			g_Console.writeToBuffer(d, "Do you think");
			d.Y = 18;
			g_Console.writeToBuffer(d, "YOU can do it?");
		}

		if (partc == true)
		{
			COORD d;
			d.X = 63;
			d.Y = 15;
			g_Console.writeToBuffer(d, "                       ");
			g_Console.writeToBuffer(d, "You are now");
			d.Y = 16;
			g_Console.writeToBuffer(d, "MERGED as ONE.");
			d.Y = 17;
			g_Console.writeToBuffer(d, "Move and Escape");
			d.Y = 18;
			g_Console.writeToBuffer(d, "as a ONE being!");
		}
		//string line = " ";
		//string name = "Text/Level/level2.txt";
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

		//COORD y;
		//y.X = 15;
		//y.Y = 15;

		rendercharacters();
		motiondetect();
		

		if (g_dCountTime < 50 && partb == false)
		{
			//Teleporter
			g_portal.m_cLocation.X = 3;
			g_portal.m_cLocation.Y = 2;

			g_portal1.m_cLocation.X = 56;
			g_portal1.m_cLocation.Y = 22;

			//Teleporter
			g_Console.writeToBuffer(g_portal.m_cLocation, (char)234);
			g_Console.writeToBuffer(g_portal1.m_cLocation, (char)234);

			if (g_sChar.m_cLocation.X == 3 &&
				g_sChar.m_cLocation.Y == 2 &&
				g_nChar.m_cLocation.X == 56 &&
				g_nChar.m_cLocation.Y == 22)
			{
				g_nChar.m_cLocation.X = 15;
				g_nChar.m_cLocation.Y = 5;

				g_sChar.m_cLocation.X = 45;
				g_sChar.m_cLocation.Y = 19;
				partb = true;
			}
		}

		if (partb == true && partc == false)
		{
			//Teleporter
			g_portal.m_cLocation.X = 3;
			g_portal.m_cLocation.Y = 22;

			g_portal1.m_cLocation.X = 56;
			g_portal1.m_cLocation.Y = 2;

			//Teleporter
			g_Console.writeToBuffer(g_portal.m_cLocation, (char)234);
			g_Console.writeToBuffer(g_portal1.m_cLocation, (char)234);

			if (g_nChar.m_cLocation.X == 3 &&
				g_nChar.m_cLocation.Y == 22 &&
				g_sChar.m_cLocation.X == 56 &&
				g_sChar.m_cLocation.Y == 2)
			{
				g_sChar.m_cLocation.X = 3;
				g_sChar.m_cLocation.Y = 22;

				g_nChar.m_cLocation.X = 56;
				g_nChar.m_cLocation.Y = 2;
				partc = true;
			}
		}

		if (partc == true)
		{
			//Teleporter
			g_portal.m_cLocation.X = 15;
			g_portal.m_cLocation.Y = 19;

			g_portal1.m_cLocation.X = 45;
			g_portal1.m_cLocation.Y = 19;

			//Teleporter
			g_Console.writeToBuffer(g_portal.m_cLocation, (char)234);
			g_Console.writeToBuffer(g_portal1.m_cLocation, (char)234);

			if (g_sChar.m_cLocation.X == 15 &&
				g_sChar.m_cLocation.Y == 19 &&
				g_nChar.m_cLocation.X == 45 &&
				g_nChar.m_cLocation.Y == 19)
			{
				g_sChar.health = 3;

				g_dCountTime = 60;
				load = levelthree;
				restarthealth = true;
				splash = true;
				spawn();
				renderGame();
			}
		}

		if ((g_enemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y) ||
			(g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y) ||
			(g_enemy.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy.m_cLocation.Y == g_nChar.m_cLocation.Y) ||
			(g_enemy2.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy2.m_cLocation.Y == g_sChar.m_cLocation.Y))
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

		//if (g_nChar.m_cLocation.X == 49 &&
		//	g_nChar.m_cLocation.Y == 11 &&
		//	g_sChar.m_cLocation.X == 11 &&
		//	g_sChar.m_cLocation.Y == 11)
		//{
		//	g_sChar.m_cLocation.X = 11;
		//	g_sChar.m_cLocation.Y = 10;

		//	g_nChar.m_cLocation.X = 49;
		//	g_nChar.m_cLocation.Y = 10;
		//	g_sChar.health = 3;

		//	load = mainscreen;

		//}

		if (g_sChar.health < 1)
		{
			level = two;
			load = defeated;
			renderGame();
		}
	}
}
