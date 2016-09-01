#include "renderLegend.h"
#include <string>
using namespace std;

void renderLegend()
{
	COORD c = g_Console.getConsoleSize();
	string healthpowerup = "Health Up";
	string legends = "LEGENDS:";
	string timepowerup = "Time Boost";
	string speedpad = "Speed pad";
	string teleporter = "Teleporter";
	string box = "Box";
	string platform = "Platform";
	string pitfall = "Pitfall";

	switch (load)
	{
	case levelzeroa:
		//Coordinates for LEGENDS:
		c.X = 66;
		c.Y = 4;
		g_Console.writeToBuffer(c, legends, red);  //Display "LEGENDS:".

		//Coordinates for "Level".
		c.X = 66;
		c.Y = 24;
		g_Console.writeToBuffer(c, "Tutorial A");  //Display "Level".
		break;

	case levelzerob:
		//Coordinates for LEGENDS:
		c.X = 66;
		c.Y = 4;
		g_Console.writeToBuffer(c, legends, red);  //Display "LEGENDS:".

		//Coordinates for Box icon.
		c.X = 64;
		c.Y = 5;
		g_Console.writeToBuffer(c, (char)254, red); //Display the Box icon.

		//Coordinates for "Box".
		c.X = 66;
		c.Y = 5;
		g_Console.writeToBuffer(c, box);  //Display "Box".

		//Coordinates for Platform icon.
		c.X = 64;
		c.Y = 6;
		g_Console.writeToBuffer(c, (char)219, yellow); //Display the Platform icon.

		c.X = 66;
		c.Y = 6;
		g_Console.writeToBuffer(c, platform);  //Display "Platform".

		c.X = 66;
		c.Y = 24;
		g_Console.writeToBuffer(c, "Tutorial B");  //Display "Level".
		break;

	case levelone:
		//Coordinates for LEGENDS:
		c.X = 66;
		c.Y = 4;
		g_Console.writeToBuffer(c, legends, red);  //Display "LEGENDS:".

		//Coordinates for Box icon.
		c.X = 64;
		c.Y = 5;
		g_Console.writeToBuffer(c, (char)254, red); //Display the Box icon.

		//Coordinates for "Box".
		c.X = 66;
		c.Y = 5;
		g_Console.writeToBuffer(c, box);  //Display "Box".

		//Coordinates for Platform icon.
		c.X = 64;
		c.Y = 6;
		g_Console.writeToBuffer(c, (char)219, yellow); //Display the Platform icon.

		c.X = 66;
		c.Y = 6;
		g_Console.writeToBuffer(c, platform);  //Display "Platform".

		c.X = 66;
		c.Y = 7;
		g_Console.writeToBuffer(c, healthpowerup);  //output the word" Health PowerUp:";

		c.X = 66;
		c.Y = 8;
		g_Console.writeToBuffer(c, timepowerup); //output the word "time boost";

		c.X = 66;
		c.Y = 9;
		g_Console.writeToBuffer(c, platform); //output the word "platform ";


		g_Console.writeToBuffer(c, teleporter); //Output the word Teleporter.

		c.X = 64;
		c.Y = 7;

		g_Console.writeToBuffer(c, (char)206, purple); //output the health powerup icon

		c.X = 64;
		c.Y = 8;
		g_Console.writeToBuffer(c, (char)64, purple); // output the time boost icon

		c.X = 64;
		c.Y = 9;
		g_Console.writeToBuffer(c, (char)234, lightblue); //output the teleporter icon

		c.X = 66;
		c.Y = 24;
		g_Console.writeToBuffer(c, "Level One");  //Display "Level".
		break;

	case leveltwo:
		//Coordinates for LEGENDS:
		c.X = 66;
		c.Y = 4;
		g_Console.writeToBuffer(c, legends, red);  //Display "LEGENDS:".

		c.X = 66;
		c.Y = 5;
		g_Console.writeToBuffer(c, teleporter); //Output the word Teleporter.

		c.X = 64;
		c.Y = 5;
		g_Console.writeToBuffer(c, (char)234, lightblue); //output the teleporter icon

		c.X = 66;
		c.Y = 24;
		g_Console.writeToBuffer(c, "Level Two");  //Display "Level"
		break;

	case levelthree:
		//Coordinates for LEGENDS:
		c.X = 66;
		c.Y = 4;
		g_Console.writeToBuffer(c, legends, red);  //Display "LEGENDS:".

													  //Coordinates for Box icon.
		c.X = 64;
		c.Y = 5;
		g_Console.writeToBuffer(c, (char)254, red); //Display the Box icon.

													//Coordinates for "Box".
		c.X = 66;
		c.Y = 5;
		g_Console.writeToBuffer(c, box);  //Display "Box".

		c.X = 66;
		c.Y = 6;
		g_Console.writeToBuffer(c, platform); //output the word "platform ";

		//Coordinates for Platform icon.
		c.X = 64;
		c.Y = 6;
		g_Console.writeToBuffer(c, (char)219, yellow); //Display the Platform icon.

		c.X = 66;
		c.Y = 24;
		g_Console.writeToBuffer(c, "Level Three");  //Display "Level"
		break;

	case levelfour:
		//Coordinates for LEGENDS:
		c.X = 66;
		c.Y = 4;
		g_Console.writeToBuffer(c, legends, red);  //Display "LEGENDS:".

													  //Coordinates for Box icon.
		c.X = 64;
		c.Y = 5;
		g_Console.writeToBuffer(c, (char)254, red); //Display the Box icon.

													//Coordinates for "Box".
		c.X = 66;
		c.Y = 5;
		g_Console.writeToBuffer(c, box);  //Display "Box".

										  //Coordinates for Platform icon.
		c.X = 64;
		c.Y = 6;
		g_Console.writeToBuffer(c, (char)219, yellow); //Display the Platform icon.

		c.X = 66;
		c.Y = 6;
		g_Console.writeToBuffer(c, platform);  //Display "Platform".

		c.X = 66;
		c.Y = 7;
		g_Console.writeToBuffer(c, timepowerup); //output the word "time boost";

		c.X = 66;
		c.Y = 8;
		g_Console.writeToBuffer(c, platform); //output the word "platform ";


		g_Console.writeToBuffer(c, teleporter); //Output the word Teleporter.

		c.X = 64;
		c.Y = 7;
		g_Console.writeToBuffer(c, (char)64, purple); // output the time boost icon

		c.X = 64;
		c.Y = 8;
		g_Console.writeToBuffer(c, (char)234, lightblue); //output the teleporter icon

		c.X = 66;
		c.Y = 24;
		g_Console.writeToBuffer(c, "Level Four");  //Display "Level"
		break;

	case levelfive:
		//Coordinates for LEGENDS:
		c.X = 66;
		c.Y = 4;
		g_Console.writeToBuffer(c, legends, red);  //Display "LEGENDS:".

		c.X = 66;
		c.Y = 5;
		g_Console.writeToBuffer(c, timepowerup); //output the word "time boost";

		c.X = 64;
		c.Y = 5;
		g_Console.writeToBuffer(c, (char)64, purple); // output the time boost icon

		c.X = 66;
		c.Y = 24;
		g_Console.writeToBuffer(c, "Grand Finale");  //Display "Level"
		break;

	case levelfiveb:
		//Coordinates for LEGENDS:
		c.X = 66;
		c.Y = 4;
		g_Console.writeToBuffer(c, legends, red);  //Display "LEGENDS:".

		c.X = 66;
		c.Y = 6;
		g_Console.writeToBuffer(c, pitfall); //output the word "Pitfall";

		c.X = 64;
		c.Y = 6;
		g_Console.writeToBuffer(c, (char)177, darkblue); //Output the Pitfall icon.

		c.X = 66;
		c.Y = 5;
		g_Console.writeToBuffer(c, teleporter); //Output the word Teleporter.

		c.X = 64;
		c.Y = 5;
		g_Console.writeToBuffer(c, (char)234, lightblue); //output the teleporter icon

		c.X = 66;
		c.Y = 24;
		g_Console.writeToBuffer(c, "Grand Finale");  //Display "Level"
		break;
	}

}