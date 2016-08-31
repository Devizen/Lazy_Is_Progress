#include "health.h"
#include <string>

using namespace std;

//Done by Yoong Soon and Eugene.
void renderhealth(Console *handle,  int hp)
{
	string s = "Health: " + to_string(hp);

	COORD c;
	c.X = handle->getConsoleSize().X - 13;
	c.Y = handle->getConsoleSize().Y -23 ;
	
	handle->writeToBuffer(c, s, green);
	
	if (g_sChar.health == 2)
	{
		g_Console.writeToBuffer(c, s, yellow);
	}

	if (g_sChar.health == 1)
	{
		g_Console.writeToBuffer(c, s, red);
	}

}