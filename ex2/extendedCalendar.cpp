#include "stdafx.h"
#include "extendedCalendar.h"


extendedCalendar::extendedCalendar()
{
}


extendedCalendar::~extendedCalendar()
{
}

void addMeeting(day d, extendedMeeting *m)
{
	d.addMeeting(m);
}
void removeMeeting (day d,extendedMeeting *m)
{
	d.removeMeeting(m);
}
void changeMeeting (day old_d, extendedMeeting *old_m, day new_d, extendedMeeting *new_m)
{
	//TODO implement with try/catch
}