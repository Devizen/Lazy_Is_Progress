#include "menu.h"

//Done by Eugene.
void menu()
{
	string line;
	ifstream myfile("Text/menu.txt");
	COORD c = g_Console.getConsoleSize();
	c.X = 20;
	c.Y = 1;
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

	g_Console.writeToBuffer(g_menu.m_cLocation, '>');

	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

	if (g_abKeyPressed[K_UP] &&
		g_menu.m_cLocation.Y > 8 &&
		g_menu.m_cLocation.Y <= 12)
	{
		g_menu.m_cLocation.Y--;
		bSomethingHappened = true;
	}

	if (g_abKeyPressed[K_DOWN] &&
		g_menu.m_cLocation.Y < 12 &&
		g_menu.m_cLocation.Y >= 8)
	{
		g_menu.m_cLocation.Y++;
		bSomethingHappened = true;
	}

	if (g_menu.m_cLocation.Y == 8 && g_abKeyPressed[K_RETURN])
	{
		g_sChar.health = 3;
		g_dCountTime = 60;
		load = levelzeroa;
		g_eGameState = S_GAME;
	}

	if (g_menu.m_cLocation.Y == 9 && g_abKeyPressed[K_RETURN])
	{
		g_sChar.health = 3;
		g_eGameState = S_GAME;
	}

	if (g_menu.m_cLocation.Y == 10 && g_abKeyPressed[K_RETURN])
	{
		g_eGameState = S_INSTRUCTIONS;
	}

	if (g_menu.m_cLocation.Y == 11 && g_abKeyPressed[K_RETURN])
	{
		g_eGameState = S_SCOREBOARD;
	}
	if (g_menu.m_cLocation.Y == 12 && g_abKeyPressed[K_RETURN])
	{
		g_bQuitGame = true;
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}