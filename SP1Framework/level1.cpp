#include "level1.h"
#include "level2.h"
#include "ai.h"
#include "game.h"
#include "health.h"

//Done by Eugene.
void level1()
{
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

	COORD y;
	y.X = 15;
	y.Y = 15;


	WORD charColor = 0x0C;
	WORD charColor2 = 0x0A;
	if (g_sChar.m_bActive)
	{
		charColor = 0x0A;
	}
	g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

	// Draw the location of the character
	if (g_nChar.m_bActive)
	{
		charColor = 0x0C;
	}
	g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

	//Enemy
	g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
	g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

	//Door
	g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, charColor);

	//Lever
	g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, charColor);

	motiondetect();

	//if (g_abKeyPressed[K_D])
	//{
	//	if (g_sChar.m_cLocation.X + 1 != g_door1.m_cLocation.X &&
	//		g_sChar.m_cLocation.Y = g_door1.m_cLocation.Y)
	//	{
	//		g_sChar.m_cLocation.X++;
	//	}
	//}

	if ((g_enemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y) ||
		(g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y))
	{
		g_sChar.health -= 1;

		g_sChar.m_cLocation.X = 11;
		g_sChar.m_cLocation.Y = 10;

		g_nChar.m_cLocation.X = 49;
		g_nChar.m_cLocation.Y = 10;

		//Enemy
		g_enemy.m_cLocation.X = 11;
		g_enemy.m_cLocation.Y = 1;

		g_enemy2.m_cLocation.X = 49;
		g_enemy2.m_cLocation.Y = 1;
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

		load = leveltwo;

	}
}