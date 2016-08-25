#include "renderResult.h"
#include <vector>
#include <fstream>


//Done by Yoong Soon.
void renderResult(bool *g_ResultIsDisplayed, double *g_ElapsedGameTime)
{
	double g_dCountTime = 10.0;
	int score_multiplier = 10;
	static vector <string> line1 ;
	string buffer;
	COORD c = g_Console.getConsoleSize();


	switch (load)
	{
	case levelone:
		if (!*g_ResultIsDisplayed){

			ifstream myfile("Text/Scoreboard/Result.txt");

			//if (!*g_ResultIsDisplayed){

			//	ifstream myfile("Text/Result.txt");


			//if (myfile.is_open())
			//{
			//	while (getline(myfile, buffer))
			//	{
			//		line1.push_back(buffer);


			if (myfile.is_open())
			{
				while (getline(myfile, buffer))
				{
					line1.push_back(buffer);

				}
				myfile.close();

				//  save game score into a file 
				ofstream savefile("Text/Scoreboard/level1.txt", ios_base::app);
				if (savefile.is_open())
				{
					savefile << to_string((g_dCountTime - *g_ElapsedGameTime) * score_multiplier + 1).substr(0, 5);
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
		break;

	case leveltwo:
		if (!*g_ResultIsDisplayed){

			ifstream myfile("Text/Scoreboard/Result.txt");


			if (myfile.is_open())
			{
				while (getline(myfile, buffer))
				{
					line1.push_back(buffer);

				}
				myfile.close();

				//  save game score into a file 
				ofstream savefile("Text/Scoreboard/level2.txt", ios_base::app);
				if (savefile.is_open())
				{
					savefile << to_string((g_dCountTime - *g_ElapsedGameTime) * score_multiplier + 1).substr(0, 5);
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
		break;

	}
	//Done by Eugene.
	//Options to select.
	if (g_abKeyPressed[K_BACK])
	{
		g_eGameState = S_MENU;
		load = levelzeroa;
		spawn();
	}

	if (g_abKeyPressed[K_ESCAPE])
	{
		g_bQuitGame = true;
	}

	if (g_abKeyPressed[K_SPACE])
	{
		switch (level)
		{
		case zeroa:
			g_sChar.health = 3;
			load = levelzeroa;
			spawn();
			renderGame();
			break;

		case zerob:
			g_sChar.health = 3;
			load = levelzerob;
			spawn();
			renderGame();
			break;

		case one:
			g_sChar.health = 3;
			load = levelone;
			spawn();
			renderGame();
			break;

		case two:
			g_sChar.health = 3;
			load = leveltwo;
			spawn();
			renderGame();
			break;
		}
	}
			
}