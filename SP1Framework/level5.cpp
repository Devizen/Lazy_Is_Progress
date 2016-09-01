#include  "level5.h"
#include "characters.h"
#include "game.h"
#include "health.h"

//Preventing Time Increase endless adding.
bool t1 = true;
bool t2 = true;
bool t3 = true;
bool t4 = true;
bool t5 = true;

//Done by Eugene.
void level5()
{
	string line = " ";
	COORD c;

	if (splash == true)
	{
		string name = "Text/Screen/level5.txt";
		loadlevel(name);

		c.X = 8;
		c.Y = 7;

		clearScreen();
		for (unsigned int i = 0; i <= y; i++)
		{
			line = map[i];
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}

		if (g_dCountTime < 59 && story == true)
		{
			name = "Text/Story/level5.txt";
			loadlevel(name);

			c.X = 0;
			c.Y = 0;

			clearScreen();
			for (unsigned int i = 0; i <= y; i++)
			{
				line = map[i];
				g_Console.writeToBuffer(c, line);
				c.Y++;
			}

			if (g_dCountTime < 40)
			{
				splash = false;
				story = false;
				renderGame();
			}

			if (g_abKeyPressed[K_RETURN])
			{
				g_dCountTime = 39;
			}

			COORD d;
			d.X = 62;
			d.Y = 14;
			g_Console.writeToBuffer(d, "To Skip:", yellow);
			d.Y = 15;
			g_Console.writeToBuffer(d, "Press the");
			d.Y = 16;
			g_Console.writeToBuffer(d, "[Enter] button");
			d.Y = 17;
			g_Console.writeToBuffer(d, "to skip the story.");
		}

		if (g_dCountTime < 59 && story == false)
		{
			splash = false;
			g_dCountTime = 60;
			renderGame();
		}
	}

	if (splash == false)
	{
		string name = "Text/Level/level5_0.txt";
		loadlevel(name);

		//COORD c;

		c.X = 0;
		c.Y = 0;

		for (unsigned int i = 0; i <= y; i++)
		{
			line = map[i];
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}

		COORD y;
		y.X = 15;
		y.Y = 15;

		//string line = " ";
		//string name = "Text/Level/level4.txt";
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
		rendercharacters();
		patrolai();
		//motiondetect();
		//patrolfour();

		COORD d;
		d.X = 63;
		d.Y = 14;
		g_Console.writeToBuffer(d, "Hint:", yellow);
		d.Y = 15;
		g_Console.writeToBuffer(d, "Just keep moving.");
		d.Y = 16;
		g_Console.writeToBuffer(d, "Do not look back");
		d.Y = 17;
		g_Console.writeToBuffer(d, "or hesistate!");

		if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == map[g_lever1.m_cLocation.Y][g_lever1.m_cLocation.X] || door1 == true)
		{
			g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, green);
			door1 = true;
			if (t1 == true)
			{
				g_dCountTime += 5;
				t1 = false;
			}
			else
			{
				g_Console.writeToBuffer(g_lever1.m_cLocation, (char)64, darkblue);
			}
		}

		if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == map[g_lever2.m_cLocation.Y][g_lever2.m_cLocation.X] || door2 == true)
		{
			g_Console.writeToBuffer(g_door2.m_cLocation, (char)219, green);
			door2 = true;
			if (t2 == true)
			{
				g_dCountTime += 5;
				t2 = false;
			}
			else
			{
				g_Console.writeToBuffer(g_lever2.m_cLocation, (char)64, darkblue);
			}
		}

		if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == map[g_lever3.m_cLocation.Y][g_lever3.m_cLocation.X] || door3 == true)
		{
			g_Console.writeToBuffer(g_door3.m_cLocation, (char)219, green);
			door3 = true;
			if (t3 == true)
			{
				g_dCountTime += 5;
				t3 = false;
			}
			else
			{
				g_Console.writeToBuffer(g_lever3.m_cLocation, (char)64, darkblue);
			}
		}

		if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == map[g_lever4.m_cLocation.Y][g_lever4.m_cLocation.X] || door4 == true)
		{
			g_Console.writeToBuffer(g_door4.m_cLocation, (char)219, green);
			door4 = true;
			if (t4 == true)
			{
				g_dCountTime += 5;
				t4 = false;
			}
			else
			{
				g_Console.writeToBuffer(g_lever4.m_cLocation, (char)64, darkblue);
			}
		}

		if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == map[g_lever5.m_cLocation.Y][g_lever5.m_cLocation.X] || door5 == true)
		{
			g_Console.writeToBuffer(g_door5.m_cLocation, (char)219, green);
			door5 = true;
			if (t5 == true)
			{
				g_dCountTime += 5;
				t5 = false;
			}
			else
			{
				g_Console.writeToBuffer(g_lever5.m_cLocation, (char)64, darkblue);
			}
		}

		if (g_sChar.m_cLocation.X == 29 &&
			g_sChar.m_cLocation.Y == 1 &&
			g_nChar.m_cLocation.X == 59 &&
			g_nChar.m_cLocation.Y == 1)
		{
			g_sChar.health = 3;
			g_dCountTime = 60;
			restarthealth = true;
			load = levelfiveb;
			spawn();
			renderGame();
		}

		if ((g_enemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y) ||
			(g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y))
		{
			//Set boolean to false so the health will not reset.
			restarthealth = false;


			//Deduct one health.
			g_sChar.health -= 1;

			//Displaying Splash Screen.
			splash = true;

			//Revert the level settings.
			spawn();
		}

		if (g_sChar.health < 1)
		{
		level = five;
		load = defeated;
		renderGame();
		rendercharacters();
		}
	}
}

