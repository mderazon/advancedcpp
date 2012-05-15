#include "stdafx.h"
#include "calendar.h"

calendar::calendar() : week(7)
{
	for (int i = 0; i<7; i++)
	{
		week[i+1].setID(i+1);
	}
}


calendar::~calendar()
{	
	for (int i=0; i<7; i++)
	{
		delete &(week[i]);
	}		
}

day calendar::getDay( int dayID ) const
{
	if (dayID < 1 || dayID >7)
			throw no_such_day_error;
	return week[dayID-1];
}

void calendar::addMeeting( day d, meeting *m)
{
	d.addMeeting(m);
}

void calendar::removeMeeting(day d, meeting *m)
{
	d.removeMeeting(m);
}

void calendar::changeMeeting( day old_d, meeting *old_m, day new_d,meeting *new_m )
{
	//TODO implement with try/catch
}
