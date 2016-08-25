#ifndef  _PLATFORM_H
#define  _PLATFORM_H

#include "Framework\console.h"
#include "game.h"
#include "main.h"

extern Console g_Console;
extern SGameChar g_sChar;
extern SGameChar g_nChar;
extern SGameChar g_platform;
extern double  g_dBounceTime;
extern double g_dElapsedTime;
extern double g_dBounceTimeBoost;


extern bool g_abKeyPressed[K_COUNT];

//Linking Map.
extern const unsigned int x;
extern const unsigned int y;
extern char map[25][80];


void SpeedUpPlatform();



#endif 



