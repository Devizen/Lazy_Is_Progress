#include "main.h"
#include "gameover.h"
#include "Framework\timer.h"
#include "level2.h"
#include "characters.h"
#include "health.h"

//Linking Timer.
extern double  g_dBounceTime;
extern double g_dElapsedTime;
extern double  g_dDeltaTime;
extern double g_dCountTime;
extern bool g_abKeyPressed[K_COUNT];

//Linking Console.
extern Console g_Console;
extern LEVELS load;

//Linking Map.
extern const unsigned int x;
extern const unsigned int y;
extern char map[25][80];

//Linking characters and enemies.
extern SGameChar g_sChar;
extern SGameChar g_nChar;
extern SGameChar g_enemy;
extern SGameChar g_enemy2;

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

//Heal and Time Boost.
extern SGameChar g_powerup;
extern SGameChar g_timeboost;

//Speed up platform
extern SGameChar g_platform;


//Linking game states.
extern EGAMESTATES g_eGameState;
extern LEVELS load;
extern RESTART level;

//Linking variables.
extern bool restarthealth;
<<<<<<< HEAD
extern bool door1;
=======
extern bool story;
>>>>>>> ebc6a07268ff44191cd7e41b6393121112daf489

//Definition for function.
void level1(); // level 1.