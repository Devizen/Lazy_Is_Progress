#ifndef _GAME_H
#define _GAME_H
#include <string>
#include "keyboard.h"

using namespace std;

#include "Framework\timer.h"

//Linking boolean states.
extern bool door1;
extern bool door2;
extern bool door3;
extern bool door4;

extern CStopWatch g_swTimer;
extern bool g_bQuitGame;

// Enumeration to store the control keys that your game will have
enum EKEYS
{
	K_LSHIFT,
	K_RSHIFT,
    K_UP,
    K_DOWN,
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
    K_SPACE,
	K_RETURN,
	K_BACK,
	K_NUM1,
	K_NUM2,

	K_w,
	K_a,
	K_s,
	K_d,
	K_W,
	K_A,
	K_S,
	K_D,
	K_R,

	K_1,
	K_2,
	K_3,
	K_4,
	K_6,
	K_9,
	K_0,

	K_COUNT //Must be at most bottom
};

// Enumeration for the different screen states
enum EGAMESTATES
{
	S_SPLASHSCREEN,
	S_MENU,
	S_GAME,
	S_INSTRUCTIONS,
	S_SCOREBOARD,
	S_LEVEL1,
	S_RESULT, //This and COUNT must be at bottom
    S_COUNT
};

enum LEVELS
{
	mainscreen,
	defeated,
	levelzeroa,
	levelzerob,
	levelone, //Loading Level 1.
	leveltwo,
	levelthree,
	levelfour,
	scoreboard1,
	scoreboard2

};

enum RESTART
{
	zeroa,
	zerob,
	one,
	two,
	three,
    four
};


//Structure for testing different directions.
enum direction
{
	upd,
	leftd,
	downd,
	rightd
};

// struct for the game character
struct SGameChar
{
    COORD m_cLocation;
    bool  m_bActive;
	int health;
};

//Struct for releasing enemy
struct RELEASE
{
	COORD m_cLocation;
};

// struct for the objects

struct objects 
{
	COORD m_cLocation;
};


void init        ( void );      // initialize your variables, allocate memory, etc
void getInput    ( void );      // get input from player
void update      ( double dt ); // update the game and the state of the game
void render      ( void );      // renders the current state of the game to the console
void shutdown    ( void );      // do clean up, free memory

void splashScreenWait();    // waits for time to pass in splash screen
void gameplay();            // gameplay logic
void moveCharacter();       // moves the character, collision detection, physics, etc
void processUserInput();    // checks if you should change states or do something else with the game, e.g. pause, exit
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void renderGame();          // renders the game stuff
void renderMap();           // renders the map to the buffer first
//void renderCharacter();     // renders the character into the buffer
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game
void renderResult();  //renders result screen
void renderScoreBoard(); // renders scoreboard

//Add-ons
//void menu();				// renders the menu screen.
void moveai();				// move ai.
void loadlevel(string name);// load levels.
void sprint();
void tutoriala();
void tutorialb();

//Movement for Characters
void movelevel0();
void movelevel1();
void movelevel2();
void movelevel4();

//Linking variables.
extern bool restarthealth;
extern bool powerup;
extern bool timeincrease;


#endif // _GAME_H