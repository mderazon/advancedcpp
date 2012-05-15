#include "stdafx.h"
#include "day.h"


day::day() {}

day::day(int id) : id(id) {}

day::~day(void)
{
}

int day::getID() const
{
	return this->id;
}

void day::setID( int id )
{
	this->id = id;
}

void day::addMeeting( meeting* m )
{
	std::list<meeting*>::iterator it;
	for(it = meetings.begin(); it != meetings.end(); it++)
		if ((m->getStartHour() > (*it)->getStartHour() && (m->getStartHour() < (*it)->getEndHour())) ||
			(m->getEndHour() > (*it)->getStartHour() && (m->getEndHour() < (*it)->getEndHour())))
			throw conflicting_meetings_error;
	meetings.insert(it,m);
}

void day::removeMeeting( meeting* a )
{
	meetings.remove(a);
}

meeting& day::findMeeting( float StartHour ) const
{
	std::list<meeting*>::const_iterator it;
	for(it = meetings.begin(); it != meetings.end(); it++)
	{
		if ((*it)->getStartHour() == StartHour)
		{
			return **it;
		}
	}
	throw no_such_meeting_error;
}

//std::string day::printDay()
//{
//
//}

void day::cleanDay()
{
	meetings.clear();
}
