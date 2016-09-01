#include "movelevel4.h"

//Done by Eugene.
void movelevel4()
{
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
	{
		return;
	}

	if (g_abKeyPressed[K_W])
	{
		if (door2 == true && door4 == true)
		{
			if (g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1 &&
				map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
			{
				if (g_sChar.m_cLocation.Y - 1 == boxone.m_cLocation.Y &&
					g_sChar.m_cLocation.X == boxone.m_cLocation.X)
				{
					g_sChar.m_cLocation.Y--;
					boxone.m_cLocation.Y--;
					bSomethingHappened = true;
				}
				else if (g_sChar.m_cLocation.Y-1 == boxtwo.m_cLocation.Y &&
					g_sChar.m_cLocation.X == boxtwo.m_cLocation.X)
				{
					g_sChar.m_cLocation.Y--;
					boxtwo.m_cLocation.Y--;
					bSomethingHappened = true;
				}
				else
				{
					g_sChar.m_cLocation.Y--;
					bSomethingHappened = true;
				}
			}
		}
		if (door2 == false && door4 == false)
		{
			if (g_sChar.m_cLocation.Y > 0 &&
				map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219 &&
				map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] !=
				map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] && map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X]
				&& map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X])

			{
				if (g_sChar.m_cLocation.Y - 1 == boxone.m_cLocation.Y &&
					g_sChar.m_cLocation.X == boxone.m_cLocation.X)
				{
					g_sChar.m_cLocation.Y--;
					boxone.m_cLocation.Y--;
					bSomethingHappened = true;
				}
				else if (g_sChar.m_cLocation.Y - 1 == boxtwo.m_cLocation.Y &&
					g_sChar.m_cLocation.X == boxtwo.m_cLocation.X)
				{
					g_sChar.m_cLocation.Y--;
					boxtwo.m_cLocation.Y--;
					bSomethingHappened = true;
				}

				else
				{
					g_sChar.m_cLocation.Y--;
					bSomethingHappened = true;
				}
			}
		}
	}


	if (g_abKeyPressed[K_A])
	{

		if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
		{
			if (g_sChar.m_cLocation.Y == boxone.m_cLocation.Y &&
				g_sChar.m_cLocation.X - 1 == boxone.m_cLocation.X)
			{
				g_sChar.m_cLocation.X--;
				boxone.m_cLocation.X--;
				bSomethingHappened = true;
			}

			else if (g_sChar.m_cLocation.Y == boxtwo.m_cLocation.Y &&
				g_sChar.m_cLocation.X - 1 == boxtwo.m_cLocation.X)
			{
				g_sChar.m_cLocation.X--;
				boxtwo.m_cLocation.X--;
				bSomethingHappened = true;
			}

			else if (door1 == false && door5 == false)
			{
				if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != map[g_door5.m_cLocation.Y][g_door5.m_cLocation.X] &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
				{
					g_sChar.m_cLocation.X--;
					bSomethingHappened = true;
				}
			}

			else if (door1 == true && door5 == false)
			{
				if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != map[g_door5.m_cLocation.Y][g_door5.m_cLocation.X])
				{
					g_sChar.m_cLocation.X--;
					bSomethingHappened = true;
				}
			}

			else if (door1 == false && door5 == true)
			{
				if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X]
					&& map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
				{
					g_sChar.m_cLocation.X--;
					bSomethingHappened = true;
				}
			}

			else if (door1 == true && door5 == true)
			{

				g_sChar.m_cLocation.X--;
				bSomethingHappened = true;

			}
		}
	}

	if (g_abKeyPressed[K_S])
	{
		if (door2 == true && door4 == true)
		{
			if (g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1 &&
				map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
			{
				if (g_sChar.m_cLocation.Y + 1 == boxone.m_cLocation.Y &&
					g_sChar.m_cLocation.X == boxone.m_cLocation.X)
				{
					g_sChar.m_cLocation.Y++;
					boxone.m_cLocation.Y++;
					bSomethingHappened = true;
				}
				else if (g_sChar.m_cLocation.Y + 1 == boxtwo.m_cLocation.Y &&
					g_sChar.m_cLocation.X == boxtwo.m_cLocation.X)
				{
					g_sChar.m_cLocation.Y++;
					boxtwo.m_cLocation.Y++;
					bSomethingHappened = true;
				}
				else
				{
					g_sChar.m_cLocation.Y++;
					bSomethingHappened = true;
				}
			}
		}
		if (door2 == false && door4 == false)
		{
			if (g_sChar.m_cLocation.Y > 0 &&
				map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219 &&
				map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] !=
				map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] && map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X]
				&& map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X])

			{
				if (g_sChar.m_cLocation.Y + 1 == boxone.m_cLocation.Y &&
					g_sChar.m_cLocation.X == boxone.m_cLocation.X)
				{
					g_sChar.m_cLocation.Y++;
					boxone.m_cLocation.Y++;
					bSomethingHappened = true;
				}
				else if (g_sChar.m_cLocation.Y + 1 == boxtwo.m_cLocation.Y &&
					g_sChar.m_cLocation.X == boxtwo.m_cLocation.X)
				{
					g_sChar.m_cLocation.Y++;
					boxtwo.m_cLocation.Y++;
					bSomethingHappened = true;
				}

				else
				{
					g_sChar.m_cLocation.Y++;
					bSomethingHappened = true;
				}
			}
		}
	}

	if (g_abKeyPressed[K_D])
	{

		if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
		{
			if (g_sChar.m_cLocation.Y == boxtwo.m_cLocation.Y &&
				g_sChar.m_cLocation.X + 1 == boxtwo.m_cLocation.X)
			{
				g_sChar.m_cLocation.X++;
				boxtwo.m_cLocation.X++;
				bSomethingHappened = true;
			}

			else if (g_sChar.m_cLocation.Y == boxone.m_cLocation.Y &&
				g_sChar.m_cLocation.X + 1 == boxone.m_cLocation.X)
			{
				g_sChar.m_cLocation.X++;
				boxone.m_cLocation.X++;
				bSomethingHappened = true;
			}

			else if (door3 == false && door5 == false)
			{
				if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X] &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != map[g_door5.m_cLocation.Y][g_door5.m_cLocation.X] && 
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X])
				{
					g_sChar.m_cLocation.X++;
					bSomethingHappened = true;
				}
			}

			else if (door3 == true && door5 == false)
			{
				if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != map[g_door5.m_cLocation.Y][g_door5.m_cLocation.X])
				{
					g_sChar.m_cLocation.X++;
					bSomethingHappened = true;
				}
			}

			else if (door3 == false && door5 == true)
			{
				if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X]
					&& map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X])
				{
					g_sChar.m_cLocation.X++;
					bSomethingHappened = true;
				}
			}

			else if (door3 == true && door5 == true)
			{

				g_sChar.m_cLocation.X++;
				bSomethingHappened = true;

			}
		}
	}

	if (g_abKeyPressed[K_UP])
	{
		if (door2 == true && door4 == true)
		{
			if (g_nChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1 &&
				map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] != (char)219)
			{
				if (g_nChar.m_cLocation.Y - 1 == boxone.m_cLocation.Y &&
					g_nChar.m_cLocation.X == boxone.m_cLocation.X)
				{
					g_nChar.m_cLocation.Y--;
					boxone.m_cLocation.Y--;
					bSomethingHappened = true;
				}
				else if (g_nChar.m_cLocation.Y-1 == boxtwo.m_cLocation.Y &&
					g_nChar.m_cLocation.X == boxtwo.m_cLocation.X)
				{
					g_nChar.m_cLocation.Y--;
					boxtwo.m_cLocation.Y--;
					bSomethingHappened = true;
				}
				else
				{
					g_nChar.m_cLocation.Y--;
					bSomethingHappened = true;
				}
			}
		}
		if (door2 == false && door4 == false)
		{
			if (g_nChar.m_cLocation.Y > 0 &&
				map[g_nChar.m_cLocation.Y-1][g_nChar.m_cLocation.X ] != (char)219 &&
				map[g_nChar.m_cLocation.Y-1][g_nChar.m_cLocation.X] !=
				map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] && map[g_nChar.m_cLocation.Y-1][g_nChar.m_cLocation.X]
				&& map[g_nChar.m_cLocation.Y-1][g_nChar.m_cLocation.X ] != map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X])

			{
				if (g_nChar.m_cLocation.Y-1 == boxone.m_cLocation.Y &&
					g_nChar.m_cLocation.X == boxone.m_cLocation.X)
				{
					g_nChar.m_cLocation.Y--;
					boxone.m_cLocation.Y--;
					bSomethingHappened = true;
				}
				else if (g_nChar.m_cLocation.Y-1 == boxtwo.m_cLocation.Y &&
					g_nChar.m_cLocation.X == boxtwo.m_cLocation.X)
				{
					g_nChar.m_cLocation.Y--;
					boxtwo.m_cLocation.Y--;
					bSomethingHappened = true;
				}

				else
				{
					g_nChar.m_cLocation.Y--;
					bSomethingHappened = true;
				}
			}
		}
	}


	if (g_abKeyPressed[K_LEFT])
	{
		if (g_nChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
			map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != (char)219)
		{
			if (g_nChar.m_cLocation.Y == boxtwo.m_cLocation.Y &&
				g_nChar.m_cLocation.X - 1 == boxtwo.m_cLocation.X)
			{
				g_nChar.m_cLocation.X--;
				boxtwo.m_cLocation.X--;
				bSomethingHappened = true;
			}

			else if (g_nChar.m_cLocation.Y == boxone.m_cLocation.Y &&
				g_nChar.m_cLocation.X - 1 == boxone.m_cLocation.X)
			{
				g_nChar.m_cLocation.X--;
				boxone.m_cLocation.X--;
				bSomethingHappened = true;
			}

			else if (door1 == false && door5 == false)
			{
				if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] &&
					map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != map[g_door5.m_cLocation.Y][g_door5.m_cLocation.X] &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
				{
					g_nChar.m_cLocation.X--;
					bSomethingHappened = true;
				}
			}

			else if (door1 == true && door5 == false)
			{
				if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != map[g_door5.m_cLocation.Y][g_door5.m_cLocation.X])
				{
					g_nChar.m_cLocation.X--;
					bSomethingHappened = true;
				}
			}

			else if (door1 == false && door5 == true)
			{
				if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X])
				{
					g_nChar.m_cLocation.X--;
					bSomethingHappened = true;
				}
			}

			else if (door1 == true && door5 == true)
			{

				g_nChar.m_cLocation.X--;
				bSomethingHappened = true;

			}
		}
	}


	if (g_abKeyPressed[K_DOWN])
	{
		if (door2 == true && door4 == true)
		{
			if (g_nChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1 &&
				map[g_nChar.m_cLocation.Y + 1][g_nChar.m_cLocation.X] != (char)219)
			{
				if (g_nChar.m_cLocation.Y + 1 == boxone.m_cLocation.Y &&
					g_nChar.m_cLocation.X == boxone.m_cLocation.X)
				{
					g_nChar.m_cLocation.Y++;
					boxone.m_cLocation.Y++;
					bSomethingHappened = true;
				}
				else if (g_nChar.m_cLocation.Y+1 == boxtwo.m_cLocation.Y &&
					g_nChar.m_cLocation.X == boxtwo.m_cLocation.X)
				{
					g_nChar.m_cLocation.Y++;
					boxtwo.m_cLocation.Y++;
					bSomethingHappened = true;
				}
				else
				{
					g_nChar.m_cLocation.Y++;
					bSomethingHappened = true;
				}
			}
		}
		if (door2 == false && door4 == false)
		{
			if (g_nChar.m_cLocation.Y > 0 &&
				map[g_nChar.m_cLocation.Y + 1][g_nChar.m_cLocation.X] != (char)219 &&
				map[g_nChar.m_cLocation.Y + 1][g_nChar.m_cLocation.X] !=
				map[g_door2.m_cLocation.Y][g_door2.m_cLocation.X] && map[g_nChar.m_cLocation.Y + 1][g_nChar.m_cLocation.X]
				&& map[g_nChar.m_cLocation.Y + 1][g_nChar.m_cLocation.X] != map[g_door4.m_cLocation.Y][g_door4.m_cLocation.X])

			{
				if (g_nChar.m_cLocation.Y + 1 == boxone.m_cLocation.Y &&
					g_nChar.m_cLocation.X == boxone.m_cLocation.X)
				{
					g_nChar.m_cLocation.Y++;
					boxone.m_cLocation.Y++;
					bSomethingHappened = true;
				}
				else if (g_nChar.m_cLocation.Y + 1 == boxtwo.m_cLocation.Y &&
					g_nChar.m_cLocation.X == boxtwo.m_cLocation.X)
				{
					g_nChar.m_cLocation.Y++;
					boxtwo.m_cLocation.Y++;
					bSomethingHappened = true;
				}

				else
				{
					g_nChar.m_cLocation.Y++;
					bSomethingHappened = true;
				}
			}
		}
	}

	if (g_abKeyPressed[K_RIGHT])
	{
		if (g_nChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
			map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != (char)219)
		{
			if (g_nChar.m_cLocation.Y == boxtwo.m_cLocation.Y &&
				g_nChar.m_cLocation.X + 1 == boxtwo.m_cLocation.X)
			{
				g_nChar.m_cLocation.X++;
				boxtwo.m_cLocation.X++;
				bSomethingHappened = true;
			}

			else if (g_nChar.m_cLocation.Y == boxone.m_cLocation.Y &&
				g_nChar.m_cLocation.X + 1 == boxone.m_cLocation.X)
			{
				g_nChar.m_cLocation.X++;
				boxone.m_cLocation.X++;
				bSomethingHappened = true;
			}

			else if (door3 == false && door5 == false)
			{
				if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X] &&
					map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != map[g_door5.m_cLocation.Y][g_door5.m_cLocation.X] &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X])
				{
					g_nChar.m_cLocation.X++;
					bSomethingHappened = true;
				}
			}

			else if (door3 == true && door5 == false)
			{
				if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != map[g_door5.m_cLocation.Y][g_door5.m_cLocation.X])
				{
					g_nChar.m_cLocation.X++;
					bSomethingHappened = true;
				}
			}

			else if (door3 == false && door5 == true)
			{
				if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != map[g_door3.m_cLocation.Y][g_door3.m_cLocation.X] &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X])
				{
					g_nChar.m_cLocation.X++;
					bSomethingHappened = true;
				}
			}

			else if (door3 == true && door5 == true)
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