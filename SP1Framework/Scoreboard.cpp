#include "ScoreBoard.h"
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdlib.h> 
#include "game.h"
using namespace std;
extern Console g_Console;
extern LEVELS load;
extern EGAMESTATES g_eGameState;
extern bool g_abKeyPressed[K_COUNT];

//Done by Yoong Soon.
void renderScoreBoard()
{
	vector <int> line;
	string buffer;
	string buffer1;
	vector <int> line2;
	WORD color = 0x5E;
	COORD A = g_Console.getConsoleSize();


		if (g_abKeyPressed[K_NUM1])
		{
			load = scoreboard1;
		}
	
		switch (load)
		{
		case scoreboard1:
		{
			A.X = 33;      // coordinate for the word "HighScore: "
			A.Y = 1;


			g_Console.writeToBuffer(A, "HighScore(LEVEL 1): ", color);
			A.Y = 3;      // coordinate for the number 1 to 10
			A.X = 30;

			for (int i = 1; i <= 10; i++)
			{
				g_Console.writeToBuffer(A, to_string(i)); // output number 1 to 10 to High ScoreBoard
				A.Y += 1;
			}
			A.Y = 3;   //coordinate for the "."
			for (int k = 1; k <= 10; k++)    //output the "." behind all the numbers
			{
				if (k != 10)
				{
					A.X = 31;
					g_Console.writeToBuffer(A, ".");
					A.Y += 1;
				}
				else
				{
					A.X = 32;
					g_Console.writeToBuffer(A, ".");
				}

			}

			A.X = 34;//coordinate for Ouput score
			A.Y = 3;
			ifstream myfile("Text/Scoreboard/Level1.txt"); //Output score into High ScoreBoard
			if (myfile.is_open())
			{
				while (getline(myfile, buffer))
				{

					line.push_back(stoi(buffer));
					sort(line.begin(), line.end(), greater<int>());

				}

				myfile.close();
			}

			else
			{
				g_Console.writeToBuffer(A, "The save file is not found");
			}

			for (size_t a = 0; a < line.size(); a++)
			{
				if (a < 10)
				{
					g_Console.writeToBuffer(A, to_string(line[a]));
					A.Y++;
				}
			}

		}
		}
	
		if (g_abKeyPressed[K_NUM2])
		{
			load = scoreboard2;
		}
		
		switch (load)
		{
		case scoreboard2:
		{
			A.X = 33;      // coordinate for the word "HighScore: "
			A.Y = 1;


			g_Console.writeToBuffer(A, "HighScore(LEVEL 2): ", color);
			A.Y = 3;      // coordinate for the number 1 to 10
			A.X = 30;

			for (int i = 1; i <= 10; i++)
			{
				g_Console.writeToBuffer(A, to_string(i)); // output number 1 to 10 to High ScoreBoard
				A.Y += 1;
			}
			A.Y = 3;   //coordinate for the "."
			for (int k = 1; k <= 10; k++)    //output the "." behind all the numbers
			{
				if (k != 10)
				{
					A.X = 31;
					g_Console.writeToBuffer(A, ".");
					A.Y += 1;
				}
				else
				{
					A.X = 32;
					g_Console.writeToBuffer(A, ".");
				}

			}

			A.X = 34;//coordinate for Ouput score
			A.Y = 3;
			ifstream myfile1("Text/Scoreboard/Level2.txt"); //Output score into High ScoreBoard
			if (myfile1.is_open())
			{
				while (getline(myfile1, buffer1))
				{

					line2.push_back(stoi(buffer1));
					sort(line2.begin(), line2.end(), greater<int>());

				}

				myfile1.close();
			}

			else
			{
				g_Console.writeToBuffer(A, "The save file is not found");
			}

			for (size_t a = 0; a < line2.size(); a++)
			{
				if (a < 10)
				{
					g_Console.writeToBuffer(A, to_string(line2[a]));
					A.Y++;
				}
			}
		}

		}


		if (g_abKeyPressed[K_BACK])
		{
			g_eGameState = S_MENU;
		}


}