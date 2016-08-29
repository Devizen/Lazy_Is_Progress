#include "game.h"
#include "main.h"

//Music

//Linking Timer.
extern double  g_dBounceTime;
extern double g_dElapsedTime;
extern double  g_dDeltaTime;
extern double g_dCountTime;
extern bool g_abKeyPressed[K_COUNT];

//Linking Console.
extern Console g_Console;

//Linking game states.
extern EGAMESTATES g_eGameState;
extern LEVELS load;

//Linking menu buttons.
extern SGameChar g_menu;

//Linking Map.
extern const unsigned int x;
extern const unsigned int y;
extern char map[25][80];

//Linking variables.
extern SGameChar g_sChar;

//Definition for function.
void menu();
void instructions();