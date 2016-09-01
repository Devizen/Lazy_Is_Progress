#include "gameover.h"

//Done by Eugene.
void gameover()
{
	clearScreen();
	string line = " ";
	string name = "Text/Result.txt";
	loadlevel(name);

	COORD c;

	c.X = 13;
	c.Y = 5;

	for (unsigned int i = 0; i <= y; i++)
	{
		line = map[i];
		g_Console.writeToBuffer(c, line);
		c.Y++;
	}

	if (g_abKeyPressed[K_BACK])
	{
		g_eGameState = S_MENU;
		load = levelzeroa; 
		spawn();
	}

	if (g_abKeyPressed[K_ESCAPE])
	{
		g_bQuitGame = true;
	}

	if (g_abKeyPressed[K_SPACE])
	{
		switch (level)
		{
		case zeroa:
			splash = true;
			g_sChar.health = 3;
			load = levelzeroa;
			spawn();
			renderGame();
			break;

		case zerob:
			splash = true;
			g_sChar.health = 3;
			load = levelzerob;
			spawn();
			renderGame();
			break;

		case one:
			splash = true;
			g_sChar.health = 3;
			load = levelone;
			spawn();
			renderGame();
			break;
			
		case two:
			splash = true;
			g_sChar.health = 3;
			load = leveltwo;
			spawn();
			renderGame();
			break;

		case three:
			splash = true;
			g_sChar.health = 3;
			load = levelthree;
			spawn();
			renderGame();
			break;

		case four:
			splash = true;
			g_sChar.health = 3;
			load = levelfour;
			spawn();
			renderGame();
			break;

		case five:
			splash = true;
			door1 = false;
			door2 = false;
			door3 = false;
			door4 = false;
			door5 = false;
			g_sChar.health = 3;
			load = levelfive;
			spawn();
			renderGame();
			break;

		case fiveb:
			splash = true;
			g_sChar.health = 3;
			load = levelfiveb;
			spawn();
			renderGame();
			break;
		}
	}
}