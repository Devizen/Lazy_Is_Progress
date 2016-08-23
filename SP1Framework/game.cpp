// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

//Add-ons
#include <fstream>
#include <string>
#include "health.h"
#include "level1.h"
#include "level2.h"
#include "ai.h"
#include "renderResult.h"
#include "menu.h"
#include "spawn.h"
#include "ScoreBoard.h"

using std::vector;
using namespace std;

double g_dElapsedTime;
double  g_dDeltaTime;
double g_dCountTime;
double g_ElapsedGameTime;
bool    g_abKeyPressed[K_COUNT];
bool g_ResultIsDisplayed = false;


// Game specific variables here
SGameChar   g_sChar;
SGameChar	g_nChar;
SGameChar	g_enemy;
SGameChar	g_enemy2;
SGameChar	g_door1;
SGameChar	g_lever1;
SGameChar	g_box1;
SGameChar	release_enemy;
SGameChar	g_menu;
SGameChar   g_result;
EGAMESTATES g_eGameState = S_SPLASHSCREEN;
LEVELS		load = levelone;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once
double ai_BounceTime;


double  g_dBounceTimeBoost = 0.0; // this is to prevent key bouncing, so we won't trigger keypresses more than once

// Console object
Console g_Console(80, 25, "SP1 Framework");

const unsigned int x = 80;
const unsigned int y = 25;

char map[25][80];


