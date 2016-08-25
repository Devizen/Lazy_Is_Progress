#include "main.h"
#include "game.h"

//Linking Console.
extern Console g_Console;

//Linking game states.
extern EGAMESTATES g_eGameState;
extern LEVELS load;

//Linking characters and enemies.
extern SGameChar g_sChar;
extern SGameChar g_nChar;
extern SGameChar g_enemy;
extern SGameChar g_enemy2;
extern SGameChar g_door1;
extern SGameChar g_lever1;
extern SGameChar g_box1;
extern SGameChar release_enemy;
extern SGameChar release_enemy1;
extern SGameChar release_enemy2;
extern SGameChar release_enemy3;
extern SGameChar release_enemy4;
extern SGameChar release_enemy5;
extern SGameChar release_enemy6;
extern SGameChar release_enemy7;
extern SGameChar release_enemy8;
extern SGameChar g_menu;
extern SGameChar g_result;
extern SGameChar g_powerup;
extern SGameChar g_timeboost;
extern SGameChar g_platform;

//Linking variables
extern double g_dCountTime;

//Definition for function.
void spawn();