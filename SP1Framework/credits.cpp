#include "credits.h"

void credits()
{
	clearScreen();
	string line = " ";
	string name = "Text/credits.txt";
	loadlevel(name);

	COORD c;

	c.X = 29;
	c.Y = 2;

	for (unsigned int i = 0; i <= y; i++)
	{
		line = map[i];
		g_Console.writeToBuffer(c, line);
		c.Y++;
	}

	c.X = 3;
	c.Y = 3;
	line = "Thank you for playing!";
	g_Console.writeToBuffer(c, line, yellow);

	c.Y = 4;
	line = "You have";
	g_Console.writeToBuffer(c, line);
	c.X = 12;
	line = "DONE WELL!";
	g_Console.writeToBuffer(c, line, yellow);


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