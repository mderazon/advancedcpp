#include "stdafx.h"
#include "extendedCalendar.h"



extendedCalendar::extendedCalendar()
{
}


extendedCalendar::~extendedCalendar()
{
}

const std::string extendedCalendar::printCalendar()
{
	std::ostringstream s;

	s << "Extended Calendar" << std::endl;
	s << "-----------------" << std::endl;
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

			s << "*	Meeting starts at " << startBuffer << " and ends at " << endBuffer << ". Participants: ";
			std::list<participant> participants = ((extendedMeeting *)*it)->getParticipants();
			std::list<participant>::const_iterator it2;
			for(it2 = participants.begin(); it2 != participants.end(); it2++)
			{
				s << it2->getName() << " ";
			}
			s << std::endl;
		}
	}
	return s.str();
}