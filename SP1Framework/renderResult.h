#include "game.h"
#include "main.h"
#include "gameover.h"

//Linking Console.
extern Console g_Console;

//Linking game states.
extern EGAMESTATES g_eGameState;

//Linking Map.
extern const unsigned int x;
extern const unsigned int y;
extern char map[25][80];

//Linking game states.
extern EGAMESTATES g_eGameState;
extern LEVELS load;

//Definition for function.
void renderResult(bool *g_ResultIsDisplayed, double *g_ElapsedGameTime);
