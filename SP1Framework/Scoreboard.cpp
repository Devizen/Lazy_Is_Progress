#include "ScoreBoard.h"
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdlib.h> 
using namespace std;
extern Console g_Console;

void renderScoreBoard()
{
    vector <string> line;
	string buffer;
	WORD Scoreboardcolor = 0xB2;
	COORD A = g_Console.getConsoleSize();
	A.X = 33;      // coordinate for the word "HighScore: "
	A.Y = 1;


	g_Console.writeToBuffer(A, "HighScore: ");
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
	ifstream myfile("Text/SaveScore.txt"); //Output score into High ScoreBoard
	if (myfile.is_open())
	{
		while (getline(myfile, buffer))
		{
			line.push_back(buffer);
			sort(line.begin(), line.end(), greater<string>());

		}
		
		myfile.close();
	}

	else
	{
		g_Console.writeToBuffer(A, "The save file is not found");
	}

	for (size_t a = 0; a < line.size(); a++)
	{
		g_Console.writeToBuffer(A, line[a]);
		A.Y++;
	}


}