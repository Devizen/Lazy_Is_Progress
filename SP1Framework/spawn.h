#include "main.h"
#include "game.h"

//Linking Console.
extern Console g_Console;

//Linking Map.
extern const unsigned int x;
extern const unsigned int y;
extern char map[25][80];

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
extern SGameChar g_powerup;
extern SGameChar g_timeboost;
extern SGameChar g_platform;

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
g_door2,
g_door3,
g_door4,
closedoor1,
closedoor2,
g_lever1,
g_lever2,
g_lever3,
g_lever4,
g_box1;

//Linking variables
extern double g_dCountTime;

//Definition for function.
void spawn();
bool boxreturn(struct objects box);