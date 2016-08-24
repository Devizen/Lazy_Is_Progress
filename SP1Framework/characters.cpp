#include "characters.h"
#include "level1.h"
#include "game.h"
#include "health.h"

//Done by Eugene.
void motiondetect()
{
	bool bSomethingHappened = false;
	if (ai_BounceTime > g_dElapsedTime)
	{
		return;
	}

	switch (load)
	{
	case levelzero:
		//For First Character
		if (g_enemy.m_cLocation.X > 0 &&
			(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
		{
			g_enemy.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.X > 0 &&
			g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
		{
			g_enemy.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
			map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
			map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		//For Second Character
		if (g_enemy2.m_cLocation.X > 0 &&
			(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
		{
			g_enemy2.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.X > 0 &&
			g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
		{
			g_enemy2.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
			map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
			map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y--;
			bSomethingHappened = true;
		}
		break;

	case levelone:
		//For First Character
		if (g_enemy.m_cLocation.X > 0 &&
			(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
		{
			g_enemy.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.X > 0 &&
			g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
		{
			g_enemy.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
			map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
			map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		//Second Character
		if (g_enemy2.m_cLocation.X > 0 &&
			(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
		{
			g_enemy2.m_cLocation.X++;
			bSomethingHappened = true;

		}

		if (g_enemy2.m_cLocation.X > 0 &&
			g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
		{
			g_enemy2.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0)
		{
			if (door1 == true)
			{
				if (map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
				{
					g_enemy2.m_cLocation.Y++;
					bSomethingHappened = true;
				}
			}
			if (door1 == false)
			{
				if (map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219 &&
					map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
					map[release_enemy.m_cLocation.Y][release_enemy.m_cLocation.X] &&
					map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
					map[release_enemy1.m_cLocation.Y][release_enemy1.m_cLocation.X] &&
					map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
					map[release_enemy2.m_cLocation.Y][release_enemy2.m_cLocation.X] &&
					map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
					map[release_enemy3.m_cLocation.Y][release_enemy3.m_cLocation.X] &&
					map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
					map[release_enemy4.m_cLocation.Y][release_enemy4.m_cLocation.X] &&
					map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
					map[release_enemy5.m_cLocation.Y][release_enemy5.m_cLocation.X] &&
					map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
					map[release_enemy6.m_cLocation.Y][release_enemy6.m_cLocation.X] &&
					map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
					map[release_enemy7.m_cLocation.Y][release_enemy7.m_cLocation.X] &&
					map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] !=
					map[release_enemy8.m_cLocation.Y][release_enemy8.m_cLocation.X])
				{
					g_enemy2.m_cLocation.Y++;
					bSomethingHappened = true;
				}
			}
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
			map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y--;
			bSomethingHappened = true;
		}
		break;

	case leveltwo:
		//For First Character
		if (g_enemy.m_cLocation.X > 0 &&
			(g_enemy.m_cLocation.X - g_sChar.m_cLocation.X) < 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X + 1] != (char)219)
		{
			g_enemy.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.X > 0 &&
			g_enemy.m_cLocation.X - g_sChar.m_cLocation.X > 0 &&
			map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X - 1] != (char)219)
		{
			g_enemy.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) < 0 &&
			map[g_enemy.m_cLocation.Y + 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy.m_cLocation.Y > 0 &&
			(g_enemy.m_cLocation.Y - g_sChar.m_cLocation.Y) > 0 &&
			map[g_enemy.m_cLocation.Y - 1][g_enemy.m_cLocation.X] != (char)219)
		{
			g_enemy.m_cLocation.Y--;
			bSomethingHappened = true;
		}

		//For Second Character
		if (g_enemy2.m_cLocation.X > 0 &&
			(g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X) < 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X + 1] != (char)219)
		{
			g_enemy2.m_cLocation.X++;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.X > 0 &&
			g_enemy2.m_cLocation.X - g_nChar.m_cLocation.X > 0 &&
			map[g_enemy2.m_cLocation.Y][g_enemy2.m_cLocation.X - 1] != (char)219)
		{
			g_enemy2.m_cLocation.X--;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) < 0 &&
			map[g_enemy2.m_cLocation.Y + 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y++;
			bSomethingHappened = true;
		}

		if (g_enemy2.m_cLocation.Y > 0 &&
			(g_enemy2.m_cLocation.Y - g_nChar.m_cLocation.Y) > 0 &&
			map[g_enemy2.m_cLocation.Y - 1][g_enemy2.m_cLocation.X] != (char)219)
		{
			g_enemy2.m_cLocation.Y--;
			bSomethingHappened = true;
		}
		break;
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		ai_BounceTime = g_dElapsedTime + 0.175; // 125ms should be enough
	}

	if (map[g_box1.m_cLocation.Y][g_box1.m_cLocation.X] == (char)219)
	{
		g_box1.m_cLocation.X = 54;
		g_box1.m_cLocation.Y = 21;
	}
}

//Done by Eugene.
void rendercharacters()
{
	WORD charColor = 0x0C;
	WORD charColor2 = 0x0A;

	switch (load)
	{
	case levelzero:
		//First Character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

		//Second Character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

		break;
	case levelone:

		//First Character
		g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

		//Second Character
		g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

		//Enemy
		g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
		g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

		//Door
		g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, charColor);

		//Lever
		g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, charColor);

		//Box
		g_Console.writeToBuffer(g_box1.m_cLocation, (char)254, charColor);

		//Release A.I
		g_Console.writeToBuffer(release_enemy.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy1.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy2.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy3.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy4.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy5.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy6.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy7.m_cLocation, (char)219, charColor);
		g_Console.writeToBuffer(release_enemy8.m_cLocation, (char)219, charColor);
		break;

	case leveltwo:
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
		break;
	}
}