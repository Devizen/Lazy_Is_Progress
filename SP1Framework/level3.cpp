#include "level3.h"
#include "characters.h"
#include "health.h"
#include "game.h"

//Done by Daniel.

//2 problems , Box cannot return and door not working
void level3()
{
	string line = " ";
	COORD c;

	if (splash == true)
	{
		string name = "Text/Screen/level3.txt";
		loadlevel(name);

		c.X = 11;
		c.Y = 7;

		clearScreen();
		for (unsigned int i = 0; i <= y; i++)
		{
			line = map[i];
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}

		if (g_dCountTime < 59 && story == true)
		{
			name = "Text/Story/level3.txt";
			loadlevel(name);

			c.X = 0;
			c.Y = 0;

			clearScreen();
			for (unsigned int i = 0; i <= y; i++)
			{
				line = map[i];
				g_Console.writeToBuffer(c, line);
				c.Y++;
			}

			if (g_dCountTime < 40)
			{
				splash = false;
				story = false;
				renderGame();
			}

			if (g_abKeyPressed[K_RETURN])
			{
				g_dCountTime = 39;
			}

			COORD d;
			d.X = 62;
			d.Y = 14;
			g_Console.writeToBuffer(d, "To Skip:", yellow);
			d.Y = 15;
			g_Console.writeToBuffer(d, "Press the");
			d.Y = 16;
			g_Console.writeToBuffer(d, "[Enter] button");
			d.Y = 17;
			g_Console.writeToBuffer(d, "to skip the story.");
		}

		if (g_dCountTime < 59 && story == false)
		{
			splash = false;
			renderGame();
		}
	}

	if (splash == false)
	{
		string name = "Text/Level/level3.txt";
		loadlevel(name);

		//COORD c;

		c.X = 0;
		c.Y = 0;

		for (unsigned int i = 0; i <= y; i++)
		{
			line = map[i];
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}

		COORD y;
		y.X = 15;
		y.Y = 15;
		//string line = " ";
		//string name = "Text/Level/level3.txt";
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

		COORD d;
		d.X = 63;
		d.Y = 15;
		g_Console.writeToBuffer(d, "Run Away From");
		d.Y = 16;
		g_Console.writeToBuffer(d, "The Bad Neighbour");
		d.Y = 17;
		g_Console.writeToBuffer(d, "Or You Will");
		d.Y = 18;
		g_Console.writeToBuffer(d, "Die");

		rendercharacters();
		motiondetect();


		if (map[boxfour.m_cLocation.Y][boxfour.m_cLocation.X] == map[g_lever1.m_cLocation.Y][g_lever1.m_cLocation.X])
		{
			g_Console.writeToBuffer(boxfour.m_cLocation, (char)219, green);
			g_Console.writeToBuffer(g_door4.m_cLocation, (char)219, green);

			door4 = true;
		}
		else
		{
			door4 = false;
		}

		if (boxreturn(boxfour) == true)
		{
			boxfour.m_cLocation.X = 52;
			boxfour.m_cLocation.Y = 23;
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
			level = three;
			load = defeated;
			renderGame();
			rendercharacters();
		}
	}
}