//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init(void)
{
	// Set precision for floating point output
	g_dElapsedTime = 0.0;
	g_dBounceTime = 0.0;
	ai_BounceTime = 0.0;
	g_dCountTime = 1000;

	// sets the initial state for the game
	g_eGameState = S_SPLASHSCREEN;

	//Run the spawn function to printing characters for different levels.
	spawn();

	// sets the width, height and the font name to use in the console
	g_Console.setConsoleFont(0, 20, L"Arial");

}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown(void)
{
	// Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Getting all the key press states
//            This function checks if any key had been pressed since the last time we checked
//            If a key is pressed, the value for that particular key will be true
//
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput(void)
{
	g_abKeyPressed[K_UP] = isKeyPressed(VK_UP);
	g_abKeyPressed[K_DOWN] = isKeyPressed(VK_DOWN);
	g_abKeyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
	g_abKeyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
	g_abKeyPressed[K_RETURN] = isKeyPressed(VK_RETURN);
	g_abKeyPressed[K_SPACE] = isKeyPressed(VK_SPACE);
	g_abKeyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
	g_abKeyPressed[K_BACK] = isKeyPressed(VK_BACK);
	g_abKeyPressed[K_LSHIFT] = isKeyPressed(VK_LSHIFT);
	g_abKeyPressed[K_RSHIFT] = isKeyPressed(VK_RSHIFT);

	//WASD
	g_abKeyPressed[K_W] = isKeyPressed(VK_W);
	g_abKeyPressed[K_A] = isKeyPressed(VK_A);
	g_abKeyPressed[K_S] = isKeyPressed(VK_S);
	g_abKeyPressed[K_D] = isKeyPressed(VK_D);

	//Restart
	g_abKeyPressed[K_R] = isKeyPressed(VK_R);

	//Levels
	g_abKeyPressed[K_1] = isKeyPressed(VK_1);
	g_abKeyPressed[K_2] = isKeyPressed(VK_2);
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
	// get the delta time

	g_dElapsedTime += dt;
	g_dDeltaTime = dt;

	switch (g_eGameState)
	{
	case S_SPLASHSCREEN: splashScreenWait(); // game logic for the splash screen
		break;
	case S_GAME: gameplay(); // gameplay logic when we are in the game
		g_dCountTime -= dt;
		g_ElapsedGameTime += dt;
		break;
	}
}
//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
	clearScreen();      // clears the current screen and draw from scratch 
	switch (g_eGameState)
	{
	case S_SPLASHSCREEN: renderSplashScreen();
		break;
	case S_MENU: menu();
		break;
	case S_GAME: renderGame();
		break;
	//case S_LEVEL1: level1();
	//	break;
	case S_RESULT: renderResult(&g_ResultIsDisplayed, &g_ElapsedGameTime);
		break;
	case S_SCOREBOARD:renderScoreBoard();
	}

	renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void splashScreenWait()    // waits for time to pass in splash screen
{
	if (g_dElapsedTime > 3.0) // wait for 3 seconds to switch to game mode, else do nothing
		//g_eGameState = S_GAME;
		g_eGameState = S_MENU;
}

void gameplay()            // gameplay logic
{
	processUserInput(); // checks if you should change states or do something else with the game, e.g. pause, exit
	moveCharacter();    // moves the character, collision detection, physics, etc
	// sound can be played here too.

}

void moveCharacter()
{
	bool bSomethingHappened = false;
	bool boost = false;
	if (g_dBounceTime > g_dElapsedTime)
	{
		return;
	}

	COORD c;
	c.X = 5;
	c.Y = 5;

	// Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
	if (g_abKeyPressed[K_RSHIFT] && g_abKeyPressed[K_W] &&
		map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
	{
		g_sChar.m_cLocation.Y--;
		boost = true;
	}
	if (g_abKeyPressed[K_RSHIFT] && g_abKeyPressed[K_A] &&
		map[g_sChar.m_cLocation.Y ][g_sChar.m_cLocation.X-1] != (char)219)
	{
		if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219 &&
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] !=
			map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X])
		{
			g_sChar.m_cLocation.X--;
			
			boost = true;
		}
	}
	if (g_abKeyPressed[K_RSHIFT] && g_abKeyPressed[K_S] &&
		map[g_sChar.m_cLocation.Y +1][g_sChar.m_cLocation.X] != (char)219)
	{
		g_sChar.m_cLocation.Y++;
		boost = true;
	}
	if (g_abKeyPressed[K_RSHIFT] && g_abKeyPressed[K_D] &&
		map[g_sChar.m_cLocation.Y ][g_sChar.m_cLocation.X +1] != (char)219)
	{
		if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219 &&
			map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] !=
			map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X])
		{
			g_sChar.m_cLocation.X++;
			bSomethingHappened = true;
		}
	}



	if (g_abKeyPressed[K_LSHIFT] && g_abKeyPressed[K_UP] &&
		map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] != (char)219)
	{
		if (g_nChar.m_cLocation.Y - 1 == g_box1.m_cLocation.Y &&
			g_nChar.m_cLocation.X == g_box1.m_cLocation.X)
		{
			g_nChar.m_cLocation.Y--;
			g_box1.m_cLocation.Y--;
			bSomethingHappened = true;
		}
		else
		{
			g_nChar.m_cLocation.Y--;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_LSHIFT] && g_abKeyPressed[K_LEFT] &&
		map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != (char)219)
	{
		if (g_nChar.m_cLocation.Y == g_box1.m_cLocation.Y &&
			g_nChar.m_cLocation.X - 1 == g_box1.m_cLocation.X)
		{
			g_nChar.m_cLocation.X--;
			g_box1.m_cLocation.X--;
			bSomethingHappened = true;
		}
		else
		{
			g_nChar.m_cLocation.X--;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_LSHIFT] && g_abKeyPressed[K_DOWN] &&
		map[g_nChar.m_cLocation.Y + 1][g_nChar.m_cLocation.X] != (char)219)
	{
		if (g_nChar.m_cLocation.Y + 1 == g_box1.m_cLocation.Y &&
			g_nChar.m_cLocation.X == g_box1.m_cLocation.X)
		{
			g_nChar.m_cLocation.Y++;
			g_box1.m_cLocation.Y++;
			bSomethingHappened = true;
		}
		else
		{
			g_nChar.m_cLocation.Y++;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_LSHIFT] && g_abKeyPressed[K_RIGHT] &&
		map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != (char)219)
	{
		if (g_nChar.m_cLocation.Y == g_box1.m_cLocation.Y &&
			g_nChar.m_cLocation.X + 1 == g_box1.m_cLocation.X)
		{
			g_nChar.m_cLocation.X++;
			g_box1.m_cLocation.X++;
			bSomethingHappened = true;
		}
		else
		{
			g_nChar.m_cLocation.X++;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_W])
	{
		if (g_sChar.m_cLocation.Y > 0 &&
			map[g_sChar.m_cLocation.Y - 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y--;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_A])
	{
		
		switch (load)
		{
		case levelone:
			if (door1 == true)
			{
				if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219)
				{
					g_sChar.m_cLocation.X--;
					bSomethingHappened = true;
					break;
				}
			}
			if (door1 == false)
			{
				if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] != (char)219 &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X - 1] !=
					map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X] && map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X])

				{
					g_sChar.m_cLocation.X--;
					bSomethingHappened = true;
					break;
				}
	
			}
			
		}
	}

	if (g_abKeyPressed[K_S])
	{
		if (g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1 &&
			map[g_sChar.m_cLocation.Y + 1][g_sChar.m_cLocation.X] != (char)219)
		{
			g_sChar.m_cLocation.Y++;
			bSomethingHappened = true;
		}
	}

	if (g_abKeyPressed[K_D])
	{
		switch (load)
		{
		case levelone:
			if (door1 == true)
			{
				if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219)
				{
					g_sChar.m_cLocation.X++;
					bSomethingHappened = true;
					break;
				}
			}
			if (door1 == false)
			{
				if (g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] != (char)219 &&
					map[g_sChar.m_cLocation.Y][g_sChar.m_cLocation.X + 1] !=
					map[g_door1.m_cLocation.Y][g_door1.m_cLocation.X])
				{
					g_sChar.m_cLocation.X++;
					bSomethingHappened = true;
					break;
				}
			}
		}
	}

	if (g_abKeyPressed[K_UP])
	{
		if (g_nChar.m_cLocation.Y > 0 &&
			map[g_nChar.m_cLocation.Y - 1][g_nChar.m_cLocation.X] != (char)219)
		{
			if (g_nChar.m_cLocation.Y - 1 == g_box1.m_cLocation.Y &&
				g_nChar.m_cLocation.X == g_box1.m_cLocation.X)
			{
				g_nChar.m_cLocation.Y--;
				g_box1.m_cLocation.Y--;
				bSomethingHappened = true;
			}
			else
			{
				g_nChar.m_cLocation.Y--;
				bSomethingHappened = true;
			}
		}
	}

	if (g_abKeyPressed[K_LEFT])
	{
		if (g_nChar.m_cLocation.X > 0 &&
			map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X - 1] != (char)219)
		{
			if (g_nChar.m_cLocation.Y == g_box1.m_cLocation.Y &&
				g_nChar.m_cLocation.X - 1 == g_box1.m_cLocation.X)
			{
				g_nChar.m_cLocation.X--;
				g_box1.m_cLocation.X--;
				bSomethingHappened = true;
			}
			else
			{
				g_nChar.m_cLocation.X--;
				bSomethingHappened = true;
			}
		}
	}

	if (g_abKeyPressed[K_DOWN])
	{
		if (g_nChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1 &&
			map[g_nChar.m_cLocation.Y + 1][g_nChar.m_cLocation.X] != (char)219)
		{
			if (g_nChar.m_cLocation.Y + 1 == g_box1.m_cLocation.Y &&
				g_nChar.m_cLocation.X == g_box1.m_cLocation.X)
			{
				g_nChar.m_cLocation.Y++;
				g_box1.m_cLocation.Y++;
				bSomethingHappened = true;
			}
			else
			{
				g_nChar.m_cLocation.Y++;
				bSomethingHappened = true;
			}
		}
	}

	if (g_abKeyPressed[K_RIGHT])
	{
		if (g_nChar.m_cLocation.X < g_Console.getConsoleSize().X - 1 &&
			map[g_nChar.m_cLocation.Y][g_nChar.m_cLocation.X + 1] != (char)219)
		{
			if (g_nChar.m_cLocation.Y == g_box1.m_cLocation.Y &&
				g_nChar.m_cLocation.X + 1 == g_box1.m_cLocation.X)
			{
				g_nChar.m_cLocation.X++;
				g_box1.m_cLocation.X++;
				bSomethingHappened = true;
			}
			else
			{
				g_nChar.m_cLocation.X++;
				bSomethingHappened = true;
			}
		}
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}

	if (boost)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTimeBoost = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}
		
