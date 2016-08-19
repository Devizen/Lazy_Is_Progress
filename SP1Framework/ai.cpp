#include "ai.h"
#include "level1.h"
#include "game.h"
#include "health.h"

//Done by Eugene.
void motiondetect()
{
	//For First Character
	if (g_enemy.m_cLocation.X > 0 &&
		((g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
		g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y &&
		(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) >= -4) &&
		map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
	{
		g_enemy.m_cLocation.X++;
	}

	if (g_enemy.m_cLocation.X > 0 &&
		g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 && 
		g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y &&
		g_enemy.m_cLocation.X - g_sChar.m_cLocation.X <= 4 && 
		map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
	{
		g_enemy.m_cLocation.X--;
	}
	
	if (g_enemy.m_cLocation.Y > 0 &&
		((g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
		g_enemy.m_cLocation.X == g_sChar.m_cLocation.X &&
		(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) >= -4) &&
		map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
	{
		g_enemy.m_cLocation.Y++;
	}


	if (g_enemy.m_cLocation.Y > 0 &&
		((g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
		g_enemy.m_cLocation.X == g_sChar.m_cLocation.X &&
		(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) <= 4) &&
		map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
	{
		g_enemy.m_cLocation.Y--;
	}



	if (g_enemy.m_cLocation.X > 0 &&
		((g_enemy.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
		g_enemy.m_cLocation.Y == g_nChar.m_cLocation.Y &&
		(g_enemy.m_cLocation.X - g_nChar.m_cLocation.X) >= -4) &&
		map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
	{
		g_enemy.m_cLocation.X++;
	}

	if (g_enemy.m_cLocation.X > 0 &&
		g_enemy.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
		g_enemy.m_cLocation.Y == g_nChar.m_cLocation.Y &&
		g_enemy.m_cLocation.X - g_nChar.m_cLocation.X <= 4 &&
		map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
	{
		g_enemy.m_cLocation.X--;
	}

	if (g_enemy.m_cLocation.Y > 0 &&
		((g_enemy.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
		g_enemy.m_cLocation.X == g_nChar.m_cLocation.X &&
		(g_enemy.m_cLocation.Y - g_nChar.m_cLocation.Y) >= -4) &&
		map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
	{
		g_enemy.m_cLocation.Y++;
	}

	if (g_enemy.m_cLocation.Y > 0 &&
		((g_enemy.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
		g_enemy.m_cLocation.X == g_nChar.m_cLocation.X &&
		(g_enemy.m_cLocation.Y - g_nChar.m_cLocation.Y) <= 4) &&
		map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
	{
		g_enemy.m_cLocation.Y--;
	}

	//Second Character
	if (g_enemy2.m_cLocation.X > 0 &&
		((g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
		g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y &&
		(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) >= -4) &&
		map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
	{
		g_enemy2.m_cLocation.X++;
	}

	if (g_enemy2.m_cLocation.X > 0 &&
		g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
		g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y &&
		g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X <= 4 &&
		map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
	{
		g_enemy2.m_cLocation.X--;
	}

	if (g_enemy2.m_cLocation.Y > 0 &&
		((g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
		g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X &&
		(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) >= -4) &&
		map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
	{
		g_enemy2.m_cLocation.Y++;
	}


	if (g_enemy2.m_cLocation.Y > 0 &&
		((g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
		g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X &&
		(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) <= 4) &&
		map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
	{
		g_enemy2.m_cLocation.Y--;
	}



	if (g_enemy2.m_cLocation.X > 0 &&
		((g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
		g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y &&
		(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) >= -4) &&
		map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
	{
		g_enemy2.m_cLocation.X++;
	}

	if (g_enemy2.m_cLocation.X > 0 &&
		g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
		g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y &&
		g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X <= 4 &&
		map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
	{
		g_enemy2.m_cLocation.X--;
	}

	if (g_enemy2.m_cLocation.Y > 0 &&
		((g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
		g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X &&
		(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) >= -4) &&
		map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
	{
		g_enemy2.m_cLocation.Y++;
	}

	if (g_enemy2.m_cLocation.Y > 0 &&
		((g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
		g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X &&
		(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) <= 4) &&
		map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
	{
		g_enemy2.m_cLocation.Y--;

	}
}