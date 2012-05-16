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
			throw no_such_day_error;
	return week[dayId-1];
}

void calendar::addMeeting( int dayId, meeting *m)
{
	if (dayId < 1 || dayId >7)
		throw no_such_day_error;
	week[dayId-1].addMeeting(m);
}

void calendar::removeMeeting(int dayId, meeting *m)
{
	if (dayId < 1 || dayId >7)
		throw no_such_day_error;
	week[dayId-1].removeMeeting(m);
}

void calendar::changeMeeting( int old_dayID, meeting *old_m, int new_dayId,meeting *new_m )
{
	//TODO implement with try/catch
}
