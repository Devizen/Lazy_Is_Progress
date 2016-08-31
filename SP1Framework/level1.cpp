#include "level1.h"

bool powerup = true;
bool timeincrease = true;

//Fix box into special wall
//Done by Eugene.
void level1()
{
	string line = " ";
	COORD c;

	if (splash == true)
	{
		string name = "Text/Screen/level1.txt";
		loadlevel(name);

		c.X = 15;
		c.Y = 7;

		clearScreen();
		for (int i = 0; i <= y; i++)
		{
			line = map[i];
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}

		if (g_dCountTime < 59 && story == true)
		{
			name = "Text/Story/level1.txt";
			loadlevel(name);

			c.X = 0;
			c.Y = 0;

			clearScreen();
			for (int i = 0; i <= y; i++)
			{
				line = map[i];
				g_Console.writeToBuffer(c, line);
				c.Y++;
			}

			if (g_dCountTime < 55)
			{
				splash = false;
				story = false;
				renderGame();
			}
		}

		if (g_dCountTime < 59 && story == false)
		{
			splash = false;
			renderGame();
		}
	}

	if (splash == false)
	{
		string name = "Text/Level/level1.txt";
		loadlevel(name);

		//COORD c;

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

		//string line = " ";
		//string name = "Text/Level/level1.txt";
		//loadlevel(name);
		//COORD c;


		//c.X = 0;
		//c.Y = 0;

		//for (int i = 0; i <= y; i++)
		//{
		//	line = map[i];
		//	g_Console.writeToBuffer(c, line);
		//	c.Y++;
		//}


		////First Character
		//g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

		////Second Character
		//g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

		////Enemy
		//g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
		//g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

		////Door
		//g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, charColor);

		////Lever
		//g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, charColor);

		////Box	
		//g_Console.writeToBuffer(g_box1.m_cLocation, (char)254, charColor);

		////Release A.I
		//g_Console.writeToBuffer(release_enemy.m_cLocation, (char)219, charColor);

		////Powerup
		//g_Console.writeToBuffer(g_powerup.m_cLocation, (char)206, charColor3);

		//TimerUp
		//g_Console.writeToBuffer(g_timeboost.m_cLocation, (char)64, charColor3);

		COORD d;
		d.X = 63;
		d.Y = 14;
		g_Console.writeToBuffer(d, "Hint:",yellow);
		d.X = 63;
		d.Y = 15;
		g_Console.writeToBuffer(d, "Running [RShift]");
		d.Y = 16;
		g_Console.writeToBuffer(d, "with");
		d.X = 68;
		g_Console.writeToBuffer(d, (char)3, red);
		d.X = 70;
		g_Console.writeToBuffer(d, "is key.");

		rendercharacters();

		motiondetect();

		if (map[g_box1.m_cLocation.Y][g_box1.m_cLocation.X] == map[g_lever1.m_cLocation.Y][g_lever1.m_cLocation.X])
		{
			g_Console.writeToBuffer(g_lever1.m_cLocation, (char)219, green);
			g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, green);
			g_Console.writeToBuffer(release_enemy.m_cLocation, (char)219, green);
			g_Console.writeToBuffer(release_enemy1.m_cLocation, (char)219, green);
			g_Console.writeToBuffer(release_enemy2.m_cLocation, (char)219, green);
			g_Console.writeToBuffer(release_enemy3.m_cLocation, (char)219, green);
			g_Console.writeToBuffer(release_enemy4.m_cLocation, (char)219, green);
			g_Console.writeToBuffer(release_enemy5.m_cLocation, (char)219, green);
			g_Console.writeToBuffer(release_enemy6.m_cLocation, (char)219, green);
			g_Console.writeToBuffer(release_enemy7.m_cLocation, (char)219, green);
			g_Console.writeToBuffer(release_enemy8.m_cLocation, (char)219, green);

			door1 = true;
		}
		else
		{
			door1 = false;
		}

		if (timeincrease == true)
		{
			g_Console.writeToBuffer(g_timeboost.m_cLocation, (char)64, purple);
		}

		if (powerup == true)
		{
			g_Console.writeToBuffer(g_powerup.m_cLocation, (char)206, purple);
		}

		if ((g_timeboost.m_cLocation.X == g_nChar.m_cLocation.X) && (g_timeboost.m_cLocation.Y == g_nChar.m_cLocation.Y && timeincrease == true))
		{
			g_dCountTime += 5.00;
			timeincrease = false;
		}
		if (timeincrease == false)
		{
			g_Console.writeToBuffer(g_timeboost.m_cLocation, (char)64, darkblue);
		}

		if ((g_powerup.m_cLocation.X == g_nChar.m_cLocation.X) && (g_powerup.m_cLocation.Y == g_nChar.m_cLocation.Y && powerup == true))
		{
			g_sChar.health++;
			powerup = false;
		}
		if (powerup == false)
		{
			g_Console.writeToBuffer(g_powerup.m_cLocation, (char)206, darkblue);
		}

		if (map[g_box1.m_cLocation.Y][g_box1.m_cLocation.X] == (char)219 ||
			map[g_box1.m_cLocation.Y][g_box1.m_cLocation.X] ==
			map[release_enemy.m_cLocation.Y][release_enemy.m_cLocation.X])
		{
			g_box1.m_cLocation.X = 54;
			g_box1.m_cLocation.Y = 21;
		}

		if ((g_enemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y) ||
			(g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y))
		{
			//Deduct one health.
			g_sChar.health -= 1;
			if (g_sChar.health > 0)
			{	//Prevent health from reverting back to 3.
				restarthealth = false;

				//Displaying Splash Screen.
				splash = true;

				//Revert level settings to default.
				spawn();
			}

			else
			{	//Boolean for restarting the level after gameover.
				level = one;
				/*g_eGameState = S_RESULT;*/
				load = defeated;
				renderGame();
			}
		}


		//Teleport character to the top.
		if (g_sChar.m_cLocation.X == 8 &&
			g_sChar.m_cLocation.Y == 22)
		{
			g_sChar.m_cLocation.X = 29;
			g_sChar.m_cLocation.Y = 5;
		}

		//Progress to next level.
		if (g_sChar.m_cLocation.X == 1 &&
			g_sChar.m_cLocation.Y == 1 &&
			g_nChar.m_cLocation.X == 39 &&
			g_nChar.m_cLocation.Y == 22)
		{
			//g_sChar.m_cLocation.X = 11;
			//g_sChar.m_cLocation.Y = 10;

			//g_nChar.m_cLocation.X = 49;
			//g_nChar.m_cLocation.Y = 10;
			g_sChar.health = 3;

			g_dCountTime = 60;
			load = leveltwo;
			restarthealth = true;
			splash = true;

			//Displaying Story Screen.
			story = true;

			spawn();
			renderGame();
		}
	}
}