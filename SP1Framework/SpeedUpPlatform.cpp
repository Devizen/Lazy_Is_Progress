#include "SpeedUpPlatform.h"

//Done by Yoong Soon and Eugene.
void SpeedUpPlatform()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
	{
		return;
	}

	if (g_abKeyPressed[K_W] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y -= 1;
			bSomethingHappened = true;

		}
	}

	else if (g_abKeyPressed[K_W] && 
		g_abKeyPressed[K_RSHIFT] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{
		while (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y -= 1;
			bSomethingHappened = true;

		}
	}

	if (g_abKeyPressed[K_A] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
		{
			g_sChar.m_cLocation.X -= 1;
			bSomethingHappened = true;

		}
	}

	else if (g_abKeyPressed[K_A] && 
		g_abKeyPressed[K_RSHIFT] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
		{
			g_sChar.m_cLocation.X -= 1;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_S] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y += 1;
			bSomethingHappened = true;
		}
	}

	else if (g_abKeyPressed[K_S] && 
		g_abKeyPressed[K_RSHIFT] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y += 1;
			bSomethingHappened = true;
		}

	}

	if (g_abKeyPressed[K_D] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
		{
			g_sChar.m_cLocation.X += 1;
			bSomethingHappened = true;
		}
	}
	else if (g_abKeyPressed[K_D] && 
		g_abKeyPressed[K_RSHIFT] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
		{
			g_sChar.m_cLocation.X += 1;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_UP] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y -= 1;
			bSomethingHappened = true;
		}
	}

	else if (g_abKeyPressed[K_UP] && 
		g_abKeyPressed[K_LSHIFT] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y -= 1;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_LEFT] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
		{
			g_sChar.m_cLocation.X -= 1;
			bSomethingHappened = true;
		}
	}
	else if (g_abKeyPressed[K_LEFT] && 
		g_abKeyPressed[K_LSHIFT] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
		{
			g_sChar.m_cLocation.X -= 1;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_DOWN] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y += 1;
			bSomethingHappened = true;
		}
	}
	else if (g_abKeyPressed[K_DOWN] && 
		g_abKeyPressed[K_LSHIFT] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y += 1;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_RIGHT] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
		{
			g_sChar.m_cLocation.X += 1;
			bSomethingHappened = true;
		}
	}
	else if (g_abKeyPressed[K_RIGHT] && 
		g_abKeyPressed[K_LSHIFT] && 
		g_sChar.m_cLocation.X == g_platform.m_cLocation.X && 
		g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
	{

		while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
		{
			g_sChar.m_cLocation.X += 1;
			bSomethingHappened = true;
		}
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}