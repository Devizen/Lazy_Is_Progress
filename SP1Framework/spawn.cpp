#include "spawn.h"
bool restarthealth = true;

//Done by Eugene.
void spawn()
{
	//Print Arrow for Menu Screen.
	switch (g_eGameState)
	{
	case S_SPLASHSCREEN:
		//Menu Arrow
		g_menu.m_cLocation.X = 30;
		g_menu.m_cLocation.Y = 8;
	}

	//For printing different characters based on levels.
	switch (load)
	{
	case levelzeroa:
		//First Character
		g_sChar.m_cLocation.X = 20;
		g_sChar.m_cLocation.Y = 23;

		//Second Character
		g_nChar.m_cLocation.X = 40;
		g_nChar.m_cLocation.Y = 23;

		//Enemy
		g_enemy.m_cLocation.X = 29;
		g_enemy.m_cLocation.Y = 23;

		g_enemy2.m_cLocation.X = 31;
		g_enemy2.m_cLocation.Y = 23;

		//Set the initial health of the player
		if (restarthealth == true)
		{
			g_sChar.health = 3;
		}

		//Set the initial time limit
		g_dCountTime = 60;

		break;

	case levelzerob:
		//First Character
		g_sChar.m_cLocation.X = 29;
		g_sChar.m_cLocation.Y = 23;

		//Second Character
		g_nChar.m_cLocation.X = 31;
		g_nChar.m_cLocation.Y = 23;

		//g_sChar.m_cLocation.X = 14;
		//g_sChar.m_cLocation.Y = 2;

		////Second Character
		//g_nChar.m_cLocation.X = 34;
		//g_nChar.m_cLocation.Y = 2;

		//Doors
		g_door1.m_cLocation.X = 56;
		g_door1.m_cLocation.Y = 19;
		g_door2.m_cLocation.X = 15;
		g_door2.m_cLocation.Y = 16;
		g_door3.m_cLocation.X = 52;
		g_door3.m_cLocation.Y = 12;
		g_door4.m_cLocation.X = 15;
		g_door4.m_cLocation.Y = 8;

		//Close Doors
		closedoor1.m_cLocation.X = 29;
		closedoor1.m_cLocation.Y = 24;
		closedoor2.m_cLocation.X = 31;
		closedoor2.m_cLocation.Y = 24;

		//Levers
		g_lever1.m_cLocation.X = 5;
		g_lever1.m_cLocation.Y = 18;
		g_lever2.m_cLocation.X = 59;
		g_lever2.m_cLocation.Y = 13;
		g_lever3.m_cLocation.X = 25;
		g_lever3.m_cLocation.Y = 15;
		g_lever4.m_cLocation.X = 38;
		g_lever4.m_cLocation.Y = 10;

		//Boxes
		boxone.m_cLocation.X = 25;
		boxone.m_cLocation.Y = 18;
		boxtwo.m_cLocation.X = 35;
		boxtwo.m_cLocation.Y = 17;
		boxthree.m_cLocation.X = 5;
		boxthree.m_cLocation.Y = 10;
		boxfour.m_cLocation.X = 54;
		boxfour.m_cLocation.Y = 2;

		//Enemy
		g_enemy.m_cLocation.X = 33;
		g_enemy.m_cLocation.Y = 8;

		//g_enemy2.m_cLocation.X = 38;
		//g_enemy2.m_cLocation.Y = 2;

		//Set the initial health of the player
		if (restarthealth == true)
		{
			g_sChar.health = 3;
		}

		//Set the initial time limit
		g_dCountTime = 60;

		break;

	case levelone: 
		//First Character
		g_sChar.m_cLocation.X = 4;
		g_sChar.m_cLocation.Y = 8;

		//Second Character
		g_nChar.m_cLocation.X = 39;
		g_nChar.m_cLocation.Y = 19;

		//Enemy
		g_enemy.m_cLocation.X = 11;
		g_enemy.m_cLocation.Y = 1;

		g_enemy2.m_cLocation.X = 49;
		g_enemy2.m_cLocation.Y = 1;

		//Door
		g_door1.m_cLocation.X = 8;
		g_door1.m_cLocation.Y = 10;

		//Lever
		g_lever1.m_cLocation.X = 53;
		g_lever1.m_cLocation.Y = 8;

		//Teleporter
		g_lever2.m_cLocation.X = 8;
		g_lever2.m_cLocation.Y = 22;

		//Box
		g_box1.m_cLocation.X = 54;
		g_box1.m_cLocation.Y = 21;

		//PowerUp
		g_powerup.m_cLocation.X = 40;
		g_powerup.m_cLocation.Y = 20;

		//TimerUp;
		g_timeboost.m_cLocation.X = 55;
		g_timeboost.m_cLocation.Y = 15;

		//Release A.I
		release_enemy.m_cLocation.X = 53;
		release_enemy.m_cLocation.Y = 6;

		release_enemy1.m_cLocation.X = 52;
		release_enemy1.m_cLocation.Y = 6;

		release_enemy2.m_cLocation.X = 51;
		release_enemy2.m_cLocation.Y = 6;

		release_enemy3.m_cLocation.X = 50;
		release_enemy3.m_cLocation.Y = 6;

		release_enemy4.m_cLocation.X = 49;
		release_enemy4.m_cLocation.Y = 6;

		release_enemy5.m_cLocation.X = 48;
		release_enemy5.m_cLocation.Y = 6;

		release_enemy6.m_cLocation.X = 47;
		release_enemy6.m_cLocation.Y = 6;

		release_enemy7.m_cLocation.X = 46;
		release_enemy7.m_cLocation.Y = 6;

		release_enemy8.m_cLocation.X = 45;
		release_enemy8.m_cLocation.Y = 6;

		//Set the initial health of the player
		if (restarthealth == true)
		{
			g_sChar.health = 3;
		}

		//Set the initial time limit
		g_dCountTime = 60;

		break;

	case leveltwo:
		//First Character
		g_sChar.m_cLocation.X = 4;
		g_sChar.m_cLocation.Y = 19;

		//Second Character
		g_nChar.m_cLocation.X = 39;
		g_nChar.m_cLocation.Y = 19;

		//Enemy
		g_enemy.m_cLocation.X = 11;
		g_enemy.m_cLocation.Y = 1;

		g_enemy2.m_cLocation.X = 49;
		g_enemy2.m_cLocation.Y = 1;

		//Door
		g_door1.m_cLocation.X = 8;
		g_door1.m_cLocation.Y = 10;

		//Lever
		g_lever1.m_cLocation.X = 53;
		g_lever1.m_cLocation.Y = 8;
		
		//Box
		g_box1.m_cLocation.X = 54;
		g_box1.m_cLocation.Y = 21;

		//Release A.I
		release_enemy.m_cLocation.X = 52;
		release_enemy.m_cLocation.Y = 6;

		//PlatForm
		g_platform.m_cLocation.X = 4;
		g_platform.m_cLocation.Y = 21;

		//Set the initial health of the player
		if (restarthealth == true)
		{
			g_sChar.health = 3;
		}

		//Set the initial time limit
		g_dCountTime = 60;
		break;
	}
}

bool boxreturn(struct objects input)
{
	if (map[input.m_cLocation.Y][input.m_cLocation.X] == (char)219)
	{
		return true;
	}
	else
	{
		return false;
	}
}