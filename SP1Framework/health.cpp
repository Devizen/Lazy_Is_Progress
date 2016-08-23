#include "health.h"
#include <string>
using namespace std;

//Done by Yoong Soon.
void renderhealth(Console *handle, unsigned int hp)
{
	WORD healthColor = 0xA1;
	string s = "Health: " + to_string(hp);

	COORD c;
	c.X = handle->getConsoleSize().X - 12;
	c.Y = handle->getConsoleSize().Y -1 ;

	handle->writeToBuffer(c, s, healthColor);
}