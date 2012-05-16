#pragma once

#ifndef EXTENDED_CALENDAR
#define EXTENDED_CALENDAR
#include "calendar.h"

class extendedCalendar : public calendar
{
public:
	extendedCalendar(void);
	~extendedCalendar(void);
	const std::string printCalendar();
};

#endif