void level5_0()
{
	string line = " ";
	COORD c;

	if (splash == true)
	{
		string name = "Text/Screen/level5.txt";
		loadlevel(name);

		c.X = 8;
		c.Y = 7;

		clearScreen();
		for (unsigned int i = 0; i <= y; i++)
		{
			line = map[i];
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}

		if (g_dCountTime < 59)
		{
			splash = false;
			g_dCountTime = 60;
			renderGame();
		}
	}

	if (splash == false)
	{
		string name = "Text/Level/level5_1.txt";
		loadlevel(name);

		//COORD c;

		c.X = 0;
		c.Y = 0;

		for (unsigned int i = 0; i <= y; i++)
		{
			line = map[i];
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}

		c.Y = 0;
		for (unsigned int i = 0; i <= 25; i++)
		{
			for (unsigned int j = 0; j <= 80; j++)
			{
				if (map[i][j] == 't')
				{
					c.X = j;
					c.Y = i;
					g_Console.writeToBuffer(c, (char)177, darkblue);
				}
			}
		}

		COORD y;
		y.X = 15;
		y.Y = 15;

		map[17][14] = 'a';
		map[17][46] = 'b';
		map[15][46] = 'A';
		map[15][14] = 'B';
		map[8][14] = 'c';
		map[8][46] = 'd';
		map[6][14] = 'C';
		map[6][46] = 'D';

		//spawn();
		rendercharacters();

		COORD d;
		d.X = 63;
		d.Y = 14;
		g_Console.writeToBuffer(d, "Hint:", yellow);
		d.Y = 15;
		g_Console.writeToBuffer(d, "Get to the");
		d.Y = 16;
		g_Console.writeToBuffer(d, "teleporter for");
		d.Y = 17;
		g_Console.writeToBuffer(d, "both characters.");

		//motiondetect();
		if (g_sChar.m_cLocation.Y < 17 && g_nChar.m_cLocation.Y < 17)
		{
			motiondetect();
		}
		patrolfiveb();
		//patrolfour();

		if (g_dCountTime < 45 && g_sChar.m_cLocation.Y < 17 && g_nChar.m_cLocation.Y < 17)
		{
			d.Y = 15;
			g_Console.writeToBuffer(d, "Get to the");
			d.Y = 16;
			g_Console.writeToBuffer(d, "teleporter for");
			d.Y = 17;
			g_Console.writeToBuffer(d, "both characters.");
			g_Console.writeToBuffer(g_lever3.m_cLocation, (char)234, lightblue);
			g_Console.writeToBuffer(g_lever4.m_cLocation, (char)234, lightblue);

			if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == map[g_lever4.m_cLocation.Y][g_lever4.m_cLocation.X])
			{
				g_sChar.m_cLocation.X = 14;
				g_sChar.m_cLocation.Y = 6;
			}

			if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X] == map[g_lever3.m_cLocation.Y][g_lever3.m_cLocation.X])
			{
				g_nChar.m_cLocation.X = 46;
				g_nChar.m_cLocation.Y = 6;
			}
		}
		else if (g_dCountTime > 44 && g_sChar.m_cLocation.Y < 17 && g_nChar.m_cLocation.Y < 17)
		{
			d.Y = 15;
			g_Console.writeToBuffer(d, "Endure until");
			d.Y = 16;
			g_Console.writeToBuffer(d, "                ");
			g_Console.writeToBuffer(d, "time left is");
			d.Y = 17;
			g_Console.writeToBuffer(d, "                ");
			g_Console.writeToBuffer(d, "lesser than 45.");
		}

		if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == map[g_lever1.m_cLocation.Y][g_lever1.m_cLocation.X])
		{
			g_sChar.m_cLocation.X = 46;
			g_sChar.m_cLocation.Y = 15;
		}

		if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X] == map[g_lever2.m_cLocation.Y][g_lever2.m_cLocation.X])
		{
			g_nChar.m_cLocation.X = 14;
			g_nChar.m_cLocation.Y = 15;
		}

		//Realmadrid123
		if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == 't'/* ||
																	map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] == 't' ||
																	map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] == 't' ||
																	map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] == 't'*/)
		{
			g_sChar.m_cLocation.Y += 17;
			g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, red);
		}

		if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X] == 't'/* ||
																	map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] == 't' ||
																	map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] == 't' ||
																	map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] == 't'*/)
		{
			g_nChar.m_cLocation.Y += 17;
			g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, green);
		}


		if (g_sChar.m_cLocation.X == 27 &&
			g_sChar.m_cLocation.Y == 4 &&
			g_nChar.m_cLocation.X == 57 &&
			g_nChar.m_cLocation.Y == 4)
		{
			g_sChar.health = 3;
			g_dCountTime = 60;
			restarthealth = true;
			load = creditscreen;
			spawn();
			renderGame();
		}

		if ((g_enemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y) ||
			(g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y) ||
			(g_enemy3.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy3.m_cLocation.Y == g_nChar.m_cLocation.Y) ||
			(g_enemy4.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy4.m_cLocation.Y == g_sChar.m_cLocation.Y))
		{
			//Set boolean to false so the health will not reset.
			restarthealth = false;


			//Deduct one health.
			g_sChar.health -= 1;

			//Revert the level settings.
			spawn();
		}

		if (g_sChar.health < 1)
		{
			level = fiveb;
			load = defeated;
			renderGame();
			rendercharacters();
		}
	}
}