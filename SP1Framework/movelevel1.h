#include "game.h"
#include "main.h"

//Linking Console.
extern Console g_Console;

//Linking Map.
extern char map[25][80];

//Linking game states.
extern LEVELS load;

//Linking characters
extern SGameChar g_sChar;
extern SGameChar g_nChar;
extern SGameChar g_door1;
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

//Linking Timer.
extern double  g_dBounceTime;
extern double g_dElapsedTime;
extern double g_dBounceTimeBoost;

extern bool g_abKeyPressed[K_COUNT];