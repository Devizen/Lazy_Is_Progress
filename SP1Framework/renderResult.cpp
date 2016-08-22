#include "renderResult.h"
#include <vector>

//Done by Yoong Soon.
void renderResult(bool *g_ResultIsDisplayed, double *g_ElapsedGameTime)
{
	double g_dCountTime = 10.0;

	int score_multiplier = 10;
	static vector <string> line1 ;
	string buffer;
	COORD c = g_Console.getConsoleSize();

	if (!*g_ResultIsDisplayed){

		ifstream myfile("Text/Result.txt");


		if (myfile.is_open())
		{
			while (getline(myfile, buffer))
			{
				line1.push_back(buffer);

			}
			myfile.close();

			//  save game score into a file 
			ofstream savefile("Text/SaveScore.txt", ios_base::app);
			if (savefile.is_open())
			{
					savefile << to_string((g_dCountTime - *g_ElapsedGameTime ) * score_multiplier +1).substr(0, 5);
					savefile << endl;
					savefile.close();
			}
			else
			{
				g_Console.writeToBuffer(c, "The save file is not found");
			}
		}
		else
		{
			g_Console.writeToBuffer(c, "The file is not found");
		}

		*g_ResultIsDisplayed = true;
	}

	c.X = 33;
	c.Y = 1;

	for (size_t i = 0; i < line1.size(); i++){
		c.Y++;
		g_Console.writeToBuffer(c, line1[i]);
	}

	c.X = 34;
	c.Y = 4;
	g_Console.writeToBuffer(c, "Score: ");
	c.Y++;
	g_Console.writeToBuffer(c, to_string((g_dCountTime -*g_ElapsedGameTime) * score_multiplier +1 ).substr(0, 2));

}