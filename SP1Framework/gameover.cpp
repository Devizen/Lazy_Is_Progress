#include "gameover.h"

void gameover(struct SGameChar character)
{
	if (character.health <= 0)
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
	}

	if (g_abKeyPressed[K_BACK])
	{
		clearScreen();
		g_eGameState = S_MENU;
		load = mainscreen;
	}
}