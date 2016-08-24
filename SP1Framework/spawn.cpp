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

		//Box
		g_box1.m_cLocation.X = 54;
		g_box1.m_cLocation.Y = 21;

		//Release A.I
		release_enemy.m_cLocation.X = 44;
		release_enemy.m_cLocation.Y = 6;

		release_enemy1.m_cLocation.X = 45;
		release_enemy1.m_cLocation.Y = 6;

		release_enemy2.m_cLocation.X = 46;
		release_enemy2.m_cLocation.Y = 6;

		release_enemy3.m_cLocation.X = 47;
		release_enemy3.m_cLocation.Y = 6;

		release_enemy4.m_cLocation.X = 48;
		release_enemy4.m_cLocation.Y = 6;

		release_enemy5.m_cLocation.X = 49;
		release_enemy5.m_cLocation.Y = 6;

		release_enemy6.m_cLocation.X = 50;
		release_enemy6.m_cLocation.Y = 6;

		release_enemy7.m_cLocation.X = 51;
		release_enemy7.m_cLocation.Y = 6;

		release_enemy8.m_cLocation.X = 52;
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

		//Set the initial health of the player
		g_sChar.health = 3;

		//Set the initial time limit
		g_dCountTime = 60;
		break;
	}
}