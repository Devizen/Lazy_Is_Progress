#include "movelevel5.h"

//Done by Eugene.
void movelevel5()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
	{
		return;
	}

	if (g_abKeyPressed[K_W])
	{
		if (g_sChar.m_cLocation.Y > 0 &&
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y--;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_A])
	{
		if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
		{
			g_sChar.m_cLocation.X--;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_S])
	{
		if (g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1 &&
			map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y++;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_D])
	{
		if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
		{
			g_sChar.m_cLocation.X++;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_UP])
	{
		if (g_nChar.m_cLocation.Y > 0 &&
			map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] != (char)219)
		{
			g_nChar.m_cLocation.Y--;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_LEFT])
	{
		if (g_nChar.m_cLocation.X > 0 &&
			map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != (char)219)
		{
			if (door1 == true &&
				map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X] && 
				map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != map[g_door5.m_cLocation.Y][g_door5.m_cLocation.X])
			{
				g_nChar.m_cLocation.X--;
				bSomethingHappened = true;
			}

			else if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] &&
				door1 == false)
			{
				g_nChar.m_cLocation.X--;
				bSomethingHappened = true;
			}

			else if (door4 == true &&
				map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != map[g_door5.m_cLocation.Y][g_door5.m_cLocation.X])
			{
				g_nChar.m_cLocation.X--;
				bSomethingHappened = true;
			}
			else if (door1 == true &&
				door2 == true &&
				door3 == true &&
				door4 == true &&
				door5 == true)
			{
				g_nChar.m_cLocation.X--;
				bSomethingHappened = true;
			}
		}
	}

	if (g_abKeyPressed[K_DOWN])
	{
		if (g_nChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1 &&
			map[g_nChar.m_cLocation.Y + 1][g_nChar.m_cLocation.X] != (char)219)
		{
			g_nChar.m_cLocation.Y++;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_RIGHT])
	{
		if (g_nChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
			map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != (char)219)
		{
			if (door2 == true &&
				map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
			{
				g_nChar.m_cLocation.X++;
				bSomethingHappened = true;
			}

			else if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] &&
				door2 == false)
			{
				g_nChar.m_cLocation.X++;
				bSomethingHappened = true;
			}

			else if (door2 == true &&
				door3 == true)
			{
				g_nChar.m_cLocation.X++;
				bSomethingHappened = true;
			}
		}
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}