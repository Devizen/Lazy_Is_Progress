#include "instructions.h"

//Done by Eugene.
void instructions()
{
	string line;

	ifstream myfile("Text/Screen/instructions.txt");
	COORD c = g_Console.getConsoleSize();
	c.X = 10;
	c.Y = 0;
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
		g_Console.writeToBuffer(c, "The file is not found");
	}

	//Displaying Players' movement for both hearts icons.
	c.X = 26;
	c.Y = 9;
	g_Console.writeToBuffer(c, (char)3, red);
	c.X = 49;
	g_Console.writeToBuffer(c, (char)3, green);

	//Displaying Players' run for both hearts icons.
	c.X = 31;
	c.Y = 14;
	g_Console.writeToBuffer(c, (char)3, red);

	c.X = 54;
	g_Console.writeToBuffer(c, (char)3, green);

	//Displaying enemy icon.
	c.X = 29;
	c.Y = 16;
	g_Console.writeToBuffer(c, (char)1, green);

	//Displaying objective for both hearts icons.
	c.X = 36;
	c.Y = 20;
	g_Console.writeToBuffer(c, (char)3, red);
	c.Y = 21;
	g_Console.writeToBuffer(c, (char)3, green);

	//Displaying Text.
	c.X = 45;
	c.Y = 16;
	g_Console.writeToBuffer(c, "[R] Reset Level.");

	c.X = 45;
	c.Y = 21;
	g_Console.writeToBuffer(c, "[Backspace]");

	c.Y = 22;
	g_Console.writeToBuffer(c, "to Main Menu/Pause.");

	c.Y = 18;
	g_Console.writeToBuffer(c, "[Enter]");

	c.Y = 19;
	g_Console.writeToBuffer(c, "to Select.");


	if (g_abKeyPressed[K_BACK])
	{
		switch (load)
		{
		case levelzeroa:
			clearScreen();
			g_eGameState = S_MENU;
			load = levelzeroa;
			break;

		case levelzerob:
			clearScreen();
			g_eGameState = S_MENU;
			load = levelzerob;
			break;

		case levelone:
			clearScreen();
			g_eGameState = S_MENU;
			load = levelone;
			break;

		case leveltwo:
			clearScreen();
			g_eGameState = S_MENU;
			load = leveltwo;
			break;

		case levelfour:
			clearScreen();
			g_eGameState = S_MENU;
			load = levelfour;
			break;
		}
	}
}