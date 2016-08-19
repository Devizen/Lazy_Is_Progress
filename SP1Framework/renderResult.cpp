#include "renderResult.h"

//Done by Yoong Soon.
void renderResult()
{
	string line;
	ifstream myfile("Text/Result.txt");
	COORD c = g_Console.getConsoleSize();
	c.X = 33;
	c.Y = 1;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}
		myfile.close();
	}
	else
	{
		g_Console.writeToBuffer(c, "The file is not found.");
	}
}