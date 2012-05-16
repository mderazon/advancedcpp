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
	{
		if ((m->getStartHour() > (*it)->getStartHour() && (m->getStartHour() < (*it)->getEndHour())) ||
			(m->getEndHour() > (*it)->getStartHour() && (m->getEndHour() < (*it)->getEndHour())))
		{
			// found time conflict, check for the type of meeting
			if (m->GetType() == meeting::E_EXTENDED_MEETING) 
			{
				// extended meeting, check for participants
				extendedMeeting * em = (extendedMeeting *) m;
				std::list<participant> participants = em->getParticipants();
				std::list<participant>::iterator part_it;
				for (part_it = participants.begin(); part_it != participants.end(); part_it++)
				{
					extendedMeeting *em2 = (extendedMeeting *) *it;
					std::list<participant> participants2 = em2->getParticipants();
					std::list<participant>::iterator part_it2;
					for (part_it2 = participants2.begin(); part_it2 != participants2.end(); part_it2++)
					{
						if (part_it2->getId() == part_it->getId())
						{
							throw CONFLICTING_MEETINGS_ERROR;
						}
					}
				}
			} 
			else
			{
				// regular meeting - time conflict
				throw CONFLICTING_MEETINGS_ERROR;
			}			
		}
	}
	// you made it through ! go on and insert the meeting
	meetings.insert(it,m);
}

void day::removeMeeting( meeting* m )
{
	meetings.remove(m);
}

meeting& day::findMeeting( std::time_t StartHour ) const
{
	std::list<meeting*>::const_iterator it;
	for(it = meetings.begin(); it != meetings.end(); it++)
	{
		if ((*it)->getStartHour() == StartHour)
		{
			return **it;
		}
	}
	throw MEETING_NOT_FOUND_ERROR;
}

const std::list<meeting*> day::getMeetings() const
{
	return this->meetings;
}

void day::cleanDay()
{
	meetings.clear();
}
