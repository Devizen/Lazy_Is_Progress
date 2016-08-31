#include  "level5.h"
#include "characters.h"
#include "game.h"
#include "health.h"

//Done by Yoong Soon.
void level5()
{
	WORD charColor = 0x0C;
	WORD charColor2 = 0x0A;
	WORD yellow = 0xFFE0;

	string line = " ";
	COORD c;

	if (splash == true)
	{
		string name = "Text/Screen/level5.txt";
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
			name = "Text/Story/level5.txt";
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
		string name = "Text/Level/level5.txt";
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

		if (g_sChar.health < 1)
		{
			level = five;
			load = defeated;
			renderGame();
			rendercharacters();
		}
	}

}

