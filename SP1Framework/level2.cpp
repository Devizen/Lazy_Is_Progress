#include "level2.h"
#include "characters.h"
#include "game.h"
#include "health.h"
SGameChar enemy;

//Done by Eugene.
void level2()
{
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
			level = two;
			load = defeated;
			renderGame();
		}
	}
}
