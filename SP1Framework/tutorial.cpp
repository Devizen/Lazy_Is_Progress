#include "tutorial.h"

void tutorial()
{
	string line = " ";
	string name = "Text/level0_0.txt";
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

	COORD y;
	y.X = 15;
	y.Y = 15;

	rendercharacters();
	motiondetect();

	if ((g_enemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y) ||
		(g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y))
	{
		g_sChar.health -= 1;

		//First Character
		g_sChar.m_cLocation.X = 20;
		g_sChar.m_cLocation.Y = 23;

		//Second Character
		g_nChar.m_cLocation.X = 40;
		g_nChar.m_cLocation.Y = 23;

		//Enemy
		g_enemy.m_cLocation.X = 22;
		g_enemy.m_cLocation.Y = 23;

		g_enemy2.m_cLocation.X = 38;
		g_enemy2.m_cLocation.Y = 23;

		g_dCountTime = 60;
	}

	if (
		g_sChar.m_cLocation.X == 29 &&
		g_sChar.m_cLocation.Y == 0 &&
		g_nChar.m_cLocation.X == 31 &&
		g_nChar.m_cLocation.Y == 0)
	{
		clearScreen();
		load = levelone;
		spawn();

	}

	if (g_sChar.health < 1)
	{
		level = two;
		load = defeated;
		renderGame();
	}
}