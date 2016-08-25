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
#include "characters.h"
#include "renderResult.h"
#include "menu.h"
#include "spawn.h"
#include "ScoreBoard.h"

#include "Windows.h"
#include "MMSystem.h"

#include "renderLegend.h"

#include "SpeedUpPlatform.h"

using std::vector;
using namespace std;

double g_dElapsedTime;
double  g_dDeltaTime;
double g_dCountTime;
double g_ElapsedGameTime;
bool    g_abKeyPressed[K_COUNT];
bool g_ResultIsDisplayed = false;

RELEASE
release_enemy,
release_enemy1,
release_enemy2,
release_enemy3,
release_enemy4,
release_enemy5,
release_enemy6,
release_enemy7,
release_enemy8;


// Game specific variables here
SGameChar   g_sChar;
SGameChar	g_nChar;
SGameChar	g_enemy;
SGameChar	g_enemy2;

objects 
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
g_box1;

SGameChar	g_door1;
SGameChar	g_lever1;
SGameChar	g_box1;
SGameChar	release_enemy;
SGameChar	release_enemy1;
SGameChar	release_enemy2;
SGameChar	release_enemy3;
SGameChar	release_enemy4;
SGameChar	release_enemy5;
SGameChar	release_enemy6;
SGameChar	release_enemy7;
SGameChar	release_enemy8;

//Speed up
SGameChar   g_platform;


SGameChar	g_menu;
SGameChar   g_result;
SGameChar   g_powerup;
SGameChar   g_timeboost;
EGAMESTATES g_eGameState = S_SPLASHSCREEN;
LEVELS		load = levelzeroa;
RESTART		level = one;
direction	check = upd;

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
	//Run the spawn function to printing characters for different levels.
	spawn();
	// Set precision for floating point output
	g_dElapsedTime = 0.0;
	g_dBounceTime = 0.0;
	ai_BounceTime = 0.0;
	g_dCountTime = 0.5;
	g_dCountTime = 60;


	// sets the initial state for the game
	g_eGameState = S_SPLASHSCREEN;

	//Run the spawn function to printing characters for different levels.
	//spawn();

	// sets the width, height and the font name to use in the console

	g_Console.setConsoleFont(0, 16, L"Arial");
	// Added by Daniel \/
	PlaySound(TEXT("Yiruma_RiverFlowsinMe(MP3).wav"), NULL, SND_SYNC |SND_LOOP | SND_ASYNC);
	
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
	g_abKeyPressed[K_NUM1] = isKeyPressed(VK_NUMPAD1);
	g_abKeyPressed[K_NUM2] = isKeyPressed(VK_NUMPAD2);
	

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
	g_abKeyPressed[K_9] = isKeyPressed(VK_9);
	g_abKeyPressed[K_0] = isKeyPressed(VK_0);
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
	case S_RESULT: 
		renderResult(&g_ResultIsDisplayed, &g_ElapsedGameTime);
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
	switch (load)
	{
	case levelzeroa:
		sprint();
		movelevel0();
		break;
	case levelzerob:
		sprint();
		movelevel0();
		break;
	case levelone:
		sprint();
		movelevel1();
		break;

	case leveltwo:
		sprint();
		movelevel2();
		SpeedUpPlatform();
		break;
	}
}
		
void processUserInput()
{
	bool bSomethingHappened = false;
	// quits the game if player hits the escape key
	if (g_abKeyPressed[K_ESCAPE])
	{
		g_bQuitGame = true;
	}

	if (g_abKeyPressed[K_9])
	{
		load = levelzeroa;
		clearScreen();
		spawn();
		renderGame();
	}

	if (g_abKeyPressed[K_0])
	{
		load = levelzerob;
		clearScreen();
		spawn();
		renderGame();
	}

	if (g_abKeyPressed[K_1])
	{
		load = levelone;
		clearScreen();
		spawn();
		renderGame();
	}
	if (g_abKeyPressed[K_2])
	{
		load = leveltwo;
		clearScreen();
		spawn();
		renderGame();
	}

	if (g_abKeyPressed[K_R])
	{
		bool bSomethingHappened = false;
		if (g_dBounceTime > g_dElapsedTime)
		{
			return;
		}

		restarthealth = false;
		g_sChar.health -= 1;
		bSomethingHappened = true;


		if (bSomethingHappened)
		{
			// set the bounce time to some time in the future to prevent accidental triggers
			g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
		}

		switch (load)
		{

		case levelzeroa:
			level = zeroa;

			if (g_sChar.health > 0)
			{
				spawn();
			}
			else
			{
				load = defeated;
			}
			break;

		case levelzerob:
			level = zerob;

			if (g_sChar.health > 0)
			{
				spawn();
			}
			else
			{
				load = defeated;
			}
			break;

		case levelone:
			level = one;

			if (g_sChar.health > 0)
			{
				spawn();
			}
			else
			{
				load = defeated;
			}
			break;

		case leveltwo:
			level = two;

			if (g_sChar.health > 0)
			{
				spawn();
			}
			else
			{
				load = defeated;
			}
			break;
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
}

void renderGame()
{
	renderMap();        // renders the map to the buffer first
	renderFramerate();  // renders debug information, frame rate, elapsed time, etc
	renderhealth(&g_Console, g_sChar.health); // draw health to the screen
	renderLegend(); //render legends regarding powerups
	//renderCharacter();  // renders the character into the buffer
	//renderCharacter();  // renders the character into the buffer


	switch (load)
	{
	case mainscreen: menu();
		break;
	case defeated: gameover();
		break;
	case levelzeroa: tutoriala();
		break;
	case levelzerob: tutorialb();
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

//void renderCharacter()
//{
//
//}

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
		//Deduct health when time over.
		g_sChar.health--;
		restarthealth = false;

		ss.str("");
		ss << "Time Over";
		c.X = g_Console.getConsoleSize().X - 10;
		c.Y = g_Console.getConsoleSize().Y - 23;
		g_Console.writeToBuffer(c, ss.str(), 0X4D);

		switch (load)
		{
		case levelzeroa:
			if (g_sChar.health < 1)
			{
				g_eGameState = S_RESULT;
			}
			else
			{
				g_dCountTime = 60;
				spawn();
			}
			break;

		case levelzerob:
			if (g_sChar.health < 1)
			{
				g_eGameState = S_RESULT;
			}
			else
			{
				g_dCountTime = 60;
				spawn();
			}
			break;


		g_eGameState = S_RESULT;


		case levelone:
			if (g_sChar.health < 1)
			{
				g_eGameState = S_RESULT;
			}
			else
			{
				g_dCountTime = 60;
				spawn();
			}
			break;
		}

	}
}

void renderToScreen()
{
	// Writes the buffer to the console, hence you will see what you have written
	g_Console.flushBufferToConsole();
}