#include "main.h"
#include "game.h"
#include "checkrelease.h"

//Linking console.
extern Console g_Console;

//Linking map.
extern const unsigned int x;
extern const unsigned int y;
extern char map[25][80];

//Linking characters and enemies.
extern SGameChar g_sChar;
extern SGameChar g_nChar;
extern SGameChar g_enemy;


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
g_box1,
g_portal;

//Linking objects.
extern bool door1;
extern bool door2;
extern bool door3;
extern bool door4;

extern bool door5;

extern bool partb;
extern bool partc;


//Linking variables.
extern int health;
extern bool bSomethingHappened;
extern double ai_BounceTime;
extern direction check;


//Definition for function.
void motiondetect();
void rendercharacters();
void patrolzerob();
void patrolfour();