#include "level2.h"
#include "ai.h"
#include "game.h"
#include "health.h"

//Done by Eugene.
void level2()
{
	string line = " ";
	string name = "Text/level2.txt";
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

		g_sChar.m_cLocation.X = 4;
		g_sChar.m_cLocation.Y = 19;

		g_nChar.m_cLocation.X = 39;
		g_nChar.m_cLocation.Y = 19;

		//Enemy
		g_enemy.m_cLocation.X = 11;
		g_enemy.m_cLocation.Y = 1;

		g_enemy2.m_cLocation.X = 49;
		g_enemy2.m_cLocation.Y = 1;

		g_dCountTime = 60;
	}

	if (g_nChar.m_cLocation.X == 49 &&
		g_nChar.m_cLocation.Y == 11 &&
		g_sChar.m_cLocation.X == 11 &&
		g_sChar.m_cLocation.Y == 11)
	{
		g_sChar.m_cLocation.X = 11;
		g_sChar.m_cLocation.Y = 10;

		g_nChar.m_cLocation.X = 49;
		g_nChar.m_cLocation.Y = 10;
		g_sChar.health = 3;

		load = mainscreen;

	}

	if (g_sChar.health < 1)
	{
		level = two;
		load = defeated;
		renderGame();
	}
}