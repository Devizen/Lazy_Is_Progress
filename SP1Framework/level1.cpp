#include "level1.h"

bool door1 = false;

//Done by Eugene.
void level1()
{
	/*bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
	{
		return;
	}*/

	string line = " ";
	string name = "Text/level1.txt";
	loadlevel(name);
	COORD c;

	c.X = 0;
	c.Y = 0;

	for (int i = 0; i <= y; i++)
	{
		line = map[i];
		g_Console.writeToBuffer(c, line);
		c.Y++;
	}

	WORD charColor = 0x0C;
	WORD charColor2 = 0x0A;

	//First Character
	g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

	//Second Character
	g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

	//Enemy
	g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
	g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

	//Door
	g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, charColor);

	//Lever
	g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, charColor);

	//Box
	g_Console.writeToBuffer(g_box1.m_cLocation, (char)254, charColor);

	//Release A.I
	g_Console.writeToBuffer(release_enemy.m_cLocation, (char)219, charColor);
	
	motiondetect();

	if (map[g_box1.m_cLocation.Y][g_box1.m_cLocation.X] == map[g_lever1.m_cLocation.Y][g_lever1.m_cLocation.X])
	{
		g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, charColor2);
		g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, charColor2);
		g_Console.writeToBuffer(release_enemy.m_cLocation, (char)219, charColor2);
		door1 = true;
	}
	else
	{
		door1 = false;
	}

	if ((g_enemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y) ||
		(g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y) ||
		g_abKeyPressed[K_R])
	{
		if (g_sChar.health > 0)
		{
			g_sChar.health -= 1;
			g_dCountTime = 1000;

			//First Character
			g_sChar.m_cLocation.X = 4;
			g_sChar.m_cLocation.Y = 8;

			//Second Character
			g_nChar.m_cLocation.X = 39;
			g_nChar.m_cLocation.Y = 19;

			//Enemy
			g_enemy.m_cLocation.X = 11;
			g_enemy.m_cLocation.Y = 1;

			g_enemy2.m_cLocation.X = 49;
			g_enemy2.m_cLocation.Y = 1;

			//Door
			g_door1.m_cLocation.X = 8;
			g_door1.m_cLocation.Y = 10;

			//Lever
			g_lever1.m_cLocation.X = 53;
			g_lever1.m_cLocation.Y = 8;

			//Box
			g_box1.m_cLocation.X = 54;
			g_box1.m_cLocation.Y = 21;
		}
		else
		{
			clearScreen();
			gameover(g_sChar);
		}
	}

	if (g_nChar.m_cLocation.X == 39 &&
		g_nChar.m_cLocation.Y == 22 &&
		g_sChar.m_cLocation.X == 23 &&
		g_sChar.m_cLocation.Y == 22)
	{
		g_sChar.m_cLocation.X = 11;
		g_sChar.m_cLocation.Y = 10;

		g_nChar.m_cLocation.X = 49;
		g_nChar.m_cLocation.Y = 10;
		g_sChar.health = 3;

		load = leveltwo;
	}
}