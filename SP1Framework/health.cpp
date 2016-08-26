#include "health.h"
#include <string>

using namespace std;

//Done by Yoong Soon and Eugene.
void renderhealth(Console *handle,  int hp)
{
	WORD healthColor = 0xA1;
	WORD red = 0x0C;
	WORD yellow = 0x5E;
	string s = "Health: " + to_string(hp);

	COORD c;
	c.X = handle->getConsoleSize().X - 12;
	c.Y = handle->getConsoleSize().Y -1 ;
	
	handle->writeToBuffer(c, s, healthColor);
	
	if (g_sChar.health == 2)
	{
		g_Console.writeToBuffer(c, s, yellow);
	}

	if (g_sChar.health == 1)
	{
		g_Console.writeToBuffer(c, s, red);
	}

}