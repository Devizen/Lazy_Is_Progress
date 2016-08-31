#ifndef _HEALTH_H
#define _HEALTH_H

#include "Framework\console.h"
#include "game.h"
#include "colours.h"

//Linking Console.
extern Console g_Console;

extern SGameChar g_sChar;

//Linking Timer.
extern double  g_dBounceTime;
extern double g_dElapsedTime;
extern double  g_dDeltaTime;
extern double g_dCountTime;

void renderhealth(Console * handle, int hp);


#endif