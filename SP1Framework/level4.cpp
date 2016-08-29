#include  "level4.h"
#include "characters.h"
#include "game.h"
#include "health.h"

void level4()
{
	string line = " ";
	string name = "Text/Level/level4.txt";
	loadlevel(name);
	COORD c;


	c.X = 0;
	c.Y = 0;

	for (int i = 0; i <= y; i++)
	{
		line = map[i];
		g_Console.writeToBuffer(c, line);
		c.Y++;
	}

	rendercharacters();

}

