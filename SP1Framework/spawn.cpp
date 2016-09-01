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
		g_menu.m_cLocation.X = 32;
		g_menu.m_cLocation.Y = 12;
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
		//Bool to reset tracking
		partb = false;
		partc = false;

		//First Character
		g_sChar.m_cLocation.X = 15;
		g_sChar.m_cLocation.Y = 19;

		//Second Character
		g_nChar.m_cLocation.X = 45;
		g_nChar.m_cLocation.Y = 19;

		//Enemy
		g_enemy.m_cLocation.X = 15;
		g_enemy.m_cLocation.Y = 10;

		g_enemy2.m_cLocation.X = 45;
		g_enemy2.m_cLocation.Y = 10;

		////Door
		//g_door1.m_cLocation.X = 8;
		//g_door1.m_cLocation.Y = 10;

		////Lever
		//g_lever1.m_cLocation.X = 53;
		//g_lever1.m_cLocation.Y = 8;
		//
		////Box
		//g_box1.m_cLocation.X = 54;
		//g_box1.m_cLocation.Y = 21;

		////Release A.I
		//release_enemy.m_cLocation.X = 52;
		//release_enemy.m_cLocation.Y = 6;

		////PlatForm
		//g_platform.m_cLocation.X = 4;
		//g_platform.m_cLocation.Y = 21;

		//Set the initial health of the player
		if (restarthealth == true)
		{
			g_sChar.health = 3;
		}

		//Set the initial time limit
		g_dCountTime = 60;
		break;

	case levelthree:
		//First Character
		g_sChar.m_cLocation.X = 39;
		g_sChar.m_cLocation.Y = 19;

		//Second Character
		g_nChar.m_cLocation.X = 17;
		g_nChar.m_cLocation.Y = 19;

		//Enemy
		g_enemy.m_cLocation.X = 17;
		g_enemy.m_cLocation.Y = 9;

		g_enemy2.m_cLocation.X = 15;
		g_enemy2.m_cLocation.Y = 9;

		//PowerUp
		g_powerup.m_cLocation.X = 40;
		g_powerup.m_cLocation.Y = 20;

		//Door
		g_door4.m_cLocation.X = 45;
		g_door4.m_cLocation.Y = 17;

		//Lever
		g_lever4.m_cLocation.X = 51;
		g_lever4.m_cLocation.Y = 23;

		//Box
		boxfour.m_cLocation.X = 52;
		boxfour.m_cLocation.Y = 23;




		//Release A.I
		release_enemy.m_cLocation.X = 16;
		release_enemy.m_cLocation.Y = 9;

		//PlatForm
		g_platform.m_cLocation.X = 7;
		g_platform.m_cLocation.Y = 21;

		//Set the initial health of the player
		if (restarthealth == true)
		{
			g_sChar.health = 3;
		}

		//Set the initial time limit
		g_dCountTime = 60;
		break;

	case levelfour:
		//First Character
		g_sChar.m_cLocation.X = 9;
		g_sChar.m_cLocation.Y = 22;

		//Second Character
		g_nChar.m_cLocation.X = 48;
		g_nChar.m_cLocation.Y = 22;

		//Enemy
		g_enemy.m_cLocation.X = 13;
		g_enemy.m_cLocation.Y = 11;

		g_enemy2.m_cLocation.X = 48;
		g_enemy2.m_cLocation.Y = 7;

		//Doors
		g_door1.m_cLocation.X = 52;
		g_door1.m_cLocation.Y = 7;
		g_door2.m_cLocation.X = 48;
		g_door2.m_cLocation.Y = 11;
		g_door3.m_cLocation.X = 44;
		g_door3.m_cLocation.Y = 8;
		g_door4.m_cLocation.X = 48;
		g_door4.m_cLocation.Y = 4;
		g_door5.m_cLocation.X = 23;
		g_door5.m_cLocation.Y = 22;

		//Levers
		g_lever1.m_cLocation.X = 32;
		g_lever1.m_cLocation.Y = 12;
		g_lever3.m_cLocation.X = 17;
		g_lever3.m_cLocation.Y = 12;

		//Boxes
		boxone.m_cLocation.X = 14;
		boxone.m_cLocation.Y = 8;
		boxtwo.m_cLocation.X = 41;
		boxtwo.m_cLocation.Y = 18;

		//Release A.I
		release_enemy.m_cLocation.X = 52;
		release_enemy.m_cLocation.Y = 6;

		//Teleporter
		g_lever2.m_cLocation.X = 3;
		g_lever2.m_cLocation.Y = 1;
		g_portal.m_cLocation.X = 48;
		g_portal.m_cLocation.Y = 8;

		//Set the initial health of the player
		if (restarthealth == true)
		{
			g_sChar.health = 3;
		}

		//Set the initial time limit
		g_dCountTime = 60;
		break;

	case levelfive:
		//First Character
		g_sChar.m_cLocation.X = 1;
		g_sChar.m_cLocation.Y = 23;

		//Second Character
		g_nChar.m_cLocation.X = 59;
		g_nChar.m_cLocation.Y = 23;

		////First Character
		//g_sChar.m_cLocation.X = 29;
		//g_sChar.m_cLocation.Y = 2;

		////Second Character
		//g_nChar.m_cLocation.X = 59;
		//g_nChar.m_cLocation.Y = 2;

		//Enemy
		g_enemy.m_cLocation.X = 38;
		g_enemy.m_cLocation.Y = 6;

		g_enemy2.m_cLocation.X = 46;
		g_enemy2.m_cLocation.Y = 5;

		g_enemy3.m_cLocation.X = 49;
		g_enemy3.m_cLocation.Y = 1;

		//Doors
		g_door1.m_cLocation.X = 32;
		g_door1.m_cLocation.Y = 23;

		g_door2.m_cLocation.X = 41;
		g_door2.m_cLocation.Y = 17;

		g_door3.m_cLocation.X = 58;
		g_door3.m_cLocation.Y = 21;

		g_door4.m_cLocation.X = 51;
		g_door4.m_cLocation.Y = 13;

		g_door5.m_cLocation.X = 36;
		g_door5.m_cLocation.Y = 13;

		//Levers
		g_lever1.m_cLocation.X = 10;
		g_lever1.m_cLocation.Y = 19;

		g_lever2.m_cLocation.X = 28;
		g_lever2.m_cLocation.Y = 23;

		g_lever3.m_cLocation.X = 22;
		g_lever3.m_cLocation.Y = 16;

		g_lever4.m_cLocation.X = 12;
		g_lever4.m_cLocation.Y = 9;

		g_lever5.m_cLocation.X = 17;
		g_lever5.m_cLocation.Y = 7;

		////Boxes
		//boxone.m_cLocation.X = 14;
		//boxone.m_cLocation.Y = 8;
		//boxtwo.m_cLocation.X = 41;
		//boxtwo.m_cLocation.Y = 18;

		////Release A.I
		//release_enemy.m_cLocation.X = 52;
		//release_enemy.m_cLocation.Y = 6;

		////Teleporter
		//g_lever2.m_cLocation.X = 3;
		//g_lever2.m_cLocation.Y = 1;
		//g_portal.m_cLocation.X = 48;
		//g_portal.m_cLocation.Y = 8;

		//Set the initial health of the player
		if (restarthealth == true)
		{
			g_sChar.health = 3;
		}

		//Set the initial time limit
		g_dCountTime = 60;
		break;

	case levelfiveb:
		//First Character
		g_sChar.m_cLocation.X = 14;
		g_sChar.m_cLocation.Y = 23;

		//Second Character
		g_nChar.m_cLocation.X = 46;
		g_nChar.m_cLocation.Y = 23;

		//Enemy
		g_enemy.m_cLocation.X = 11;
		g_enemy.m_cLocation.Y = 17;

		g_enemy2.m_cLocation.X = 43;
		g_enemy2.m_cLocation.Y = 17;

		g_enemy3.m_cLocation.X = 14;
		g_enemy3.m_cLocation.Y = 9;

		g_enemy4.m_cLocation.X = 46;
		g_enemy4.m_cLocation.Y = 9;

		////Doors
		//g_door1.m_cLocation.X = 32;
		//g_door1.m_cLocation.Y = 23;

		//g_door2.m_cLocation.X = 41;
		//g_door2.m_cLocation.Y = 17;

		//g_door3.m_cLocation.X = 58;
		//g_door3.m_cLocation.Y = 21;

		//g_door4.m_cLocation.X = 51;
		//g_door4.m_cLocation.Y = 13;

		//g_door5.m_cLocation.X = 36;
		//g_door5.m_cLocation.Y = 13;

		//Levers
		g_lever1.m_cLocation.X = 14;
		g_lever1.m_cLocation.Y = 17;

		g_lever2.m_cLocation.X = 46;
		g_lever2.m_cLocation.Y = 17;

		g_lever3.m_cLocation.X = 14;
		g_lever3.m_cLocation.Y = 8;

		g_lever4.m_cLocation.X = 46;
		g_lever4.m_cLocation.Y = 8;

		//g_lever5.m_cLocation.X = 17;
		//g_lever5.m_cLocation.Y = 7;

		////Boxes
		//boxone.m_cLocation.X = 14;
		//boxone.m_cLocation.Y = 8;
		//boxtwo.m_cLocation.X = 41;
		//boxtwo.m_cLocation.Y = 18;

		////Release A.I
		//release_enemy.m_cLocation.X = 52;
		//release_enemy.m_cLocation.Y = 6;

		////Teleporter
		//g_lever2.m_cLocation.X = 3;
		//g_lever2.m_cLocation.Y = 1;
		//g_portal.m_cLocation.X = 48;
		//g_portal.m_cLocation.Y = 8;

		//Set the initial health of the player
		if (restarthealth == true)
		{
			g_sChar.health = 3;
		}

		//Set the initial time limit
		g_dCountTime = 60;
		break;

	case creditscreen:
		//First Character
		g_sChar.m_cLocation.X = 3;
		g_sChar.m_cLocation.Y = 9;

		//Second Character
		g_nChar.m_cLocation.X = 3;
		g_nChar.m_cLocation.Y = 7;

		//Enemy
		g_enemy.m_cLocation.X = 3;
		g_enemy.m_cLocation.Y = 5;
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

bool boxreturndoor(struct objects box, struct objects door)
{
	if (map[box.m_cLocation.Y][box.m_cLocation.X] == map[door.m_cLocation.Y][door.m_cLocation.X])
	{
		return true;
	}
	else
	{
		return false;
	}
}