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
		(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
		//g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y &&
		//(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) >= -4) &&
		map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
	{
		g_enemy2.m_cLocation.X++;
	}

	if (g_enemy2.m_cLocation.X > 0 &&
		g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
		//g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y &&
		//g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X <= 4 &&
		map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
	{
		g_enemy2.m_cLocation.X--;
	}

	if (g_enemy2.m_cLocation.Y > 0 &&
		(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
		//g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X &&
		//(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) >= -4) &&
		map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
	{
		g_enemy2.m_cLocation.Y++;
	}


	if (g_enemy2.m_cLocation.Y > 0 &&
		(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
		//g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X &&
		//(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) <= 4) &&
		map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
	{
		g_enemy2.m_cLocation.Y--;
	}



	//	while (1)
	//{
	//	g_enemy.m_cLocation.X += 1;
	//	g_enemy.m_cLocation.Y += 1;
	//	g_enemy.m_cLocation.X -= 1;
	//	g_enemy.m_cLocation.Y -= 1;
	//	break;
	//}
	//static int square_state = 0;

	//// bottom left to top left is done
	//if (g_enemy.m_cLocation.Y <= g_enemy.m_cLocation.Y- 25 && square_state == 0)
	//	square_state = 1;

	//// top left to top right is done
	//if (g_enemy.m_cLocation.X >= g_enemy.m_cLocation.X + 25 && square_state == 1)
	//	square_state = 2;

	//// top right to bottom right is done
	//if (g_enemy.m_cLocation.Y >= g_enemy.m_cLocation.Y + 25  && square_state == 2)
	//	square_state = 3;

	//// bottom right to bottom left is done
	//if (g_enemy.m_cLocation.X <= g_enemy.m_cLocation.X - 25  && square_state == 3)
	//	square_state = 0;

	//switch (square_state)
	//{
	//case 0: // bottom left to top left
	//	g_enemy.m_cLocation.Y -= 1;
	//	break;

	//case 1: // top left to top right
	//	g_enemy.m_cLocation.X += 1;
	//	break;

	//case 2: // top right to bottom right
	//	g_enemy.m_cLocation.Y += 1;
	//	break;

	//case 3: // bottom right to bottom left
	//	g_enemy.m_cLocation.X -= 1;
	//	break;
	//}

}