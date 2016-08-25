#include "SpeedUpPlatform.h"


void SpeedUpPlatform()
{

	
		if (g_abKeyPressed[K_W] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
			{
				g_sChar.m_cLocation.Y -= 1;

			}
		}
		else if (g_abKeyPressed[K_W] && g_abKeyPressed[K_RSHIFT] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{
			while (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
			{
				g_sChar.m_cLocation.Y -= 1;

			}
		}


		if (g_abKeyPressed[K_A] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
			{
				g_sChar.m_cLocation.X -= 1;

			}
		}
		else if (g_abKeyPressed[K_A] && g_abKeyPressed[K_RSHIFT] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
			{
				g_sChar.m_cLocation.X -= 1;

			}

		}


		if (g_abKeyPressed[K_S] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
			{
				g_sChar.m_cLocation.Y += 1;

			}
		}

		else if (g_abKeyPressed[K_S] && g_abKeyPressed[K_RSHIFT] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
			{
				g_sChar.m_cLocation.Y += 1;

			}

		}

		if (g_abKeyPressed[K_D] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
			{
				g_sChar.m_cLocation.X += 1;

			}
		}
		else if (g_abKeyPressed[K_D] && g_abKeyPressed[K_RSHIFT] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
			{
				g_sChar.m_cLocation.X += 1;

			}
		}



		if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
			{
				g_sChar.m_cLocation.Y -= 1;

			}
		}
		else if (g_abKeyPressed[K_UP] && g_abKeyPressed[K_LSHIFT] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
			{
				g_sChar.m_cLocation.Y -= 1;

			}
		}


		if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
			{
				g_sChar.m_cLocation.X -= 1;

			}
		}
		else	if (g_abKeyPressed[K_LEFT] && g_abKeyPressed[K_LSHIFT] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
			{
				g_sChar.m_cLocation.X -= 1;

			}
		}

		if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
			{
				g_sChar.m_cLocation.Y += 1;

			}
		}
		else if (g_abKeyPressed[K_DOWN] && g_abKeyPressed[K_LSHIFT] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
			{
				g_sChar.m_cLocation.Y += 1;

			}
		}

		if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
			{
				g_sChar.m_cLocation.X += 1;

			}
		}
		else 	if (g_abKeyPressed[K_RIGHT] && g_abKeyPressed[K_LSHIFT] && g_sChar.m_cLocation.X == g_platform.m_cLocation.X && g_sChar.m_cLocation.Y == g_platform.m_cLocation.Y)
		{

			while (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
			{
				g_sChar.m_cLocation.X += 1;

			}
		}

	
	
}