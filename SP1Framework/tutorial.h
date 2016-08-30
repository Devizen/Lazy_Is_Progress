#include "main.h"
#include "gameover.h"
#include "Framework\timer.h"
#include "level1.h"
#include "characters.h"
#include "health.h"
#include "game.h"

//Linking Timer.
extern double  g_dBounceTime;
extern double g_dElapsedTime;
extern double  g_dDeltaTime;
extern double g_dCountTime;
extern bool g_abKeyPressed[K_COUNT];

//Linking Console.
extern Console g_Console;

//Linking Map.
extern const unsigned int x;
extern const unsigned int y;
extern char map[25][80];

//Linking characters and enemies.
extern SGameChar g_sChar;
extern SGameChar g_nChar;
extern SGameChar g_enemy;
extern SGameChar g_enemy2;

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
g_lever1,
g_lever2,
g_lever3,
g_lever4,
g_box1;

//Linking game states.
extern EGAMESTATES g_eGameState;
extern LEVELS load;
extern RESTART level;

//Linking variables.
extern bool restarthealth;
extern bool splash;

