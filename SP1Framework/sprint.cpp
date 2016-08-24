#include "sprint.h"

//Done by Eugene.
void sprint()
{
	bool boost = false;
	if (g_dBounceTime > g_dElapsedTime)
	{
		return;
	}

	switch (load)
	{
	case levelone:

		if (g_abKeyPressed[K_RSHIFT] && g_abKeyPressed[K_W] &&
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y--;
			boost = true;
		}

		if (g_abKeyPressed[K_RSHIFT] && g_abKeyPressed[K_A] &&
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
		{
			if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
				map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219 &&
				map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] !=
				map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X])
			{
				g_sChar.m_cLocation.X--;

				boost = true;
			}
		}

		if (g_abKeyPressed[K_RSHIFT] && g_abKeyPressed[K_S] &&
			map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y++;
			boost = true;
		}

		if (g_abKeyPressed[K_RSHIFT] && g_abKeyPressed[K_D] &&
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
		{
			if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
				map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219 &&
				map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] !=
				map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X])
			{
				g_sChar.m_cLocation.X++;
				boost = true;
			}
		}

		if (g_abKeyPressed[K_LSHIFT] && g_abKeyPressed[K_UP] &&
			map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] != (char)219)
		{
			if (g_nChar.m_cLocation.Y - 1 == g_box1.m_cLocation.Y &&
				g_nChar.m_cLocation.X == g_box1.m_cLocation.X)
			{
				g_box1.m_cLocation.Y--;
				boost = true;
			}

			if (door1 == false &&
				map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] !=
				map[release_enemy.m_cLocation.Y][release_enemy.m_cLocation.X] &&
				map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] !=
				map[release_enemy1.m_cLocation.Y][release_enemy1.m_cLocation.X] &&
				map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] !=
				map[release_enemy2.m_cLocation.Y][release_enemy2.m_cLocation.X] &&
				map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] !=
				map[release_enemy3.m_cLocation.Y][release_enemy3.m_cLocation.X] &&
				map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] !=
				map[release_enemy4.m_cLocation.Y][release_enemy4.m_cLocation.X] &&
				map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] !=
				map[release_enemy5.m_cLocation.Y][release_enemy5.m_cLocation.X] &&
				map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] !=
				map[release_enemy6.m_cLocation.Y][release_enemy6.m_cLocation.X] &&
				map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] !=
				map[release_enemy7.m_cLocation.Y][release_enemy7.m_cLocation.X] &&
				map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] !=
				map[release_enemy8.m_cLocation.Y][release_enemy8.m_cLocation.X])
			{
				g_nChar.m_cLocation.Y--;
				boost = true;
			}

			if (door1 == true)
			{
				g_nChar.m_cLocation.Y--;
				boost = true;
			}
		}

		if (g_abKeyPressed[K_LSHIFT] && g_abKeyPressed[K_LEFT] &&
			map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != (char)219)
		{
			if (g_nChar.m_cLocation.Y == g_box1.m_cLocation.Y &&
				g_nChar.m_cLocation.X - 1 == g_box1.m_cLocation.X)
			{
				g_nChar.m_cLocation.X--;
				g_box1.m_cLocation.X--;
				boost = true;
			}
			else
			{
				g_nChar.m_cLocation.X--;
				boost = true;
			}
		}

		if (g_abKeyPressed[K_LSHIFT] && g_abKeyPressed[K_DOWN] &&
			map[g_nChar.m_cLocation.Y + 1][g_nChar.m_cLocation.X] != (char)219)
		{
			if (g_nChar.m_cLocation.Y + 1 == g_box1.m_cLocation.Y &&
				g_nChar.m_cLocation.X == g_box1.m_cLocation.X)
			{
				g_nChar.m_cLocation.Y++;
				g_box1.m_cLocation.Y++;
				boost = true;
			}
			else
			{
				g_nChar.m_cLocation.Y++;
				boost = true;
			}
		}

		if (g_abKeyPressed[K_LSHIFT] && g_abKeyPressed[K_RIGHT] &&
			map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != (char)219)
		{
			if (g_nChar.m_cLocation.Y == g_box1.m_cLocation.Y &&
				g_nChar.m_cLocation.X + 1 == g_box1.m_cLocation.X)
			{
				g_nChar.m_cLocation.X++;
				g_box1.m_cLocation.X++;
				boost = true;
			}
			else
			{
				g_nChar.m_cLocation.X++;
				boost = true;
			}
		}

		break;

	case leveltwo:

		if (g_abKeyPressed[K_RSHIFT] && g_abKeyPressed[K_W] &&
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y--;
			boost = true;
		}

		if (g_abKeyPressed[K_RSHIFT] && g_abKeyPressed[K_A] &&
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
		{
			g_sChar.m_cLocation.X--;
			boost = true;
		}

		if (g_abKeyPressed[K_RSHIFT] && g_abKeyPressed[K_S] &&
			map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y++;
			boost = true;
		}

		if (g_abKeyPressed[K_RSHIFT] && g_abKeyPressed[K_D] &&
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
		{
			g_sChar.m_cLocation.X++;
			boost = true;
		}

		if (g_abKeyPressed[K_LSHIFT] && g_abKeyPressed[K_UP] &&
			map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] != (char)219)
		{
			g_nChar.m_cLocation.Y--;
			boost = true;
		}

		if (g_abKeyPressed[K_LSHIFT] && g_abKeyPressed[K_LEFT] &&
			map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != (char)219)
		{
			g_nChar.m_cLocation.X--;
			boost = true;
		}

		if (g_abKeyPressed[K_LSHIFT] && g_abKeyPressed[K_DOWN] &&
			map[g_nChar.m_cLocation.Y + 1][g_nChar.m_cLocation.X] != (char)219)
		{
			g_nChar.m_cLocation.Y++;
			boost = true;
		}

		if (g_abKeyPressed[K_LSHIFT] && g_abKeyPressed[K_RIGHT] &&
			map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != (char)219)
		{
			g_nChar.m_cLocation.X++;
			boost = true;
		}
		break;
	}
	if (boost)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTimeBoost = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}