#include "stdafx.h"
#include "calendar.h"

calendar::calendar() : week(7)
{
	for (int i = 0; i<7; i++)
	{
		week[i].setID(i+1);
	}
}


calendar::~calendar()
{	
	for (int i=0; i<7; i++)
	{
		delete &(week[i]);
	}		
}

day calendar::getDay( int dayId ) const
{
	if (dayId < 1 || dayId >7)
			throw NO_SUCH_DAY_ERROR;
	return week[dayId-1];
}

void calendar::addMeeting( int dayId, meeting *m)
{
	if (dayId < 1 || dayId >7)
		throw NO_SUCH_DAY_ERROR;
	week[dayId-1].addMeeting(m);
}

void calendar::removeMeeting(int dayId, meeting *m)
{
	if (dayId < 1 || dayId >7)
		throw NO_SUCH_DAY_ERROR;
	week[dayId-1].removeMeeting(m);
}

void calendar::changeMeeting( int old_dayID, meeting *old_m, int new_dayId,meeting *new_m )
{
	//TODO implement with try/catch
}

const std::string calendar::printCalendar()
{
	//std::string str;
	std::ostringstream s;
	
	s << "Calendar" << std::endl;
	s << "--------" << std::endl;
	for (int i = 0; i<week.size(); i++)
	{
		day d = week[i];
		s << "Day " << i+1 << std::endl;
		std::list<meeting*> meetings = d.getMeetings();
		std::list<meeting*>::const_iterator it;
		for(it = meetings.begin(); it != meetings.end(); it++)
		{
			// convert the time_t to a string
			std::time_t startTime = (*it)->getStartHour();
			std::time_t endTime = (*it)->getEndHour();
			struct tm startTimeinfo;
			struct tm endTimeinfo;
			char startBuffer [10];
			char endBuffer [10];
			startTimeinfo = *(localtime ( &startTime ));
			endTimeinfo = *(localtime ( &endTime ));
			strftime (startBuffer,10,"%I:%M%p.",&startTimeinfo);
			strftime (endBuffer,10,"%I:%M%p.",&endTimeinfo);
			
			s << "*	Meeting starts at " << startBuffer << " and ends at " << endBuffer << std::endl;
		}
	}
	return s.str();
}
