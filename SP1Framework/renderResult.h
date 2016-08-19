#include "game.h"
#include "main.h"

//Linking Console.
extern Console g_Console;

//Linking game states.
extern EGAMESTATES g_eGameState;

//Linking Map.
extern const unsigned int x;
extern const unsigned int y;
extern char map[25][80];

//Definition for function.
void renderResult();