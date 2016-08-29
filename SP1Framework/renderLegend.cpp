#include "renderLegend.h"
#include <string>
using namespace std;

void renderLegend()
{
	WORD color = 0X4D;
	WORD color1 = 0x3C;
	WORD color2 = 0x2B;
	WORD red = 0x0C;
	WORD charColor2 = 0x0A;
	WORD charColor3 = 0x2B;
	WORD yellow = 0x5E;
	WORD purple = 0x780F;

	COORD c = g_Console.getConsoleSize();
	string healthpowerup = "Health Up";
	string legends = "LEGENDS:";
	string timepowerup = "Time Boost";
	string speedpad = "Speed pad";
	string teleporter = "Teleporter";
	string box = "Box";
	string platform = "Platform";

	switch (load)
	{
	case levelzerob:
		//Coordinates for LEGENDS:
		c.X = 66;
		c.Y = 4;
		g_Console.writeToBuffer(c, legends, color1);  //Display "LEGENDS:".

		//Coordinates for Box icon.
		c.X = 64;
		c.Y = 7;
		g_Console.writeToBuffer(c, (char)254, red); //Display the Box icon.

		//Coordinates for "Box".
		c.X = 66;
		c.Y = 7;
		g_Console.writeToBuffer(c, box);  //Display "Box".

		//Coordinates for Platform icon.
		c.X = 64;
		c.Y = 9;
		g_Console.writeToBuffer(c, (char)219, yellow); //Display the Platform icon.

		c.X = 66;
		c.Y = 9;
		g_Console.writeToBuffer(c, platform);  //Display "Platform".


		break;

	case levelone:
		c.X = 66;
		c.Y = 4;
		g_Console.writeToBuffer(c, legends, color1);  //output the word "LEGENDS:"

		c.X = 66;
		c.Y = 7;
		g_Console.writeToBuffer(c, healthpowerup);  //output the word" Health PowerUp:";

		c.X = 66;
		c.Y = 9;
		g_Console.writeToBuffer(c, timepowerup); //output the word "time boost";

		c.X = 66;
		c.Y = 11;
		g_Console.writeToBuffer(c, platform); //output the word "platform ";


		g_Console.writeToBuffer(c, teleporter); //Output the word Teleporter.

		c.X = 64;
		c.Y = 7;

		g_Console.writeToBuffer(c, (char)206, color); //output the health powerup icon

		c.X = 64;
		c.Y = 9;
		g_Console.writeToBuffer(c, (char)64, color); // output the time boost icon

		c.X = 64;
		c.Y = 11;
		g_Console.writeToBuffer(c, (char)254, color2); //output the speed pad icon
		break;
	}

}