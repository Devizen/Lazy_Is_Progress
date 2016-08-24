#include "main.h"
#include "game.h"

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

//Linking objects.
extern bool door1;

//Linking variables.
extern int health;
extern bool bSomethingHappened;
extern double ai_BounceTime;

//Definition for function.
void motiondetect();
void rendercharacters();