void processUserInput()
{
	// quits the game if player hits the escape key
	if (g_abKeyPressed[K_ESCAPE])
	{
		g_bQuitGame = true;
	}

	if (g_abKeyPressed[K_1])
	{
		load = levelone;
		spawn();
		level1();
	}
	if (g_abKeyPressed[K_2])
	{
		load = leveltwo;
		spawn();
		renderGame();
	}

	//if (g_abKeyPressed[K_R])
	//{
	//	bool bSomethingHappened = false;
	//	if (g_dBounceTime > g_dElapsedTime)
	//	{
	//		return;
	//	}
	//	switch (load)
	//	{
	//	case levelone:
	//		if (g_sChar.health > 0)
	//		{
	//			g_sChar.health -= 1;
	//			g_dCountTime = 1000;

	//			//First Character
	//			g_sChar.m_cLocation.X = 4;
	//			g_sChar.m_cLocation.Y = 8;

	//			//Second Character
	//			g_nChar.m_cLocation.X = 39;
	//			g_nChar.m_cLocation.Y = 19;

	//			//Enemy
	//			g_enemy.m_cLocation.X = 11;
	//			g_enemy.m_cLocation.Y = 1;

	//			g_enemy2.m_cLocation.X = 49;
	//			g_enemy2.m_cLocation.Y = 1;

	//			//Door
	//			g_door1.m_cLocation.X = 8;
	//			g_door1.m_cLocation.Y = 10;

	//			//Lever
	//			g_lever1.m_cLocation.X = 53;
	//			g_lever1.m_cLocation.Y = 8;

	//			//Box
	//			g_box1.m_cLocation.X = 54;
	//			g_box1.m_cLocation.Y = 21;
	//			bSomethingHappened = true;
	//		}
	//		else
	//		{
	//			gameover(g_sChar);
	//		}

	//	}
	//	if (bSomethingHappened)
	//	{
	//		// set the bounce time to some time in the future to prevent accidental triggers
	//		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	//	}
	//}

}

