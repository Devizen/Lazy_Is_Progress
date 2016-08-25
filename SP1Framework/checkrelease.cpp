#include "checkrelease.h"

bool releasestate(struct SGameChar character, struct RELEASE input)
{
	switch (check)
	{
	case upd:
		if (map[character.m_cLocation.Y - 1][character.m_cLocation.X] !=
			map[input.m_cLocation.Y][input.m_cLocation.X])
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case leftd:
		if (map[character.m_cLocation.Y][character.m_cLocation.X - 1] !=
			map[input.m_cLocation.Y][input.m_cLocation.X])
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case downd:
		if (map[character.m_cLocation.Y + 1][character.m_cLocation.X] !=
			map[input.m_cLocation.Y][input.m_cLocation.X])
		{
			return true;
		}
		else
		{
			return false;
		}
		break;

	case rightd:
		if (map[character.m_cLocation.Y][character.m_cLocation.X + 1] !=
			map[input.m_cLocation.Y][input.m_cLocation.X])
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	}
}