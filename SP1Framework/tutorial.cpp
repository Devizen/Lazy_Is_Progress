#include "tutorial.h"


void tutoriala()
{
	string line = " ";
	COORD c;

	if (splash == true)
	{
		string name = "Text/Screen/level0_0.txt";
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

		if (g_dCountTime < 59)
		{
			splash = false;
			renderGame();
		}
	}

	if (splash == false)
	{
		string name = "Text/Level/level0_0.txt";
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

		rendercharacters();
		motiondetect();

		if (map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X] == map[13][11])
		{
			g_Console.writeToBuffer(release_enemy.m_cLocation, (char)0);
			g_Console.writeToBuffer(release_enemy1.m_cLocation, (char)0);
			door1 = true;
		}
		else
		{
			door1 = false;
		}

		if ((g_enemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y) ||
			(g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y))
		{
			//Deduct one health.
			g_sChar.health--;

			//g_sChar.health -= 1;
			if (g_sChar.health > 0)
			{	//Prevent health from reverting back to 3.
				restarthealth = false;

				//Display Splash Screen.
				splash = true;

				//Revert level settings to default.
				spawn();
			}
			if (g_sChar.health < 1)
			{	//Boolean for restarting the level after gameover.
				level = zeroa;
				load = defeated;
				renderGame();
			}
		}

		if (g_sChar.m_cLocation.X == 29 &&
			g_sChar.m_cLocation.Y == 0 &&
			g_nChar.m_cLocation.X == 31 &&
			g_nChar.m_cLocation.Y == 0)
		{
			clearScreen();
			restarthealth = true;
			splash = true;
			load = levelzerob;
			spawn();
		}
	}
}

void tutorialb()
{
	WORD charColor = 0x0C;
	WORD charColor2 = 0x0A;
	WORD yellow = 0xFFE0;

	//string line = " ";
	//string name = "Text/Level/level0_1.txt";
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

	string line = " ";
	COORD c;

	if (splash == true)
	{
		string name = "Text/Screen/level0_1.txt";
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

		if (g_dCountTime < 59)
		{
			splash = false;
			renderGame();
		}
	}

	if (splash == false)
	{
		string name = "Text/Level/level0_1.txt";
		loadlevel(name);

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

		COORD d;
		d.X = 63;
		d.Y = 15;
		g_Console.writeToBuffer(d, "Push the");
		d.Y = 16;
		g_Console.writeToBuffer(d, "Red Box");
		d.Y = 17;
		g_Console.writeToBuffer(d, "into the");
		d.Y = 18;
		g_Console.writeToBuffer(d, "Yellow Platform.");

		rendercharacters();
		//motiondetect();
		patrolzerob();
		// epatrolenemy();



		if (boxreturn(boxone) == true)
		{
			boxone.m_cLocation.X = 25;
			boxone.m_cLocation.Y = 18;
		}

		if (boxreturn(boxtwo) == true)
		{
			boxtwo.m_cLocation.X = 35;
			boxtwo.m_cLocation.Y = 17;
		}

		if (boxreturn(boxthree) == true)
		{
			boxthree.m_cLocation.X = 5;
			boxthree.m_cLocation.Y = 10;
		}

		if (boxreturn(boxfour) == true)
		{
			boxfour.m_cLocation.X = 54;
			boxfour.m_cLocation.Y = 2;
		}


		//Unlock Door 1
		if (map[boxone.m_cLocation.Y][boxone.m_cLocation.X] == map[g_lever1.m_cLocation.Y][g_lever1.m_cLocation.X])
		{
			g_Console.writeToBuffer(boxone.m_cLocation, (char)219, charColor2);
			g_Console.writeToBuffer(g_door1.m_cLocation, (char)219, charColor2);

			door1 = true;
		}
		else
		{
			door1 = false;
		}

		//Unlock Door 2
		if (map[boxtwo.m_cLocation.Y][boxtwo.m_cLocation.X] == map[g_lever2.m_cLocation.Y][g_lever2.m_cLocation.X])
		{
			g_Console.writeToBuffer(boxtwo.m_cLocation, (char)219, charColor2);
			g_Console.writeToBuffer(g_door2.m_cLocation, (char)219, charColor2);

			door2 = true;
		}
		else
		{
			door2 = false;
		}

		//Unlock Door 3
		if (map[boxthree.m_cLocation.Y][boxthree.m_cLocation.X] == map[g_lever3.m_cLocation.Y][g_lever3.m_cLocation.X])
		{
			g_Console.writeToBuffer(boxthree.m_cLocation, (char)219, charColor2);
			g_Console.writeToBuffer(g_door3.m_cLocation, (char)219, charColor2);

			door3 = true;
		}
		else
		{
			door3 = false;
		}

		//Unlock Door 4
		if (map[boxfour.m_cLocation.Y][boxfour.m_cLocation.X] == map[g_lever4.m_cLocation.Y][g_lever4.m_cLocation.X])
		{
			g_Console.writeToBuffer(boxfour.m_cLocation, (char)219, charColor2);
			g_Console.writeToBuffer(g_door4.m_cLocation, (char)219, charColor2);

			door4 = true;
		}
		else
		{
			door4 = false;
		}

		//if (map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X] == map[g_enemy.m_cLocation.Y][g_enemy.m_cLocation.X])
		//{
		//	restarthealth = false;
		//	g_sChar.health -= 1;

		//	spawn();

		//}

		//if ((g_enemy.m_cLocation.X == g_sChar.m_cLocation.X) && (g_enemy.m_cLocation.Y == g_sChar.m_cLocation.Y)/* ||
		//	(g_enemy2.m_cLocation.X == g_nChar.m_cLocation.X) && (g_enemy2.m_cLocation.Y == g_nChar.m_cLocation.Y)*/)
		//{
		//	restarthealth = false;
		//	g_sChar.health -= 1;

		//	spawn();

		//	////First Character
		//	//g_sChar.m_cLocation.X = 20;
		//	//g_sChar.m_cLocation.Y = 23;

		//	////Second Character
		//	//g_nChar.m_cLocation.X = 40;
		//	//g_nChar.m_cLocation.Y = 23;

		//	////Enemy
		//	//g_enemy.m_cLocation.X = 22;
		//	//g_enemy.m_cLocation.Y = 23;

		//	//g_enemy2.m_cLocation.X = 38;
		//	//g_enemy2.m_cLocation.Y = 23;

		///*	g_dCountTime = 60;*/
		//}

		if (g_sChar.m_cLocation.X == 15 &&
			g_sChar.m_cLocation.Y == 2 &&
			g_nChar.m_cLocation.X == 33 &&
			g_nChar.m_cLocation.Y == 2)
		{
			clearScreen();
			restarthealth = true;
			splash = true;
			load = levelone;
			spawn();
		}

		if (g_sChar.health < 1)
		{
			level = zeroa;
			load = defeated;
			renderGame();
		}
	}
}