void clearScreen()
{
	// Clears the buffer with this colour attribute
	g_Console.clearBuffer();
}

void renderSplashScreen()  // renders the splash screen
{
	string line;
	ifstream myfile("Text/splashScreen.txt");
	COORD c = g_Console.getConsoleSize();
	c.X = 9;
	c.Y = 1;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			g_Console.writeToBuffer(c, line);
			c.Y++;
		}
		myfile.close();
	}
	else
	{
		g_Console.writeToBuffer(c, "The file is not found");
	}

	//memset is clear

}

void renderGame()
{
	renderMap();        // renders the map to the buffer first
	renderFramerate();  // renders debug information, frame rate, elapsed time, etc
	renderhealth(&g_Console, g_sChar.health); // draw health to the screen
	renderCharacter();  // renders the character into the buffer

	switch (load)
	{
	case mainscreen: menu();
		break;
	case levelone: level1();
		break;
	case leveltwo: level2();
		break;
	//case levelthree: levelthree();
	//	break;
	}
}

void renderMap()
{
	COORD c = g_Console.getConsoleSize();
	c.X = 0;
	c.Y = 0;
	string line = " ";

	for (unsigned int i = 0; i < y; i++)
	{
		line = map[i];
		g_Console.writeToBuffer(c, line);
		c.Y++;
	}
}

void renderCharacter()
{
	// Draw the location of the character
	//WORD charColor = 0x0C;
	//WORD charColor2 = 0x0A;
	//if (g_sChar.m_bActive)
	//{
	//	charColor = 0x0A;
	//}
	//g_Console.writeToBuffer(g_sChar.m_cLocation, (char)3, charColor);

	//// Draw the location of the character
	//if (g_nChar.m_bActive)
	//{
	//	charColor = 0x0C;
	//}
	//g_Console.writeToBuffer(g_nChar.m_cLocation, (char)3, charColor2);

	////Enemy
	//g_Console.writeToBuffer(g_enemy.m_cLocation, (char)1, charColor2);
	//g_Console.writeToBuffer(g_enemy2.m_cLocation, (char)1, charColor2);

	////Door
	//g_Console.writeToBuffer(g_door1.m_cLocation,(char)219, charColor);

}

void renderFramerate()
{
	COORD c;
	// displays the framerate
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(1);
	ss << 1.0 / g_dDeltaTime << "fps";
	c.X = g_Console.getConsoleSize().X - 9;
	c.Y = 0;
	g_Console.writeToBuffer(c, ss.str());

	// displays the elapsed time
	if (g_dCountTime >= 0)
	{
		ss.str("");
		ss << g_dCountTime << "secs";
		c.X = g_Console.getConsoleSize().X - 10;
		c.Y = g_Console.getConsoleSize().Y - 23;
		g_Console.writeToBuffer(c, ss.str(), 0xE5);
	}
	else
	{
		ss.str("");
		ss << "Time Over";
		c.X = g_Console.getConsoleSize().X - 10;
		c.Y = g_Console.getConsoleSize().Y - 23;
		g_Console.writeToBuffer(c, ss.str(), 0X4D);


		g_eGameState = S_RESULT;
	}
}

void renderToScreen()
{
	// Writes the buffer to the console, hence you will see what you have written
	g_Console.flushBufferToConsole();
}