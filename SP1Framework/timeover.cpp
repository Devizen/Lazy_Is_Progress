#include "timeover.h"

void timeover()
{
	COORD c;

	WORD charColor = 0x0C;
	WORD charColor2 = 0x0A;
	WORD charColor3 = 0x2B;
	WORD yellow = 0x5E;
	WORD purple = 0x780F;

	// displays the framerate
	std::ostringstream ss;

	if (g_dCountTime <= 30 && g_dCountTime >= 10)
	{
		ss.str("");
		ss << g_dCountTime << "secs";
		c.X = g_Console.getConsoleSize().X - 10;
		c.Y = g_Console.getConsoleSize().Y - 23;
		g_Console.writeToBuffer(c, ss.str(), yellow);
	}

	if (g_dCountTime <= 10)
	{
		ss.str("");
		ss << g_dCountTime << "secs";
		c.X = g_Console.getConsoleSize().X - 10;
		c.Y = g_Console.getConsoleSize().Y - 23;
		g_Console.writeToBuffer(c, ss.str(), charColor);
	}

	//string line = " ";
	//string name = "Text/Screen/timeover.txt";
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

}