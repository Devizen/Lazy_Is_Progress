#include "game.h"
#include "main.h"
#include "checkrelease.h"

//Linking Console.
extern Console g_Console;

//Linking Map.
extern char map[25][80];

//Linking game states.
extern LEVELS load;

//Linking characters
extern SGameChar g_sChar;
extern SGameChar g_nChar;

extern RELEASE
release_enemy,
release_enemy1,
release_enemy2,
release_enemy3,
release_enemy4,
release_enemy5,
release_enemy6,
release_enemy7,
release_enemy8;

extern objects
boxone,
boxtwo,
boxthree,
boxfour,
boxfive,
g_door1,
g_lever1,
g_box1;

extern direction check;

//Linking Timer.
extern double  g_dBounceTime;
extern double g_dElapsedTime;
extern double g_dBounceTimeBoost;

extern bool g_abKeyPressed[K_COUNT];