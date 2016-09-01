#include "credits.h"

void credits()
{
	clearScreen();
	string line = " ";
	string name = "Text/credits.txt";
	loadlevel(name);

	COORD c;

	c.X = 39;
	c.Y = 3;

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
}