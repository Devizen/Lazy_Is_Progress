#include "renderLegend.h"
#include <string>
using namespace std;

void renderLegend()
{
	WORD color = 0X4D;
	WORD color1 = 0x3C;
	COORD c = g_Console.getConsoleSize();
	string healthpowerup = "Health Up";
	string legends = "LEGENDS:";
	string timepowerup = "Time Boost";

	c.X = 66;
	c.Y = 4;
	g_Console.writeToBuffer(c, legends,color1);  //output the word "LEGENDS:"

	c.X = 66;
	c.Y = 7;
	g_Console.writeToBuffer(c,healthpowerup);  //output the word" Health PowerUp:";

	c.X = 66;
	c.Y = 9;
	g_Console.writeToBuffer(c, timepowerup); //output the word "time boost: ";

	c.X = 64;
	c.Y = 9;
	g_Console.writeToBuffer(c, (char)64, color); // output the time boost icon


	c.X = 64;
	c.Y = 7;

	g_Console.writeToBuffer(c, (char)206  , color); //output the health powerup icon
}