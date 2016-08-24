#include "loadlevel.h"

//Done by Eugene.
void loadlevel(string name)
{
	//Coordinates for printing file cannot be file.
	COORD c;
	c.X = 40;
	c.Y = 12;

	string line;

	unsigned int increase = 0;

	//Reset the map array.
	memset(map, '\0', sizeof(map[0][0]) * 25 * 80);

	ifstream myfile(name);

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			for (unsigned int i = 0; i < line.length(); i++)
			{
				map[increase][i] = line[i];
				if (map[increase][i] == '+')
				{
					map[increase][i] = (char)219;
				}
			}
			increase++;
		}
	}
	else
	{
		g_Console.writeToBuffer(c, "The file is not found");
	}
}