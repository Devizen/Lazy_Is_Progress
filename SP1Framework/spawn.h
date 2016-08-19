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
extern SGameChar g_menu;
extern SGameChar g_result;

//Definition for function.
void spawn();