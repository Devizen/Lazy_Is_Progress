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

	for (int i = 0; i <= y; i++)
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
			g_sChar.health = 3;
			load = levelzeroa;
			spawn();
			renderGame();
			break;

		case zerob:
			g_sChar.health = 3;
			load = levelzerob;
			spawn();
			renderGame();
			break;

		case one:
			g_sChar.health = 3;
			load = levelone;
			spawn();
			renderGame();
			break;
			
		case two:
			g_sChar.health = 3;
			load = leveltwo;
			spawn();
			renderGame();
			break;
		}
	}
}