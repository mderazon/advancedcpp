#pragma once
#ifndef EXTENDED_CALENDAR
#define EXTENDED_CALENDAR

#include "calendar.h"

class extendedCalendar : public calendar
{
public:
	extendedCalendar(void);
	~extendedCalendar(void);
	
	void addMeeting(day d, extendedMeeting *m);
	void removeMeeting (day d,extendedMeeting *m);
	void changeMeeting (day old_d, extendedMeeting *old_m, day new_d, extendedMeeting *new_m);
};

#endif